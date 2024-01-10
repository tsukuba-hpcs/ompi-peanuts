/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adio/ad_ufs/ad_ufs.h"
#include "adioi.h"

void ADIOI_PMEMBB_Open(ADIO_File fd, int *error_code)
{
    DEBUG_PRINT(fd->filename);
    ADIOI_UFS_Open(fd, error_code);

    if (*error_code != MPI_SUCCESS) {
        return;
    }

    fd->fs_ptr = rpmbb_store_open_attach(mca_hook_pmembb_rpmbb_store, fd->comm, fd->fd_sys);
    if (fd->fs_ptr == NULL) {
        *error_code = ADIOI_Err_create_code("ADIOI_PMEMBB_Open", fd->filename, errno);
        return;
    }
}
