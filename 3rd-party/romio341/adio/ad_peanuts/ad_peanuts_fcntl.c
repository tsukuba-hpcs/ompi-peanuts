/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adio_extern.h"
#include "adioi.h"

void ADIOI_PEANUTS_Fcntl(ADIO_File fd, int flag, ADIO_Fcntl_t *fcntl_struct, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);

    *error_code = MPI_SUCCESS;

    switch (flag) {
    case ADIO_FCNTL_GET_FSIZE:
        peanuts_handler_t handler = (peanuts_handler_t) fd->fs_ptr;
        size_t fsize;
        int ret;
        ret = peanuts_bb_size(handler, &fsize);
        if(ret != 0) {
            *error_code = ADIOI_Err_create_code(__func__, fd->filename, -ret);
            return;
        }
        fcntl_struct->fsize = fsize;
        break;

    case ADIO_FCNTL_SET_DISKSPACE:
        FPRINTF(stderr, "WARNING: ADIO_FCNTL_SET_DISKSPACE is not supported\n");
        *error_code = MPI_SUCCESS;
        break;

    case ADIO_FCNTL_SET_ATOMICITY:
        if (fcntl_struct->atomicity == 1) {
            FPRINTF(stderr, "WARNING: atomic mode is not supported\n");
        }
        *error_code = MPI_SUCCESS;
        break;

    default:
        /* --BEGIN ERROR HANDLING-- */
        *error_code = MPIO_Err_create_code(MPI_SUCCESS, MPIR_ERR_RECOVERABLE, __func__, __LINE__,
                                           MPI_ERR_ARG, "**flag", "**flag %d", flag);
        return;
        /* --END ERROR HANDLING-- */
    }
}
