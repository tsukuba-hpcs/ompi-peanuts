/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_ReadComplete(ADIO_Request *request, ADIO_Status *status, int *error_code)
{
    DEBUG_PRINT(MPI_COMM_SELF, "called");
    *error_code = MPI_SUCCESS;
    /* do something with status set bytes? */
}

void ADIOI_PMEMBB_WriteComplete(ADIO_Request *request, ADIO_Status *status, int *error_code)
{
    DEBUG_PRINT(MPI_COMM_SELF, "called");
    *error_code = MPI_SUCCESS;
    /* do something with status_set_bytes? */
}
