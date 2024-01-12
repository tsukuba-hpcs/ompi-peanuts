/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"

/* adioi.h has the ADIOI_Fns_struct define */
#include "adioi.h"

    // ADIOI_PMEMBB_OpenColl,         /* OpenColl */
struct ADIOI_Fns_struct ADIO_PMEMBB_operations = {
    ADIOI_PMEMBB_Open,             /* Open */
    ADIOI_GEN_OpenColl,            /* OpenColl */
    ADIOI_PMEMBB_ReadContig,       /* ReadContig */
    ADIOI_PMEMBB_WriteContig,      /* WriteContig */
    ADIOI_PMEMBB_ReadStridedColl,  /* ReadStridedColl */
    ADIOI_PMEMBB_WriteStridedColl, /* WriteStridedColl */
    ADIOI_PMEMBB_SeekIndividual,   /* SeekIndividual */
    ADIOI_PMEMBB_Fcntl,            /* Fcntl */
    ADIOI_PMEMBB_SetInfo,          /* SetInfo */
    ADIOI_PMEMBB_ReadStrided,      /* ReadStrided */
    ADIOI_PMEMBB_WriteStrided,     /* WriteStrided */
    ADIOI_PMEMBB_Close,            /* Close */
    ADIOI_PMEMBB_IreadContig,      /* IreadContig */
    ADIOI_PMEMBB_IwriteContig,     /* IwriteContig */
    ADIOI_PMEMBB_ReadDone,         /* ReadDone */
    ADIOI_PMEMBB_WriteDone,        /* WriteDone */
    ADIOI_PMEMBB_ReadComplete,     /* ReadComplete */
    ADIOI_PMEMBB_WriteComplete,    /* WriteComplete */
    ADIOI_PMEMBB_IreadStrided,     /* IreadStrided */
    ADIOI_PMEMBB_IwriteStrided,    /* IwriteStrided */
    ADIOI_PMEMBB_Flush,            /* Flush */
    ADIOI_PMEMBB_Resize,           /* Resize */
    ADIOI_PMEMBB_Delete,           /* Delete */
    ADIOI_GEN_Feature,             /* Features */
    "PMEMBB: A Persistent Memory Burst Buffer",
    ADIOI_GEN_IreadStridedColl,  /* IreadStridedColl */
    ADIOI_GEN_IwriteStridedColl, /* IwriteStridedColl */
#if defined(F_SETLKW64)
    ADIOI_GEN_SetLock /* SetLock */
#else
    ADIOI_GEN_SetLock64 /* SetLock */
#endif
};
