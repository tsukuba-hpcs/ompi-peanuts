/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

/* ADIOI_PMEMBB_IreadContig()
 *
 * Implemented by immediately calling ReadContig()
 */
void ADIOI_PMEMBB_IreadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                              int *error_code)
{
    ADIO_Status status;
    MPI_Count typesize, len;
    DEBUG_PRINT(fd->filename);

    *error_code = MPI_SUCCESS;

    MPI_Type_size_x(datatype, &typesize);
    len = count * typesize;
    ADIOI_PMEMBB_ReadContig(fd, buf, len, MPI_BYTE, file_ptr_type, offset, &status, error_code);

    MPIO_Completed_request_create(&fd, len, error_code, request);
}

void ADIOI_PMEMBB_IreadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                               int *error_code)
{
    ADIO_Status status;
    MPI_Count typesize;
    DEBUG_PRINT(fd->filename);

    MPI_Type_size_x(datatype, &typesize);

    ADIOI_PMEMBB_ReadStrided(fd, buf, count, datatype, file_ptr_type, offset, &status, error_code);
    MPIO_Completed_request_create(&fd, count * typesize, error_code, request);
}
