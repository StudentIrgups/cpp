#include "equilateralTriangle.h"

equilateralTriangle::equilateralTriangle () {
    _a = 30;
    _b = 30;
    _c = 30;
    _A = 60;
    _B = 60; 
    _C = 60;
    _cSides = 3;
    _name = "Равносторонний треугольник: ";
}
void equilateralTriangle::print_info () {
    triangle::print_info();
}  
bool equilateralTriangle::check() {
    return triangle::check() && _A == _B && _B == _C && _a == _b && _b == _c;
}        