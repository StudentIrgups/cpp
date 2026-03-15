#include "isoscelesTriangle.h"

 isoscelesTriangle::isoscelesTriangle() {
    _a = 10;
    _b = 20;
    _c = 30;
    _A = 50;
    _B = 60; 
    _C = 50;
    _cSides = 3;
    _name = "Равнобедренный треугольник: ";
}
void isoscelesTriangle::print_info () {
    triangle::print_info();
}  
bool isoscelesTriangle::check() {
    return triangle::check() && _A == _C && _a == _b;
}