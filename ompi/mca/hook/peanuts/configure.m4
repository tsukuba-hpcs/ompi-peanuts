#
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# Copyright (c) 2024      range3 ( https://github.com/range3 )
#
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

# Make this a static component
AC_DEFUN([MCA_ompi_hook_peanuts_COMPILE_MODE], [
    AC_MSG_CHECKING([for MCA component $2:$3 compile mode])
    $4="static"
    AC_MSG_RESULT([$$4])
])

# ------------------------------------------------
AC_DEFUN([MCA_ompi_hook_peanuts_CONFIG],[
    AC_CONFIG_FILES([ompi/mca/hook/peanuts/Makefile])

    $1
])
