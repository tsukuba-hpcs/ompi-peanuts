/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

/* ADIOI_PEANUTS_IreadContig()
 *
 * Implemented by immediately calling ReadContig()
 */
void ADIOI_PEANUTS_IreadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                              int *error_code)
{
    ADIO_Status status;
    MPI_Count typesize, len;
    DEBUG_PRINT(fd->comm, fd->filename);

    *error_code = MPI_SUCCESS;

    MPI_Type_size_x(datatype, &typesize);
    len = count * typesize;
    ADIOI_PEANUTS_ReadContig(fd, buf, len, MPI_BYTE, file_ptr_type, offset, &status, error_code);

    MPIO_Completed_request_create(&fd, len, error_code, request);
}

void ADIOI_PEANUTS_IreadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                               int *error_code)
{
    ADIO_Status status;
    MPI_Count typesize;
    DEBUG_PRINT(fd->comm, fd->filename);

    MPI_Type_size_x(datatype, &typesize);

    ADIOI_PEANUTS_ReadStrided(fd, buf, count, datatype, file_ptr_type, offset, &status, error_code);
    MPIO_Completed_request_create(&fd, count * typesize, error_code, request);
}
