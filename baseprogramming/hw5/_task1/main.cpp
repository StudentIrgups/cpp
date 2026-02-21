#include <iostream>
#include "math.h"

int main(void) {
    int a{0};
    std::cout << "Введите первое число: ";
    std::cin >> a;
    int b{0};
    std::cout << "Введите второе число: ";
    std::cin >> b;
    int oper{0};
    std::cout << "Введите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 возведение в степень): ";
    std::cin >> oper;

    switch (oper)
    {
    case 1:
        std::cout << a << " + " << b << " = " << add(a, b) << std::endl;
        break;
    case 2:
        std::cout << a << " - " << b << " = " << subtract(a, b) << std::endl;
        break;
    case 3:
        std::cout << a << " * " << b << " = " << multiply(a, b) << std::endl;
        break;        
    case 4:
        std::cout << a << " / " << b << " = " << division(a, b) << std::endl;
        break;        
    case 5:
        std::cout << a << " в степени " << b << " = " << power(a, b) << std::endl;
        break;        
    default:
        break;
    }
    return 0;
}