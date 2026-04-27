#include "main.h"

int main(void) {
    std::string sig{""};
    do {
        std::cout << "Введите строку: ";
        std::cin >> sig;
        std::cout << "Наивный хэш строки " << sig << " = " << simple_string_hash(sig) << std::endl;
    } while (sig != "exit");
    return 0;
}