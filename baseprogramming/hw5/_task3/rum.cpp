#include "rum.h"

rum::rum() {
    _a = 40;
    _b = 40;
    _c = 40;
    _d = 40;
    _A = 50;
    _B = 60; 
    _C = 50;
    _D = 60;
    _cSides = 4;
    _name = "Ромб: ";
}
void rum::print_info () {
    quadangle::print_info();
}     
bool rum::check() {
    return quadangle::check() 
        && _a == _c && _b == _d && _a == _b
        && _A == _C && _B == _D && _A == _B;
}            