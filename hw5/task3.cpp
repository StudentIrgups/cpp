#include <iostream>

int main() {
    std::cout << "Введите целое число: ";
    int num{};
    std::cin >> num;
    for (int i = 1; i < 11; i++) {
        std::cout << i << " * " << num << " = " << i * num << std::endl;
    }
    std::cout << "\n\n";
    return 0;
}
