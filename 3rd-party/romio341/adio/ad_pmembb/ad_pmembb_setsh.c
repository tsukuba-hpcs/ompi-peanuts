/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_Set_shared_fp(ADIO_File fd, ADIO_Offset offset, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);
    *error_code = MPI_ERR_IO;
}
