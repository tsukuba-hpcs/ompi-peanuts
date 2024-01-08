#
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

sources = \
	hook_pmembb.h \
	hook_pmembb_component.c \
	hook_pmembb_fns.c

# This component will only ever be built statically -- never as a DSO.

noinst_LTLIBRARIES = libmca_hook_pmembb.la

libmca_hook_pmembb_la_SOURCES = $(sources)
libmca_hook_pmembb_la_LDFLAGS = -module -avoid-version
