#include "equilateralTriangle.h"

equilateralTriangle::equilateralTriangle(int a, int b, int c, int A, int B, int C, int sideCount) : triangle(a, b, c, A, B, C, sideCount) {
    _name = "Равносторонний треугольник";
    if (a != c || a != b) {        
        throw badFigure("Равносторонний треугольник не создан! Стороны не равны");
    }  
    if (A != C || A != B) {        
        throw badFigure("Равносторонний треугольник не создан! Уголы не равны");
    }  
}