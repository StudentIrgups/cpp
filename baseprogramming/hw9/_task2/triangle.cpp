#include "triangle.h"

triangle::triangle() {
    _a = 10;
    _b = 20;
    _c = 30;
    _A = 50;
    _B = 60; 
    _C = 70;
    _cSides = 3;
    _name = "Треугольник: ";
}
void triangle::print_info () {
    figure::print_info();
    std::cout << "Стороны: " << "a=" << _a << " b=" << _b << " c=" << _c << std::endl;
    std::cout << "Углы: " << "A=" << _A << " B=" << _B << " C=" << _C << std::endl;
}     
bool triangle::check() {
    return _cSides == 3 && (_A + _B + _C) == 180;
}       