if BUILD_AD_PEANUTS

noinst_HEADERS += \
	adio/ad_peanuts/ad_peanuts.h \
	adio/ad_peanuts/peanuts_c.h

romio_other_sources +=                \
    adio/ad_peanuts/ad_peanuts_close.c  \
    adio/ad_peanuts/ad_peanuts_read.c   \
    adio/ad_peanuts/ad_peanuts_rdcoll.c \
    adio/ad_peanuts/ad_peanuts_wrcoll.c \
    adio/ad_peanuts/ad_peanuts_open.c   \
    adio/ad_peanuts/ad_peanuts_write.c  \
    adio/ad_peanuts/ad_peanuts_done.c   \
    adio/ad_peanuts/ad_peanuts_fcntl.c  \
		adio/ad_peanuts/ad_peanuts_feature.c \
    adio/ad_peanuts/ad_peanuts_iread.c  \
    adio/ad_peanuts/ad_peanuts_iwrite.c \
    adio/ad_peanuts/ad_peanuts_wait.c   \
    adio/ad_peanuts/ad_peanuts_flush.c  \
    adio/ad_peanuts/ad_peanuts_seek.c   \
    adio/ad_peanuts/ad_peanuts_resize.c \
		adio/ad_peanuts/ad_peanuts_binding.c \
    adio/ad_peanuts/ad_peanuts_hints.c  \
    adio/ad_peanuts/ad_peanuts_delete.c \
    adio/ad_peanuts/ad_peanuts.c

endif BUILD_AD_PEANUTS
