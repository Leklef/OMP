#include <iostream>
#include <vector>

bool is_prime (int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int start;
    int end;
    std::cout << "Введите начало промежутка и нажмите Enter: ";
    std::cin >> start;
    std::cout << "Введите конец промежутка и нажмите Enter: ";
    std::cin >> end;
    if (end < start) {
        std::cout << "Неверный промежуток\n";
    } else {
        #pragma omp parallel for ordered schedule(dynamic) num_threads(4)
        for(int i = start; i <= end; i++) {
            if (is_prime(i))
            {
                #pragma omp ordered
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}