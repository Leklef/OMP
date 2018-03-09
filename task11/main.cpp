#include <iostream>
#include <random>

#define SIZE 30

int main() {
    int a[SIZE];
    for(int i = 0; i < SIZE; i++) {
        std::mt19937 gen { std::random_device()() };
        std::uniform_int_distribution<> uid(0, SIZE);
        a[i] = uid(gen);
    }

    int max = 0;

    #pragma parallel for num_threads(6)
    for(int i = 0; i < SIZE; i++) {
        #pragma omp critical
        {
            if(a[i] % 7 == 0 && a[i] > max) {
                max = a[i];
            }
        }
    }

    printf("Максимальное число, кратное 7 - %d", max);

    return 0;
}