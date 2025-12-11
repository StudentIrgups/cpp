#include <iostream>

int main() {
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;

    long long x = 0, y = 1, nextx = 0;

    std::cout << "Числа Фибоначчи: ";

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            std::cout << x << " ";
            continue;
        }
        if (i == 2) {
            std::cout << y << " ";
            continue;
        }
        nextx = x + y;
        x = y;
        y = nextx;
        std::cout << nextx << " ";
    }
    std::cout << std::endl;
    return 0;
}