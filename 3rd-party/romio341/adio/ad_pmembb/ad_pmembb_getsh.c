/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_Get_shared_fp(ADIO_File fd, int size, ADIO_Offset *shared_fp, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);
    *error_code = MPI_ERR_IO;
}
