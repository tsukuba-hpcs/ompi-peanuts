/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adioi.h"

void ADIOI_PMEMBB_Flush(ADIO_File fd, int *error_code)
{
    int ret;
    rpmbb_handler_t handler = (rpmbb_handler_t) fd->fs_ptr;
    DEBUG_PRINT(fd->comm, fd->filename);

    *error_code = MPI_SUCCESS;

    if (fd->is_open > 0) {
        ret = rpmbb_bb_sync(handler);
        if (ret != 0) {
            *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
            return;
        }
    }
}
