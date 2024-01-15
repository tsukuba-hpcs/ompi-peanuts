/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_Resize(ADIO_File fd, ADIO_Offset size, int *error_code)
{
    int ret;
    DEBUG_PRINT(fd->comm, fd->filename);

    ret = rpmbb_bb_truncate((rpmbb_handler_t) fd->fs_ptr, size);
    if (ret != 0) {
        *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
        DEBUG_PRINT(fd->comm, "rpmbb_bb_truncate failed");
        return;
    }

    *error_code = MPI_SUCCESS;
}
