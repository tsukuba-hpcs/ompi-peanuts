/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

void ADIOI_PEANUTS_WriteStridedColl(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                   int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                   int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);
    *error_code = MPI_SUCCESS;
    ADIOI_GEN_WriteStridedColl(fd, buf, count, datatype, file_ptr_type, offset, status, error_code);
}
