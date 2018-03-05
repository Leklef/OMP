#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(3)
    {
        #pragma omp if(omp_get_num_threads() > 1)
        {
            if (omp_get_num_threads() > 1) {
                printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
            };
        }
    }
    #pragma omp parallel num_threads(1)
    {
        #pragma omp if(omp_get_num_threads() > 1)
        {
            if (omp_get_num_threads() > 1) {
                printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
            };
        }
    }
    return 0;
}