#include "rightTriangle.h"

rightTriangle::rightTriangle(int a, int b, int c, int A, int B, int C, int sideCount) : triangle(a, b, c, A, B, C, sideCount) {
    _name = "Прямоугольный треугольник";
    if (C != 90) {
        throw badFigure("Прямоугольный треугольник не создан! C != 90");
    }  
}

bool rightTriangle::check() {
    bool f = false;
    for (int i = 0; i < get_sidesCount(); ++i)
        f = f == true || angels[i] == 90;
    return triangle::check() && f;
}