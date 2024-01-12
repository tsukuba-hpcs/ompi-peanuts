/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_Resize(ADIO_File fd, ADIO_Offset size, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);
    *error_code = MPI_SUCCESS;
    ADIOI_GEN_Resize(fd, size, error_code);
}
