/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"

void ADIOI_PEANUTS_Close(ADIO_File fd, int *error_code)
{
    int ret;
    peanuts_handler_t handler = (peanuts_handler_t) fd->fs_ptr;
    DEBUG_PRINT(fd->comm, fd->filename);

    if (handler != NULL) {
        // int comp_result;
        // MPI_Comm_compare(MPI_COMM_WORLD, fd->comm, &comp_result);
        // if (comp_result == MPI_IDENT) {
        //     ret = peanuts_bb_sync(handler);
        //     if (ret != 0) {
        //         *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
        //         DEBUG_PRINT(fd->comm, "peanuts_bb_sync failed");
        //     }
        // }
        peanuts_bb_close(handler);
    }

    fd->fs_ptr = NULL;
    fd->fd_sys = -1;
    fd->fd_direct = -1;
}
