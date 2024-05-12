#ifndef AD_PEANUTS_H_INCLUDED
#define AD_PEANUTS_H_INCLUDED

#include "adio.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "peanuts_c.h"
extern peanuts_store_t mca_hook_peanuts_peanuts_store;

void ADIOI_PEANUTS_Open(ADIO_File fd, int *error_code);
void ADIOI_PEANUTS_OpenColl(ADIO_File fd, int rank, int access_mode, int *error_code);
void ADIOI_PEANUTS_Close(ADIO_File fd, int *error_code);
void ADIOI_PEANUTS_ReadAggregateContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                                       int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                       int *error_code);
void ADIOI_PEANUTS_ReadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                              int *error_code);
void ADIOI_PEANUTS_WriteContig(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                               int *error_code);
void ADIOI_PEANUTS_IwriteContig(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                                int *error_code);
void ADIOI_PEANUTS_IreadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                               int *error_code);
int ADIOI_PEANUTS_ReadDone(ADIO_Request *request, ADIO_Status *status, int *error_code);
int ADIOI_PEANUTS_WriteDone(ADIO_Request *request, ADIO_Status *status, int *error_code);
void ADIOI_PEANUTS_ReadComplete(ADIO_Request *request, ADIO_Status *status, int *error_code);
void ADIOI_PEANUTS_WriteComplete(ADIO_Request *request, ADIO_Status *status, int *error_code);
void ADIOI_PEANUTS_Fcntl(ADIO_File fd, int flag, ADIO_Fcntl_t *fcntl_struct, int *error_code);
void ADIOI_PEANUTS_WriteStrided(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                int *error_code);
void ADIOI_PEANUTS_ReadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                               int *error_code);
void ADIOI_PEANUTS_WriteStridedColl(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                    int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                    int *error_code);
void ADIOI_PEANUTS_ReadStridedColl(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                                   int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                   int *error_code);
void ADIOI_PEANUTS_IreadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                                int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                                int *error_code);
void ADIOI_PEANUTS_IwriteStrided(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                 int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                                 int *error_code);
void ADIOI_PEANUTS_Flush(ADIO_File fd, int *error_code);
void ADIOI_PEANUTS_Resize(ADIO_File fd, ADIO_Offset size, int *error_code);
ADIO_Offset ADIOI_PEANUTS_SeekIndividual(ADIO_File fd, ADIO_Offset offset, int whence,
                                         int *error_code);
void ADIOI_PEANUTS_SetInfo(ADIO_File fd, MPI_Info users_info, int *error_code);
void ADIOI_PEANUTS_Get_shared_fp(ADIO_File fd, int size, ADIO_Offset *shared_fp, int *error_code);
void ADIOI_PEANUTS_Set_shared_fp(ADIO_File fd, ADIO_Offset offset, int *error_code);
void ADIOI_PEANUTS_Delete(const char *filename, int *error_code);
int ADIOI_PEANUTS_Feature(ADIO_File fd, int flag);

#ifndef NDEBUG
#    define DEBUG_PRINT(comm, msg)                                              \
        do {                                                                    \
            int myrank, nprocs;                                                 \
            MPI_Comm_size(comm, &nprocs);                                       \
            MPI_Comm_rank(comm, &myrank);                                       \
            FPRINTF(stdout, "[%d/%d] %s: %s\n", myrank, nprocs, __func__, msg); \
        } while (0)
#else
#    define DEBUG_PRINT(comm, filename) \
        do {                            \
        } while (0)
#endif

#endif /* AD_PEANUTS_H_INCLUDED */
