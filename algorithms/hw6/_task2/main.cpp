#include "main.h"

int main(void) {
    std::string sig{""};
    std::cout << "Введите p: ";        
    int p{0};
    std::cin >> p;
    std::cout << "Введите n: ";        
    int n{0};
    std::cin >> n;    
    do {
        std::cout << "Введите строку: ";
        std::cin >> sig;
        std::cout << "Хэш строки " << sig << " = " << realHash(sig, p, n) << std::endl;
    } while (sig != "exit");
    return 0;
}