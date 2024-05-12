/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_peanuts.h"

/* adioi.h has the ADIOI_Fns_struct define */
#include "adioi.h"

struct ADIOI_Fns_struct ADIO_PEANUTS_operations = {
    ADIOI_PEANUTS_Open,             /* Open */
    ADIOI_PEANUTS_OpenColl,         /* OpenColl */
    ADIOI_PEANUTS_ReadContig,       /* ReadContig */
    ADIOI_PEANUTS_WriteContig,      /* WriteContig */
    ADIOI_PEANUTS_ReadStridedColl,  /* ReadStridedColl */
    ADIOI_PEANUTS_WriteStridedColl, /* WriteStridedColl */
    ADIOI_PEANUTS_SeekIndividual,   /* SeekIndividual */
    ADIOI_PEANUTS_Fcntl,            /* Fcntl */
    ADIOI_PEANUTS_SetInfo,          /* SetInfo */
#ifdef PEANUTS_AGGREGATE_READ
    ADIOI_PEANUTS_ReadStrided,      /* Aggregated ReadStrided */
#else
    ADIOI_GEN_ReadStrided,         /* Non-aggregated ReadStrided */
#endif
    ADIOI_PEANUTS_WriteStrided,     /* WriteStrided */
    ADIOI_PEANUTS_Close,            /* Close */
    ADIOI_PEANUTS_IreadContig,      /* IreadContig */
    ADIOI_PEANUTS_IwriteContig,     /* IwriteContig */
    ADIOI_PEANUTS_ReadDone,         /* ReadDone */
    ADIOI_PEANUTS_WriteDone,        /* WriteDone */
    ADIOI_PEANUTS_ReadComplete,     /* ReadComplete */
    ADIOI_PEANUTS_WriteComplete,    /* WriteComplete */
    ADIOI_PEANUTS_IreadStrided,     /* IreadStrided */
    ADIOI_PEANUTS_IwriteStrided,    /* IwriteStrided */
    ADIOI_PEANUTS_Flush,            /* Flush */
    ADIOI_PEANUTS_Resize,           /* Resize */
    ADIOI_PEANUTS_Delete,           /* Delete */
    ADIOI_PEANUTS_Feature,          /* Features */
    "PEANUTS: A Persistent Memory-Based Network Unilateral Transfer System",
    ADIOI_GEN_IreadStridedColl,  /* IreadStridedColl */
    ADIOI_GEN_IwriteStridedColl, /* IwriteStridedColl */
#if defined(F_SETLKW64)
    ADIOI_GEN_SetLock /* SetLock */
#else
    ADIOI_GEN_SetLock64 /* SetLock */
#endif
};
