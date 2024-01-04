/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_ReadComplete(ADIO_Request *request, ADIO_Status *status, int *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_PMEMBB_ReadComplete called \n", myrank, nprocs);

    /* do something with status set bytes? */
}

void ADIOI_PMEMBB_WriteComplete(ADIO_Request *request, ADIO_Status *status, int *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_PMEMBB_WriteComplete called\n", myrank, nprocs);

    /* do something with status_set_bytes? */
}
