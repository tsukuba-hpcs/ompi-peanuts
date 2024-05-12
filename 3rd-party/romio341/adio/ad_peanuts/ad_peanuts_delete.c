/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

void ADIOI_PEANUTS_Delete(const char *filename, int *error_code)
{
    int err;
    DEBUG_PRINT(MPI_COMM_SELF, filename);

    err = unlink(filename);
    if (err == -1) {
        *error_code = ADIOI_Err_create_code(__func__, filename, errno);
        return;
    }

    peanuts_store_unlink(mca_hook_peanuts_peanuts_store, filename);

    *error_code = MPI_SUCCESS;
}
