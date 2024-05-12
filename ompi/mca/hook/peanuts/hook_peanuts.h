/*
 * Copyright (c) 2017      IBM Corporation.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#ifndef MCA_HOOK_PEANUTS_H
#define MCA_HOOK_PEANUTS_H

#include "ompi_config.h"

#include "ompi/constants.h"

#include "opal/util/output.h"

#include "ompi/mca/hook/base/base.h"
#include "ompi/mca/hook/hook.h"
#include "3rd-party/romio341/adio/ad_peanuts/peanuts_c.h"

BEGIN_C_DECLS

OMPI_DECLSPEC extern const ompi_hook_base_component_1_0_0_t mca_hook_peanuts_component;

extern peanuts_store_t mca_hook_peanuts_peanuts_store;
extern char* mca_hook_peanuts_pmem_path;
extern size_t mca_hook_peanuts_pmem_size;
extern bool mca_hook_peanuts_save;
extern bool mca_hook_peanuts_load;
extern bool mca_hook_peanuts_enable;

void ompi_hook_peanuts_mpi_init_bottom(int argc, char **argv, int requested, int *provided);

void ompi_hook_peanuts_mpi_finalize_top(void);

END_C_DECLS

#endif /* MCA_HOOK_PEANUTS_H */
