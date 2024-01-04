/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"
#ifdef ROMIO_BGL
#    include "../ad_bgl/ad_bgl.h"
#endif
void ADIOI_PMEMBB_SetInfo(ADIO_File fd, MPI_Info users_info, int *error_code)
{
    int myrank, nprocs;

    *error_code = MPI_SUCCESS;

    MPI_Comm_size(fd->comm, &nprocs);
    MPI_Comm_rank(fd->comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_PMEMBB_SetInfo called on %s\n", myrank, nprocs, fd->filename);
    FPRINTF(stdout, "[%d/%d]    calling ADIOI_GEN_SetInfo\n", myrank, nprocs);

    ADIOI_GEN_SetInfo(fd, users_info, error_code);
}
