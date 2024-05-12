#
# Copyright (c) 2017      IBM Corporation.  All rights reserved.
# $COPYRIGHT$
#
# Additional copyrights may follow
#
# $HEADER$
#

sources = \
	hook_peanuts.h \
	hook_peanuts_component.c \
	hook_peanuts_fns.c

# This component will only ever be built statically -- never as a DSO.

noinst_LTLIBRARIES = libmca_hook_peanuts.la

libmca_hook_peanuts_la_SOURCES = $(sources)
libmca_hook_peanuts_la_LDFLAGS = -module -avoid-version
