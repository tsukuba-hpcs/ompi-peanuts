/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adio_extern.h"
#include "adioi.h"

void ADIOI_PMEMBB_Fcntl(ADIO_File fd, int flag, ADIO_Fcntl_t *fcntl_struct, int *error_code)
{
    DEBUG_PRINT(fd->filename);

    *error_code = MPI_SUCCESS;

    switch (flag) {
    case ADIO_FCNTL_GET_FSIZE:
        // FIXME: this is not correct file size
        ADIOI_GEN_Fcntl(fd, flag, fcntl_struct, error_code);
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
