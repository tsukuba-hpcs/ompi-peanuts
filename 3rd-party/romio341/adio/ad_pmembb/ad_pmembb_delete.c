/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_Delete(const char *filename, int *error_code)
{
    DEBUG_PRINT(MPI_COMM_SELF, filename);
    *error_code = MPI_SUCCESS;
    ADIOI_GEN_Delete(filename, error_code);
}
