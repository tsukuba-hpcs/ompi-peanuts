#include "ad_pmembb.h"

rpmbb_store_t ADIOI_PMEMBB_store = NULL;
static int ADIOI_PMEMBB_keyval = MPI_KEYVAL_INVALID;

void ADIOI_PMEMBB_Term(int *error_code)
{
    char *tmp;
    int pmem_save;

    *error_code = MPI_SUCCESS;
    if (ADIOI_PMEMBB_store == NULL) {
        return;
    }

    tmp = getenv("PMEMBB_SAVE");
    pmem_save = tmp ? atoi(tmp) : 0;

    if (pmem_save) {
        if (rpmbb_store_save(ADIOI_PMEMBB_store) != 0) {
            *error_code = MPI_ERR_IO;
            return;
        }
    }
    rpmbb_store_free(ADIOI_PMEMBB_store);
    ADIOI_PMEMBB_store = NULL;
}

void ADIOI_PMEMBB_Term_cb(MPI_Comm comm, int keyval, void *attribute_val, void *extra_state)
{
    int error_code;
#ifndef NDEBUG
    int myrank, nprocs;
    MPI_Comm_size(comm, &nprocs);
    MPI_Comm_rank(comm, &myrank);
    FPRINTF(stdout, "[%d/%d] ADIOI_PMEMBB_Term_cb called\n", myrank, nprocs);
#endif
    ADIOI_PMEMBB_Term(&error_code);
    MPI_Comm_free_keyval(&keyval);
    return error_code;
}

void ADIOI_PMEMBB_InitColl(MPI_Comm comm, int *error_code)
{
    static char default_pmem_path[] = "/dev/dax0.0";
    char *tmp;
    char *pmem_path;
    size_t pmem_size;
    int pmem_load;

    *error_code = MPI_SUCCESS;

    if (ADIOI_PMEMBB_store != NULL) {
        return;
    }

    tmp = getenv("PMEMBB_PMEM_PATH");
    pmem_path = tmp ? tmp : default_pmem_path;

    tmp = getenv("PMEMBB_PMEM_SIZE");
    pmem_size = tmp ? atol(tmp) : 0;

    tmp = getenv("PMEMBB_LOAD");
    pmem_load = tmp ? atoi(tmp) : 0;

    ADIOI_PMEMBB_store = rpmbb_store_create(MPI_COMM_WORLD, pmem_path, pmem_size);
    if (ADIOI_PMEMBB_store == NULL) {
        *error_code = MPI_ERR_IO;
        return;
    }

    if (pmem_load) {
        if (rpmbb_store_load(ADIOI_PMEMBB_store) != 0) {
            rpmbb_store_free(ADIOI_PMEMBB_store);
            ADIOI_PMEMBB_store = NULL;
            *error_code = MPI_ERR_IO;
            return;
        }
    }

    MPI_Comm_create_keyval(MPI_COMM_NULL_COPY_FN, ADIOI_PMEMBB_Term_cb, &ADIOI_PMEMBB_keyval,
                           (void *) 0);
    MPI_Comm_set_attr(MPI_COMM_SELF, ADIOI_PMEMBB_keyval, (void *) 0);
}
