#include <iostream>
#include "counter.h"

int main(void) {    
    std::string ans;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";  
    std::cin >> ans;     
    counter* activeCntr = nullptr;
    counter cntr;     

    activeCntr = &cntr;
    if (ans == "да") {
        std::cout << "ВВведите начальное значение счётчика: ";
        int n = 0;
        std::cin >> n;
        
        activeCntr = new counter(n);
        ans = "";
    } else if(ans == "нет") {        
        ans = "";
    } else {
        std::cout << "Введено что-то некорректное. Выход..." << std::endl;
        ans = "x";
        return 0;
    } 

    if (ans != "x")
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> ans;
        
        if (ans == "+") {
            activeCntr->inc();
            ans = "";
        } else if (ans == "-") {
            activeCntr->dec();
            ans = "";
        } else if (ans == "=") {
            std::cout << activeCntr->get_var() << std::endl;
            ans = "";
        }
    } while (ans != "x");
    delete activeCntr;
    return 0;
}