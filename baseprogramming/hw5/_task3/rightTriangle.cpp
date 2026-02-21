#include "rightTriange.h"

rightTriangle::rightTriangle() {
    _a = 11;
    _b = 22;
    _c = 33;
    _A = 30;
    _B = 59; 
    _C = 91;
    _cSides = 3;
    _name = "Прямоугольный треугольник: ";
}
void rightTriangle::print_info () {            
    triangle::print_info();
}  
bool rightTriangle::check() {
    return triangle::check() && _C == 90;
}