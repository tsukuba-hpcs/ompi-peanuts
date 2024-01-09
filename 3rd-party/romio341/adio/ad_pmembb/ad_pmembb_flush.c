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
    DEBUG_PRINT(fd->filename);

    *error_code = MPI_SUCCESS;

    if (fd->is_open > 0) {
        // FIXME: rpmbb_bb_sync() is not working other than MPI_COMM_WORLD
        if (fd->comm == MPI_COMM_WORLD) {
            ret = rpmbb_bb_sync(handler);
            if (ret != 0) {
                *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
                return;
            }
        }
    }
}
