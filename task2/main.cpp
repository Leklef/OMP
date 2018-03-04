#include <iostream>
#include <omp.h>

void task1()
{
    #pragma omp parallel num_threads(3)
    {
        #pragma omp parallel num_threads(3) if(omp_get_num_threads() > 1)
        {
            printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
        }
    }
}

void task2() {
    #pragma omp parallel num_threads(1)
    {
        #pragma omp parallel num_threads(1) if(omp_get_num_threads() > 1)
        {
            printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
        }
    }
}

int main() {
    #pragma omp parallel sections num_threads(8)
    {
        #pragma omp section
        {
            task1();
        }

        #pragma omp section
        {
            task2();
        }
    }
    return 0;
}