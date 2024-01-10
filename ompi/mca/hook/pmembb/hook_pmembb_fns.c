/*
 * Copyright (c) 2017      IBM Corporation.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "hook_pmembb.h"

rpmbb_store_t mca_hook_pmembb_rpmbb_store = NULL;

void ompi_hook_pmembb_mpi_init_bottom(int argc, char **argv, int requested, int *provided)
{
    if (mca_hook_pmembb_pmem_path == NULL) {
        return;
    }
    mca_hook_pmembb_rpmbb_store = rpmbb_store_create(MPI_COMM_WORLD, mca_hook_pmembb_pmem_path,
                                                     mca_hook_pmembb_pmem_size);
    if (mca_hook_pmembb_rpmbb_store == NULL) {
        opal_output(0, "hook:pmembb: rpmbb_store_create failed");
        return;
    }

    if (mca_hook_pmembb_load) {
        if (rpmbb_store_load(mca_hook_pmembb_rpmbb_store)) {
            opal_output(0, "hook:pmembb: rpmbb_store_load failed");
            return;
        }
        // opal_output(0, "hook:pmembb: rpmbb_store_load succeeded");
    }
}

void ompi_hook_pmembb_mpi_finalize_top(void)
{
    if (mca_hook_pmembb_rpmbb_store == NULL) {
        return;
    }
    if (mca_hook_pmembb_save) {
        if (rpmbb_store_save(mca_hook_pmembb_rpmbb_store)) {
            opal_output(0, "hook:pmembb: rpmbb_store_save failed");
            return;
        }
        // opal_output(0, "hook:pmembb: rpmbb_store_save succeeded");
    }
    rpmbb_store_free(mca_hook_pmembb_rpmbb_store);
}
