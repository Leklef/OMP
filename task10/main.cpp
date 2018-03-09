#include <iostream>
#include <omp.h>

#define SIZE 30

int main() {
    int a[SIZE];
    for(int i = 0; i < SIZE; i++) {
        a[i] = rand() % SIZE;
    }

    int counter = 0;

    #pragma omp parallel for num_threads(6)
    for(int i = 0; i < SIZE; i++) {
        if(a[i] % 9 == 0) {
            #pragma omp atomic
            counter += 1;
        }
    }

    printf("Число кратных 9 чисел - %d", counter);
    return 0;
}