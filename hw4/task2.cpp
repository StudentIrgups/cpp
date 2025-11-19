#include <iostream>

int main() {
    std::cout << "Введите целое число: ";
    int num{};
    std::cin >> num;

    int sum{};
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    std::cout << "Сумма цифр: " << sum << "\n\n\n";

    return 0;
}