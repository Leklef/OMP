#include <iostream>
#include <omp.h>

#define SIZE 12

int main() {
    int a[SIZE], b[SIZE], c[SIZE];
    #pragma omp parallel for schedule(static, 2) num_threads(3)
    for (int i = 0; i < SIZE; i++) {
        a[i] = i * 3;
        b[i] = i * 4;
        printf("статическое, номер цикла %d, работает %d из %d потоков\n", i, omp_get_thread_num(), omp_get_num_threads());
    }

    #pragma omp parallel for schedule(dynamic, 2) num_threads(4)
    for (int i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
        printf("динамическое, номер цикла %d, работает %d из %d потоков\n", i, omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}