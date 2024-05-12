/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

void ADIOI_PEANUTS_Flush(ADIO_File fd, int *error_code)
{
    int ret;
    peanuts_handler_t handler = (peanuts_handler_t) fd->fs_ptr;
    DEBUG_PRINT(fd->comm, fd->filename);

    *error_code = MPI_SUCCESS;

    if (fd->is_open > 0) {
        ret = peanuts_bb_sync(handler);
        if (ret != 0) {
            *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
            return;
        }
    }
}
