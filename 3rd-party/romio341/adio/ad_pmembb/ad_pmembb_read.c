/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_ReadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                             int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                             int *error_code)
{
    rpmbb_handler_t handler = (rpmbb_handler_t) fd->fs_ptr;
    MPI_Count datatype_size;
    DEBUG_PRINT(fd->filename);

    *error_code = MPI_SUCCESS;

    MPI_Type_size_x(datatype, &datatype_size);

    off_t absolute_offset = file_ptr_type == ADIO_INDIVIDUAL ? fd->fp_ind : offset;
    size_t data_size = datatype_size * count;
    size_t bytes_read = 0;
    ssize_t ret;

#ifndef NDEBUG
    FPRINTF(stdout, "[%d/%d]    reading (buf = %p, loc = %lld, sz = %lld)\n", myrank, nprocs, buf,
            (long long) absolute_offset, (long long) data_size);
#endif

    while (bytes_read < data_size) {
        ret = rpmbb_bb_pread(handler, (char *) buf + bytes_read, data_size - bytes_read,
                             absolute_offset + bytes_read);
        if (ret < 0) {
            *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
            fd->fp_sys_posn = -1;
            return;
        }
#ifndef NDEBUG
        FPRINTF(stdout, "[%d/%d]    read %ld bytes\n", myrank, nprocs, ret);
#endif

        if (ret == 0) {
            return;
        }

        bytes_read += ret;
    }

    fd->fp_sys_posn = absolute_offset + bytes_read;
    if (file_ptr_type == ADIO_INDIVIDUAL) {
        fd->fp_ind += bytes_read;
    }

#ifdef HAVE_STATUS_SET_BYTES
    MPIR_Status_set_bytes(status, datatype, datatype_size * count);
#endif
}

void ADIOI_PMEMBB_ReadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                              int *error_code)
{
    DEBUG_PRINT(fd->filename);
    *error_code = MPI_SUCCESS;
    ADIOI_GEN_ReadStrided_naive(fd, buf, count, datatype, file_ptr_type, offset, status,
                                error_code);
}
