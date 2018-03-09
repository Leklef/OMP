#include <iostream>
#include <omp.h>
#include <math.h>

#define SIZE 30

int main() {
    int a[SIZE] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
    int x = 0;
    #pragma omp parallel for reduction(+: x) num_threads(4)
    for(int i = 0; i < SIZE; i++) {
        x += a[SIZE - 1 - i] * pow(2, i);
    }
    printf("%d", x);
    return 0;
}