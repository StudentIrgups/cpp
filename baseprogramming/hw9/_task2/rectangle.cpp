#include "rectangle.h"

rectangle::rectangle() {
    _a = 10;
    _b = 20;
    _c = 10;
    _d = 20;
    _A = 90;
    _B = 90; 
    _C = 90;
    _D = 90;
    _cSides = 4;
    _name = "Прямоульник: ";
}
void rectangle::print_info () {
    quadangle::print_info();
} 
bool rectangle::check() {
    return quadangle::check() 
        && _A == 90 && _B == 90 && _C == 90 && _D == 90 
        && _a == _c && _b == _d;
}