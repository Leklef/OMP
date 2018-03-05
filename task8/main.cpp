#include <iostream>
#include <omp.h>

#define SIZE 10

void printVector(int c[]) {
    for(int i = 0; i < SIZE; i++) {
        std::cout << c[i];
        std::cout << " ";
    }
}

int main() {

    int a[SIZE][SIZE]; int b[SIZE]; int c[SIZE];

    for(int i = 0; i < SIZE; i++) {
        b[i] = i;
        for(int j = 0; j < SIZE; j++) {
            a[i][j] = i;
        }
    }

    double start = omp_get_wtime();
    for(int i = 0; i < SIZE; i++) {
        c[i] = 0;
        for(int j = 0; j < SIZE; j++) {
            c[i] = a[i][j] * b[j];
        }
    }
    double end = omp_get_wtime();
    double time = end - start;

    double parallel_start = omp_get_wtime();
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for schedule(dynamic, 4)
        for(int i = 0; i < SIZE; i++) {
            c[i] = 0;
            for(int j = 0; j < SIZE; j++) {
                c[i] = a[i][j] * b[j];
            }
        }
    }
    double parallel_end = omp_get_wtime();
    double parallel_time = parallel_end - parallel_start;

    printf("Последовательное время: %d, параллельное время: %d\n", time, parallel_time);
    printVector(c);

    return 0;
}