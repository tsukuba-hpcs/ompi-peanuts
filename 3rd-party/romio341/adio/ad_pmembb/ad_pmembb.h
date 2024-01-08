#ifndef AD_PMEMBB_H_INCLUDED
#define AD_PMEMBB_H_INCLUDED

#include "adio.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "rpmbb_c.h"
extern rpmbb_store_t ADIOI_PMEMBB_store;

void ADIOI_PMEMBB_InitColl(MPI_Comm comm, int *error_code);
void ADIOI_PMEMBB_Term(int *error_code);
void ADIOI_PMEMBB_Open(ADIO_File fd, int *error_code);
void ADIOI_PMEMBB_Close(ADIO_File fd, int *error_code);
void ADIOI_PMEMBB_ReadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                             int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                             int *error_code);
void ADIOI_PMEMBB_WriteContig(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                              int *error_code);
void ADIOI_PMEMBB_IwriteContig(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                               int *error_code);
void ADIOI_PMEMBB_IreadContig(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                              int *error_code);
int ADIOI_PMEMBB_ReadDone(ADIO_Request *request, ADIO_Status *status, int *error_code);
int ADIOI_PMEMBB_WriteDone(ADIO_Request *request, ADIO_Status *status, int *error_code);
void ADIOI_PMEMBB_ReadComplete(ADIO_Request *request, ADIO_Status *status, int *error_code);
void ADIOI_PMEMBB_WriteComplete(ADIO_Request *request, ADIO_Status *status, int *error_code);
void ADIOI_PMEMBB_Fcntl(ADIO_File fd, int flag, ADIO_Fcntl_t *fcntl_struct, int *error_code);
void ADIOI_PMEMBB_WriteStrided(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                               int *error_code);
void ADIOI_PMEMBB_ReadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                              int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                              int *error_code);
void ADIOI_PMEMBB_WriteStridedColl(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                   int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                   int *error_code);
void ADIOI_PMEMBB_ReadStridedColl(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                                  int file_ptr_type, ADIO_Offset offset, ADIO_Status *status,
                                  int *error_code);
void ADIOI_PMEMBB_IreadStrided(ADIO_File fd, void *buf, int count, MPI_Datatype datatype,
                               int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                               int *error_code);
void ADIOI_PMEMBB_IwriteStrided(ADIO_File fd, const void *buf, int count, MPI_Datatype datatype,
                                int file_ptr_type, ADIO_Offset offset, ADIO_Request *request,
                                int *error_code);
void ADIOI_PMEMBB_Flush(ADIO_File fd, int *error_code);
void ADIOI_PMEMBB_Resize(ADIO_File fd, ADIO_Offset size, int *error_code);
ADIO_Offset ADIOI_PMEMBB_SeekIndividual(ADIO_File fd, ADIO_Offset offset, int whence,
                                        int *error_code);
void ADIOI_PMEMBB_SetInfo(ADIO_File fd, MPI_Info users_info, int *error_code);
void ADIOI_PMEMBB_Get_shared_fp(ADIO_File fd, int size, ADIO_Offset *shared_fp, int *error_code);
void ADIOI_PMEMBB_Set_shared_fp(ADIO_File fd, ADIO_Offset offset, int *error_code);
void ADIOI_PMEMBB_Delete(const char *filename, int *error_code);

#endif /* AD_PMEMBB_H_INCLUDED */
