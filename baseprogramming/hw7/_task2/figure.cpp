#include "figure.h"

figure::~figure(){}

std::string figure::get_name() const {
    return _name;
}

int figure::get_sidesCount() const {
    return sideCount;
}

const int* figure::get_sides() const {
    return sides;
}

const int* figure::get_angels() const {
    return angels;
}

bool figure::check() {
    return sideCount == 0;
}
