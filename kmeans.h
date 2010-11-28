/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*   File:         kmeans.h   (an OpenMP version)                            */
/*   Description:  header file for a simple k-means clustering program       */
/*                                                                           */
/*   Author:  Wei-keng Liao                                                  */
/*            ECE Department Northwestern University                         */
/*            email: wkliao@ece.northwestern.edu                             */
/*   Copyright, 2005, Wei-keng Liao                                          */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _H_KMEANS
#define _H_KMEANS

#include <assert.h>

#define msg(format, ...)    { fprintf(stderr, format, ##__VA_ARGS__); }
#define err(format, ...)    { fprintf(stderr, format, ##__VA_ARGS__); exit(1); }

#ifdef __CUDACC__
inline void checkCuda(cudaError_t e) {
    if (e != cudaSuccess) {
        err("CUDA Error: %s\n", cudaGetErrorString(e))
    }
}

inline void checkLastCudaError() {
    checkCuda(cudaGetLastError());
}
#endif

float** omp_kmeans(int, float**, int, int, int, float, int*);
float** seq_kmeans(float**, int, int, int, float, int*, int*);
float** cuda_kmeans(float**, int, int, int, float, int*, int*);

float** file_read(int, char*, int*, int*);
int     file_write(char*, int, int, int, float**, int*);


double  wtime(void);

extern int _debug;

#endif
