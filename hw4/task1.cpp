#include <iostream>

int main() {
    int num{0}, sum{0};
    do {
        sum += num;
        std::cout << "Введите целое число или число '0', чтобы закончить: ";        
        std::cin >> num;
    }
    while(num != 0);
    std::cout << sum << "\n\n\n";

    return 0;
}