/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

void ADIOI_PEANUTS_Resize(ADIO_File fd, ADIO_Offset size, int *error_code)
{
    int ret;
    DEBUG_PRINT(fd->comm, fd->filename);

    ret = peanuts_bb_truncate((peanuts_handler_t) fd->fs_ptr, size);
    if (ret != 0) {
        *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
        DEBUG_PRINT(fd->comm, "peanuts_bb_truncate failed");
        return;
    }

    *error_code = MPI_SUCCESS;
}
