#include "square.h"

square::square() {
    _a = 20;
    _b = 20;
    _c = 20;
    _d = 20;
    _A = 90;
    _B = 90; 
    _C = 90;
    _D = 90;
    _cSides = 4;
    _name = "Квадрат: ";
}
void square::print_info () {
    quadangle::print_info();
}    
bool square::check() {
    return quadangle::check() 
        && _A == 90 && _B == _A && _C == _A && _D == _A
        && _a == _c && _b == _d && _a == _b;
}              