#include <iostream>
#include <omp.h>

int main() {
    int a = 0, b = 0;

	printf("#before a:%d b:%d\n", a, b);

	#pragma omp parallel num_threads(2) private(a) firstprivate(b)
	{
		a = 0;
		a += omp_get_thread_num();
		b += omp_get_thread_num();
		printf("#during%d a:%d b:%d\n", omp_get_thread_num(), a, b);
	}
	printf("#after a:%d b:%d\n\n\n", a, b);

	#pragma omp parallel num_threads(4) shared(a) private(b)
	{
		b = 0;
		#pragma omp atomic
		a -= omp_get_thread_num();
		b -= omp_get_thread_num();
		printf("#during%d a:%d b:%d\n", omp_get_thread_num(), a, b);
	}
	printf("#after a:%d b:%d\n\n\n", a, b);
    return 0;
}