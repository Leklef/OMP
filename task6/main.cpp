#include <iostream>
#include <omp.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {10, 9, 8, 20, 6, 5, 30, 3, 40, 1};

    int sum_a = 0, sum_b = 0;

    #pragma omp parallel for reduction(+: sum_a) reduction(+: sum_b)
    for (int i = 0; i < 10; i++) {
        sum_a += a[i];
        sum_b += b[i];
    }

    if (sum_a > sum_b) {
        printf("среднее арифметическое массива 'a' больше, sum_a = %d, sum_b = %d\n", sum_a / 10, sum_b / 10);
    } else {
        if (sum_a < sum_b) {
            printf("среднее арифметическое массива 'b' больше, sum_a = %d, sum_b = %d\n", sum_a / 10, sum_b / 10);
        } else {
            printf("среднее арифметическое массивов 'a' и 'b' равны, sum_a = %d, sum_b = %d\n", sum_a / 10, sum_b / 10);
        }
    }

    return 0;
}