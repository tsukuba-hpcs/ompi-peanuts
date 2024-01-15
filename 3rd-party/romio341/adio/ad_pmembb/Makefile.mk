if BUILD_AD_PMEMBB

noinst_HEADERS += \
	adio/ad_pmembb/ad_pmembb.h \
	adio/ad_pmembb/rpmbb_c.h

romio_other_sources +=                \
    adio/ad_pmembb/ad_pmembb_close.c  \
    adio/ad_pmembb/ad_pmembb_read.c   \
    adio/ad_pmembb/ad_pmembb_rdcoll.c \
    adio/ad_pmembb/ad_pmembb_wrcoll.c \
    adio/ad_pmembb/ad_pmembb_open.c   \
    adio/ad_pmembb/ad_pmembb_write.c  \
    adio/ad_pmembb/ad_pmembb_done.c   \
    adio/ad_pmembb/ad_pmembb_fcntl.c  \
		adio/ad_pmembb/ad_pmembb_feature.c \
    adio/ad_pmembb/ad_pmembb_iread.c  \
    adio/ad_pmembb/ad_pmembb_iwrite.c \
    adio/ad_pmembb/ad_pmembb_wait.c   \
    adio/ad_pmembb/ad_pmembb_flush.c  \
    adio/ad_pmembb/ad_pmembb_seek.c   \
    adio/ad_pmembb/ad_pmembb_resize.c \
		adio/ad_pmembb/ad_pmembb_rpmbb_c.c \
    adio/ad_pmembb/ad_pmembb_hints.c  \
    adio/ad_pmembb/ad_pmembb_delete.c \
    adio/ad_pmembb/ad_pmembb.c

endif BUILD_AD_PMEMBB
