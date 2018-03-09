#include <iostream>
#include <omp.h>
#include <random>

#define WIDTH 6
#define HEIGHT 8
#define RANDOM 30

int main() {
    int d[WIDTH][HEIGHT];
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            std::mt19937 gen { std::random_device()() };
            std::uniform_int_distribution<> uid(0, RANDOM);
            d[i][j] = uid(gen);
        }
    }

    int min = RANDOM + 1;
    int max = -1;

    int counter = 0;

    #pragma omp parallel for num_threads(6)
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (min > d[i][j]) {
                #pragma omp critical
                min = d[i][j];
            }
            if (max < d[i][j]) {
                #pragma omp critical
                max = d[i][j];
            }
        }
    }
    printf("максимум - %d, минимум - %d\n", max, min);

    return 0;
}