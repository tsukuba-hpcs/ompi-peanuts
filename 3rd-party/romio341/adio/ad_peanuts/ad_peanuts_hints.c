/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"
#include "adioi.h"
#ifdef ROMIO_BGL
#    include "../ad_bgl/ad_bgl.h"
#endif
void ADIOI_PEANUTS_SetInfo(ADIO_File fd, MPI_Info users_info, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);
    *error_code = MPI_SUCCESS;
    ADIOI_GEN_SetInfo(fd, users_info, error_code);
}
