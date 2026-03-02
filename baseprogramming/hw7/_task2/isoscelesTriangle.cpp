#include "isoscelesTriangle.h"

isoscelesTriangle::isoscelesTriangle(int a, int b, int c, int A, int B, int C, int sideCount) : triangle(a, b, c, A, B, C, sideCount) {
    _name = "Равнобедренный треугольник";
    if (a != c) {        
        throw badFigure("Равнобедренный треугольник не создан! Сторона а != с");
    }  
    if (A != C) {        
        throw badFigure("Равнобедренный треугольник не создан! Угол А != С");
    }  
}