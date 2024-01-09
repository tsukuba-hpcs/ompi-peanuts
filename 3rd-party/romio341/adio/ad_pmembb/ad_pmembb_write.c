/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_WriteContig(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                              int *error_code)
{
    MPI_Count datatype_size;
    rpmbb_handler_t handler = (rpmbb_handler_t) fd->fs_ptr;
    DEBUG_PRINT(fd->filename);

    *error_code = MPI_SUCCESS;

    MPI_Type_size_x(datatype, &datatype_size);

    off_t absolute_offset = file_ptr_type == ADIO_INDIVIDUAL ? fd->fp_ind : offset;
    size_t data_size = datatype_size * count;
    size_t bytes_written = 0;
    ssize_t ret;

#ifndef NDEBUG
    FPRINTF(stdout, "[%d/%d]    writing (buf = %p, loc = %lld, sz = %lld)\n", myrank, nprocs, buf,
            (long long) absolute_offset, (long long) data_size);
#endif

    while (bytes_written < data_size) {
        ret = rpmbb_bb_pwrite(handler, (char *) buf + bytes_written, data_size - bytes_written,
                              absolute_offset + bytes_written);
        if (ret < 0) {
            *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
            fd->fp_sys_posn = -1;
            return;
        }
#ifndef NDEBUG
        FPRINTF(stdout, "[%d/%d]    wrote %ld bytes\n", myrank, nprocs, ret);
#endif
        bytes_written += ret;
    }

    fd->fp_sys_posn = absolute_offset + bytes_written;
    if (file_ptr_type == ADIO_INDIVIDUAL) {
        fd->fp_ind += bytes_written;
#ifdef DEBUG
        FPRINTF(stdout, "[%d/%d]    new file position is %lld\n", myrank, nprocs,
                (long long) fd->fp_ind);
#endif
    }

#ifdef HAVE_STATUS_SET_BYTES
    MPIR_Status_set_bytes(status, datatype, datatype_size * count);
#endif
}

void ADIOI_PMEMBB_WriteStrided(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                               int *error_code)
{
    DEBUG_PRINT(fd->filename);
    *error_code = MPI_SUCCESS;
    ADIOI_GEN_WriteStrided_naive(fd, buf, count, datatype, file_ptr_type, offset, status,
                                 error_code);
}
