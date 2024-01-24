/*
 * Copyright (c) 2017      IBM Corporation.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#ifndef MCA_HOOK_PMEMBB_H
#define MCA_HOOK_PMEMBB_H

#include "ompi_config.h"

#include "ompi/constants.h"

#include "opal/util/output.h"

#include "ompi/mca/hook/base/base.h"
#include "ompi/mca/hook/hook.h"
#include "3rd-party/romio341/adio/ad_pmembb/rpmbb_c.h"

BEGIN_C_DECLS

OMPI_DECLSPEC extern const ompi_hook_base_component_1_0_0_t mca_hook_pmembb_component;

extern rpmbb_store_t mca_hook_pmembb_rpmbb_store;
extern char* mca_hook_pmembb_pmem_path;
extern size_t mca_hook_pmembb_pmem_size;
extern bool mca_hook_pmembb_save;
extern bool mca_hook_pmembb_load;
extern bool mca_hook_pmembb_enable;

void ompi_hook_pmembb_mpi_init_bottom(int argc, char **argv, int requested, int *provided);

void ompi_hook_pmembb_mpi_finalize_top(void);

END_C_DECLS

#endif /* MCA_HOOK_PMEMBB_H */
