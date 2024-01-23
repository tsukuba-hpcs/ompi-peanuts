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

static int ompi_hook_pmembb_component_open(void);
static int ompi_hook_pmembb_component_close(void);
static int ompi_hook_pmembb_component_register(void);

/*
 * Public string showing the component version number
 */
const char *mca_hook_pmembb_component_version_string
    = "Open MPI 'pmembb' hook MCA component version " OMPI_VERSION;

/*
 * Instantiate the public struct with all of our public information
 * and pointers to our public functions in it
 */
const ompi_hook_base_component_1_0_0_t mca_hook_pmembb_component = {

    /* First, the mca_component_t struct containing meta information
     * about the component itself */
    .hookm_version = {
        OMPI_HOOK_BASE_VERSION_1_0_0,

        /* Component name and version */
        .mca_component_name = "pmembb",
        MCA_BASE_MAKE_VERSION(component, OMPI_MAJOR_VERSION, OMPI_MINOR_VERSION,
                              OMPI_RELEASE_VERSION),

        /* Component open and close functions */
        .mca_open_component = ompi_hook_pmembb_component_open,
        .mca_close_component = ompi_hook_pmembb_component_close,
        .mca_register_component_params = ompi_hook_pmembb_component_register,

        // Force this component to always be considered - component must be static
        .mca_component_flags = MCA_BASE_COMPONENT_FLAG_REQUIRED,
    },
    .hookm_data = {
        /* The component is checkpoint ready */
        MCA_BASE_METADATA_PARAM_NONE
    },

    /* Component functions */
    .hookm_mpi_initialized_top = NULL,
    .hookm_mpi_initialized_bottom = NULL,

    .hookm_mpi_finalized_top = NULL,
    .hookm_mpi_finalized_bottom = NULL,

    .hookm_mpi_init_top = NULL,
    .hookm_mpi_init_top_post_opal = NULL,
    .hookm_mpi_init_bottom = ompi_hook_pmembb_mpi_init_bottom,
    .hookm_mpi_init_error = NULL,

    .hookm_mpi_finalize_top = ompi_hook_pmembb_mpi_finalize_top,
    .hookm_mpi_finalize_bottom = NULL,
};

char *mca_hook_pmembb_pmem_path = "/dev/dax0.0";
size_t mca_hook_pmembb_pmem_size = 0;
bool mca_hook_pmembb_save = true;
bool mca_hook_pmembb_load = false;
bool mca_hook_pmembb_enable = true;

static int ompi_hook_pmembb_component_open(void)
{
    return OMPI_SUCCESS;
}

static int ompi_hook_pmembb_component_close(void)
{
    return OMPI_SUCCESS;
}

static int ompi_hook_pmembb_component_register(void)
{
    // mca_hook_pmembb_pmem_path
    (void) mca_base_component_var_register(&mca_hook_pmembb_component.hookm_version, "pmem_path",
                                           "Path to the pmem device", MCA_BASE_VAR_TYPE_STRING,
                                           NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE, OPAL_INFO_LVL_3,
                                           MCA_BASE_VAR_SCOPE_READONLY, &mca_hook_pmembb_pmem_path);

    // mca_hook_pmembb_pmem_size
    (void) mca_base_component_var_register(&mca_hook_pmembb_component.hookm_version, "pmem_size",
                                           "Size of the pmem device", MCA_BASE_VAR_TYPE_SIZE_T,
                                           NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE, OPAL_INFO_LVL_3,
                                           MCA_BASE_VAR_SCOPE_READONLY, &mca_hook_pmembb_pmem_size);

    // mca_hook_pmembb_save
    (void) mca_base_component_var_register(&mca_hook_pmembb_component.hookm_version, "save",
                                           "Save the pmem data", MCA_BASE_VAR_TYPE_BOOL, NULL, 0,
                                           MCA_BASE_VAR_FLAG_SETTABLE, OPAL_INFO_LVL_3,
                                           MCA_BASE_VAR_SCOPE_READONLY, &mca_hook_pmembb_save);

    // mca_hook_pmembb_load
    (void) mca_base_component_var_register(&mca_hook_pmembb_component.hookm_version, "load",
                                           "Load the pmem data", MCA_BASE_VAR_TYPE_BOOL, NULL, 0,
                                           MCA_BASE_VAR_FLAG_SETTABLE, OPAL_INFO_LVL_3,
                                           MCA_BASE_VAR_SCOPE_READONLY, &mca_hook_pmembb_load);

    // mca_hook_pmembb_enable
    (void) mca_base_component_var_register(&mca_hook_pmembb_component.hookm_version, "enable",
                                           "Enable pmembb", MCA_BASE_VAR_TYPE_BOOL, NULL, 0,
                                           MCA_BASE_VAR_FLAG_SETTABLE, OPAL_INFO_LVL_3,
                                           MCA_BASE_VAR_SCOPE_READONLY, &mca_hook_pmembb_enable);
    return OMPI_SUCCESS;
}
