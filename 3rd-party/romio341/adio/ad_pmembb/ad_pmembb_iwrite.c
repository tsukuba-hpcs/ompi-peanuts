/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

#include "../../mpi-io/mpioimpl.h"
#include "mpiu_greq.h"

/* ADIOI_PMEMBB_IwriteContig()
 *
 * Implemented by immediately calling WriteContig()
 */
void ADIOI_PMEMBB_IwriteContig(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                               int *error_code)
{
    ADIO_Status status;
    MPI_Count typesize, len;
    DEBUG_PRINT(fd->comm, fd->filename);

    *error_code = MPI_SUCCESS;

    MPI_Type_size_x(datatype, &typesize);
    len = count * typesize;
    ADIOI_PMEMBB_WriteContig(fd, buf, len, MPI_BYTE, file_ptr_type, offset, &status, error_code);
    MPIO_Completed_request_create(&fd, len, error_code, request);
}

void ADIOI_PMEMBB_IwriteStrided(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                                int *error_code)
{
    ADIO_Status status;
    MPI_Count typesize;
    DEBUG_PRINT(fd->comm, fd->filename);

    *error_code = MPI_SUCCESS;

    MPI_Type_size_x(datatype, &typesize);
    ADIOI_PMEMBB_WriteStrided(fd, buf, count, datatype, file_ptr_type, offset, &status, error_code);
    MPIO_Completed_request_create(&fd, count * typesize, error_code, request);
}
