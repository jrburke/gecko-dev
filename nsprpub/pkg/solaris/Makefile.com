#
# Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
# Use is subject to license terms.
#
#ident	"$Id: Makefile.com,v 1.7 2004/11/29 16:26:02 christophe.ravel.bugs%sun.com Exp $"
#

MACH = $(shell mach)

PUBLISH_ROOT = $(DIST)
ifeq ($(MOD_DEPTH),../..)
ROOT = ROOT
else
ROOT = $(subst ../../,,$(MOD_DEPTH))/ROOT
endif

PKGARCHIVE = $(dist_prefix)/pkgarchive
DATAFILES = copyright
FILES = $(DATAFILES) pkginfo

PACKAGE = $(shell basename `pwd`)

PRODUCT_VERSION = $(shell grep PR_VERSION $(dist_includedir)/prinit.h \
		   | sed -e 's/"$$//' -e 's/.*"//' -e 's/ .*//')

LN = /usr/bin/ln
CP = /usr/bin/cp

CLOBBERFILES = $(FILES)

include $(topsrcdir)/config/rules.mk

# vim: ft=make
