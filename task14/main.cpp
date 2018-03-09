#include <iostream>
#include <omp.h>

int square (int x)
{
    int res = 0;
    #pragma omp parallel for reduction(+: res) num_threads(4)
    for (int j = 0; j < x; j++) {
        res += x;
    }
    return res;
}

int main()
{
    printf("%d\n", square(210));
    return 0;
}