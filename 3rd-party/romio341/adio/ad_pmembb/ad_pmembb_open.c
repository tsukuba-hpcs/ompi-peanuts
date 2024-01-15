/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "ad_pmembb.h"
#include "adio/ad_ufs/ad_ufs.h"
#include "adioi.h"

void ADIOI_PMEMBB_Open(ADIO_File fd, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);
    int perm, old_mask, amode;
    rpmbb_handler_t handler;
    size_t file_size;

    if (fd->perm == ADIO_PERM_NULL) {
        old_mask = umask(022);
        umask(old_mask);
        perm = old_mask ^ 0666;
    } else
        perm = fd->perm;

    amode = 0;
    if (fd->access_mode & ADIO_CREATE)
        amode = amode | O_CREAT;
    if (fd->access_mode & ADIO_RDONLY)
        amode = amode | O_RDONLY;
    if (fd->access_mode & ADIO_WRONLY)
        amode = amode | O_WRONLY;
    if (fd->access_mode & ADIO_RDWR)
        amode = amode | O_RDWR;
    if (fd->access_mode & ADIO_EXCL)
        amode = amode | O_EXCL;

    fd->fd_direct = -1;
    fd->fd_sys = -1;
    handler = rpmbb_store_open(mca_hook_pmembb_rpmbb_store, fd->comm, fd->filename, amode, perm);
    fd->fs_ptr = (void *) handler;

    if ((fd->fs_ptr != NULL) && (fd->access_mode & ADIO_APPEND)) {
        FPRINTF(stderr, "WARNING: ADIO_APPEND not supported by PMEMBB\n");
        rpmbb_bb_size(handler, &file_size);
        fd->fp_ind = fd->fp_sys_posn = file_size;
    }

    if (fd->fs_ptr == NULL) {
        *error_code = ADIOI_Err_create_code(__func__, fd->filename, errno);
    } else
        *error_code = MPI_SUCCESS;
}

void ADIOI_PMEMBB_OpenColl(ADIO_File fd, int rank, int access_mode, int *error_code)
{
    DEBUG_PRINT(fd->comm, fd->filename);

    int orig_amode_excl, orig_amode_wronly;
    MPI_Comm tmp_comm;
    MPI_Datatype stats_type; /* deferred open: some processes might not
                              * open the file, so we'll exchange some
                              * information with those non-aggregators */

    orig_amode_excl = access_mode;

    if (access_mode & ADIO_CREATE) {
        if (rank == fd->hints->ranklist[0]) {
            /* remove delete_on_close flag if set */
            if (access_mode & ADIO_DELETE_ON_CLOSE)
                fd->access_mode = access_mode ^ ADIO_DELETE_ON_CLOSE;
            else
                fd->access_mode = access_mode;

            tmp_comm = fd->comm;
            fd->comm = MPI_COMM_SELF;
            (*(fd->fns->ADIOI_xxx_Open))(fd, error_code);
            MPI_Bcast(error_code, 1, MPI_INT, fd->hints->ranklist[0], tmp_comm);
            /* if no error, close the file and reopen normally below */
            if (*error_code == MPI_SUCCESS)
                (*(fd->fns->ADIOI_xxx_Close))(fd, error_code);
            fd->comm = tmp_comm;

            fd->access_mode = access_mode; /* back to original */
        } else
            MPI_Bcast(error_code, 1, MPI_INT, fd->hints->ranklist[0], fd->comm);

        if (*error_code != MPI_SUCCESS) {
            FPRINTF(stderr, "[%d] error in ADIOI_GEN_OpenColl\n", rank);
            return;
        } else {
            /* turn off CREAT (and EXCL if set) for real multi-processor open */
            access_mode ^= ADIO_CREATE;
            if (access_mode & ADIO_EXCL)
                access_mode ^= ADIO_EXCL;
        }
    }
    fd->blksize = 1024 * 1024 * 4; /* this large default value should be good for
                                    * most file systems.  any ROMIO driver is free
                                    * to stat the file and find an optimial value */

    /* For writing with data sieving, a read-modify-write is needed. If
       the file is opened for write_only, the read will fail. Therefore,
       if write_only, open the file as read_write, but record it as write_only
       in fd, so that get_amode returns the right answer. */

    /* observation from David Knaak: file systems that do not support data
     * sieving do not need to change the mode */

    orig_amode_wronly = access_mode;
    if ((access_mode & ADIO_WRONLY) && ADIO_Feature(fd, ADIO_DATA_SIEVING_WRITES)) {
        access_mode = access_mode ^ ADIO_WRONLY;
        access_mode = access_mode | ADIO_RDWR;
    }
    fd->access_mode = access_mode;

    (*(fd->fns->ADIOI_xxx_Open))(fd, error_code);

    /* if error, may be it was due to the change in amode above.
     * therefore, reopen with access mode provided by the user. */
    fd->access_mode = orig_amode_wronly;
    if (*error_code != MPI_SUCCESS)
        (*(fd->fns->ADIOI_xxx_Open))(fd, error_code);

    /* if we turned off EXCL earlier, then we should turn it back on */
    if (fd->access_mode != orig_amode_excl)
        fd->access_mode = orig_amode_excl;

    /* file domain code will get terribly confused in a hard-to-debug way if
     * gpfs blocksize not sensible */
    ADIOI_Assert(fd->blksize > 0);

    /* for deferred open: this process has opened the file (because if we are
     * not an aggregaor and we are doing deferred open, we returned earlier)*/
    fd->is_open = 1;
}
