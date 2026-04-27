#include "main.h"

int main(void) {
     
    std::string sig{""};
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";        
    std::cin >> sig;
    std::string pattern{""};

    do {
        std::cout << "Введите подстроку, которую нужно найти: ";        
        std::cin >> pattern;
        int idx = find_substring_light_rabin_karp(sig, pattern);
        if (idx == -1)
            std::cout << "Подстрока " << pattern << " не найдена" << std::endl;
        else 
            std::cout << "Подстрока " << pattern << " найдена по индексу " << idx << std::endl;
    } while (pattern != "exit");
    return 0;
}