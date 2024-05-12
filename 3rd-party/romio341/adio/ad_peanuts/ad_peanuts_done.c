/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

int ADIOI_PEANUTS_ReadDone(ADIO_Request *request, ADIO_Status *status, int *error_code)
{
    DEBUG_PRINT(MPI_COMM_SELF, "called on ADIO_REQUEST_NULL");
    *error_code = MPI_SUCCESS;
    return 1;
}

int ADIOI_PEANUTS_WriteDone(ADIO_Request *request, ADIO_Status *status, int *error_code)
{
    DEBUG_PRINT(MPI_COMM_SELF, "called on ADIO_REQUEST_NULL");
    *error_code = MPI_SUCCESS;
    return 1;
}
