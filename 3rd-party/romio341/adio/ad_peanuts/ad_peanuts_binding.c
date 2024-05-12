#include "ad_peanuts.h"
#include "peanuts_c.h"

#pragma weak peanuts_store_create = default_peanuts_store_create
#pragma weak peanuts_store_free = default_peanuts_store_free
#pragma weak peanuts_store_save = default_peanuts_store_save
#pragma weak peanuts_store_load = default_peanuts_store_load
#pragma weak peanuts_store_open = default_peanuts_store_open
#pragma weak peanuts_store_unlink = default_peanuts_store_unlink
#pragma weak peanuts_bb_close = default_peanuts_bb_close
#pragma weak peanuts_bb_pwrite = default_peanuts_bb_pwrite
#pragma weak peanuts_bb_pread = default_peanuts_bb_pread
#pragma weak peanuts_bb_pread_aggregate = default_peanuts_bb_pread_aggregate
#pragma weak peanuts_bb_wait = default_peanuts_bb_wait
#pragma weak peanuts_bb_sync = default_peanuts_bb_sync
#pragma weak peanuts_bb_size = default_peanuts_bb_size
#pragma weak peanuts_bb_truncate = default_peanuts_bb_truncate

peanuts_store_t default_peanuts_store_create(MPI_Comm comm, const char *pmem_path, size_t pmem_size)
{
    FPRINTF(stderr, "default_peanuts_store_create\n");
    return NULL;
}

int default_peanuts_store_free(peanuts_store_t store)
{
    FPRINTF(stderr, "default_peanuts_store_free\n");
    return -1;
}

int default_peanuts_store_save(peanuts_store_t store)
{
    FPRINTF(stderr, "default_peanuts_store_save\n");
    return -1;
}

int default_peanuts_store_load(peanuts_store_t store)
{
    FPRINTF(stderr, "default_peanuts_store_load\n");
    return -1;
}

peanuts_handler_t default_peanuts_store_open(peanuts_store_t store, MPI_Comm comm, const char *pathname,
                                         int flags, mode_t mode)
{
    FPRINTF(stderr, "default_peanuts_store_open\n");
    return NULL;
}

int default_peanuts_store_unlink(peanuts_store_t store, const char *pathname)
{
    FPRINTF(stderr, "default_peanuts_store_unlink\n");
    return -1;
}

int default_peanuts_bb_close(peanuts_handler_t handler)
{
    FPRINTF(stderr, "default_peanuts_bb_close\n");
    return -1;
}
ssize_t default_peanuts_bb_pwrite(peanuts_handler_t handler, const void *buf, size_t count,
                                off_t offset)
{
    FPRINTF(stderr, "default_peanuts_bb_pwrite\n");
    return -1;
}

ssize_t default_peanuts_bb_pread(peanuts_handler_t handler, void *buf, size_t count, off_t offset)
{
    FPRINTF(stderr, "default_peanuts_bb_pread\n");
    return -1;
}

ssize_t default_peanuts_bb_pread_aggregate(peanuts_handler_t handler, void *buf, size_t count,
                                         off_t offset)
{
    FPRINTF(stderr, "default_peanuts_bb_pread_aggregate\n");
    return -1;
}

int default_peanuts_bb_wait(peanuts_handler_t handler)
{
    FPRINTF(stderr, "default_peanuts_bb_wait\n");
    return -1;
}

int default_peanuts_bb_sync(peanuts_handler_t handler)
{
    FPRINTF(stderr, "default_peanuts_bb_sync\n");
    return -1;
}

int default_peanuts_bb_size(peanuts_handler_t handler, size_t *size)
{
    FPRINTF(stderr, "default_peanuts_bb_size\n");
    return -1;
}

int default_peanuts_bb_truncate(peanuts_handler_t handler, size_t size)
{
    FPRINTF(stderr, "default_peanuts_bb_truncate\n");
    return -1;
}
