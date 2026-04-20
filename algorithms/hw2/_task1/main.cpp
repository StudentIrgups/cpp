#include <iostream>

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibo(n-1) + fibo(n-2);
}

int main(void) {
    std::cout << "Введите число: ";
    int n{0};
    std::cin >> n;

    std::cout << "Ответ: " << fibo(n) << std::endl;

    return 0;
}