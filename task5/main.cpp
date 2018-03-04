#include <iostream>
#include <omp.h>

#define SIZE 30

int main() {
    int d[6][8];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % SIZE;
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            int elements = 0;
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    sum += d[i][j];
                    elements++;
                }
            }
            printf("среднее арифмитическое %.2f из %d потока\n", sum * 1.0 / elements, omp_get_thread_num());
        }

        #pragma omp section
        {
            int min = SIZE + 1;
            int max = -1;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (min > d[i][j]) {
                        min = d[i][j];
                    }
                    if (max < d[i][j]) {
                        max = d[i][j];
                    }
                }
            }
            printf("максимум - %d, минимум %d из %d потока\n", max, min, omp_get_thread_num());
        }

        #pragma omp section
        {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    if (d[i][j] % 3 == 0) {
                        sum += d[i][j];
                    }
                }
            }
            printf("сумма кратных чисел %d из %d потоков\n", sum, omp_get_thread_num());
        }
    }
    return 0;
}