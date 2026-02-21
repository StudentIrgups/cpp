#include "parallelogram.h"

parallelogram::parallelogram() {
    _a = 20;
    _b = 40;
    _c = 20;
    _d = 40;
    _A = 50;
    _B = 60; 
    _C = 50;
    _D = 60;
    _cSides = 4;
    _name = "Параллелограмм: ";
}
void parallelogram::print_info () {
    quadangle::print_info();
} 
bool parallelogram::check() {
    return quadangle::check() 
        && _a == _c && _b == _d
        && _A == _C && _B == _D;
}          
