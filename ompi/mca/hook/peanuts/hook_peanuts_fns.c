/*
 * Copyright (c) 2017      IBM Corporation.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "hook_peanuts.h"

peanuts_store_t mca_hook_peanuts_peanuts_store = NULL;

void ompi_hook_peanuts_mpi_init_bottom(int argc, char **argv, int requested, int *provided)
{
    if (!mca_hook_peanuts_enable) {
        return;
    }
    mca_hook_peanuts_peanuts_store = peanuts_store_create(MPI_COMM_WORLD, mca_hook_peanuts_pmem_path,
                                                     mca_hook_peanuts_pmem_size);
    if (mca_hook_peanuts_peanuts_store == NULL) {
        opal_output(0, "hook:peanuts: peanuts_store_create failed");
        return;
    }

    if (mca_hook_peanuts_load) {
        if (peanuts_store_load(mca_hook_peanuts_peanuts_store)) {
            opal_output(0, "hook:peanuts: peanuts_store_load failed");
            return;
        }
        // opal_output(0, "hook:peanuts: peanuts_store_load succeeded");
    }
}

void ompi_hook_peanuts_mpi_finalize_top(void)
{
    if (mca_hook_peanuts_peanuts_store == NULL) {
        return;
    }
    if (mca_hook_peanuts_save) {
        if (peanuts_store_save(mca_hook_peanuts_peanuts_store)) {
            opal_output(0, "hook:peanuts: peanuts_store_save failed");
            return;
        }
        // opal_output(0, "hook:peanuts: peanuts_store_save succeeded");
    }
    peanuts_store_free(mca_hook_peanuts_peanuts_store);
}
