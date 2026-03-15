#include "quadangle.h"

quadangle::quadangle() {
    _a = 10;
    _b = 20;
    _c = 30;
    _d = 40;
    _A = 50;
    _B = 60; 
    _C = 70;
    _D = 80;
    _cSides = 4;
    _name = "Четырёхугольник: ";
}
void quadangle::print_info () {
    figure::print_info();
    std::cout << "Стороны: " << "a=" << _a << " b=" << _b << " c=" << _c << " d=" << _d << std::endl;
    std::cout << "Углы: " << "A=" << _A << " B=" << _B << " C=" << _C << " D=" << _D << std::endl;
} 
bool quadangle::check() {
    return _cSides == 4 && (_A + _B + _C + _D) == 360;
} 