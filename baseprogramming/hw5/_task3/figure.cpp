#include "figure.h"

void figure::print_info(){
    std::cout <<  _name << std::endl;
    std::cout << (check()?"Правильная":"Неправильная") << std::endl;
    std::cout << "Количество сторон: " << _cSides << std::endl;
}

bool figure::check() {
    return _cSides == 0;
}