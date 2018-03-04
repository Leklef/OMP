#include <iostream>
#include <omp.h>

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int max = 10;
    int min = 0;

    #pragma omp parallel sections num_threads(2)
    {
        #pragma omp section
        {
            for (int i = 0; i < 10; i++) {
                if (min > a[i]) { min = a[i]; }
            }
        }

        #pragma omp section
        {
            for (int i = 0; i < 10; i++) {
                if (max < b[i]) { max = b[i]; }
            }
        }
    }

    printf("min is %d, max is %d\n", min, max);
    return 0;
}
