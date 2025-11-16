#include <iostream>

int main () {
    int a {}, b{}, c{};
    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << "Enter third number: ";
    std::cin >> c;

    int first {
        a > b ? (a > c ? a : c) : (b > c ? b : c)
    };

    int third {
        a < b ? (a < c ? a : c) : (b < c ? b : c)      
    };

    int second {
        (a + b + c) - third - first
    };
    
    std::cout << "Result: " << first << " " << second << " " << third << std::endl;

    return 0;
}