#include "ad_pmembb.h"

int ADIOI_PMEMBB_Feature(ADIO_File fd, int flag)
{
    switch (flag) {
        case ADIO_SCALABLE_RESIZE:
        case ADIO_TWO_PHASE:
            return 1;
            break;
        case ADIO_UNLINK_AFTER_CLOSE:
        case ADIO_LOCKS:
        case ADIO_SHARED_FP:
        case ADIO_ATOMIC_MODE:
        case ADIO_DATA_SIEVING_WRITES:
        case ADIO_SCALABLE_OPEN:
        default:
            return 0;
            break;
    }
}
