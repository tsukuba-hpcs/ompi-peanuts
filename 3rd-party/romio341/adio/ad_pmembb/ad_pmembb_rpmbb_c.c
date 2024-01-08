#include "ad_pmembb.h"
#include "rpmbb_c.h"

#pragma weak rpmbb_store_create = default_rpmbb_store_create
#pragma weak rpmbb_store_free = default_rpmbb_store_free
#pragma weak rpmbb_store_save = default_rpmbb_store_save
#pragma weak rpmbb_store_load = default_rpmbb_store_load
#pragma weak rpmbb_store_open_attach = default_rpmbb_store_open_attach
#pragma weak rpmbb_bb_close = default_rpmbb_bb_close
#pragma weak rpmbb_bb_pwrite = default_rpmbb_bb_pwrite
#pragma weak rpmbb_bb_pread = default_rpmbb_bb_pread
#pragma weak rpmbb_bb_sync = default_rpmbb_bb_sync

rpmbb_store_t default_rpmbb_store_create(MPI_Comm comm, const char *pmem_path, size_t pmem_size)
{
    FPRINTF(stderr, "default_rpmbb_store_create\n");
    return NULL;
}

int default_rpmbb_store_free(rpmbb_store_t store)
{
    FPRINTF(stderr, "default_rpmbb_store_free\n");
    return -1;
}

int default_rpmbb_store_save(rpmbb_store_t store)
{
    FPRINTF(stderr, "default_rpmbb_store_save\n");
    return -1;
}

int default_rpmbb_store_load(rpmbb_store_t store)
{
    FPRINTF(stderr, "default_rpmbb_store_load\n");
    return -1;
}

rpmbb_handler_t default_rpmbb_store_open_attach(rpmbb_store_t store, int fd)
{
    FPRINTF(stderr, "default_rpmbb_store_open_attach\n");
    return NULL;
}

int default_rpmbb_bb_close(rpmbb_handler_t handler)
{
    FPRINTF(stderr, "default_rpmbb_bb_close\n");
    return -1;
}
ssize_t default_rpmbb_bb_pwrite(rpmbb_handler_t handler, const void *buf, size_t count,
                                off_t offset)
{
    FPRINTF(stderr, "default_rpmbb_bb_pwrite\n");
    return -1;
}

ssize_t default_rpmbb_bb_pread(rpmbb_handler_t handler, void *buf, size_t count, off_t offset)
{
    FPRINTF(stderr, "default_rpmbb_bb_pread\n");
    return -1;
}

int default_rpmbb_bb_sync(rpmbb_handler_t handler)
{
    FPRINTF(stderr, "default_rpmbb_bb_sync\n");
    return -1;
}
