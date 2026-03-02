#include "quadangle.h"

quadangle::quadangle(int a, int b, int c, int d, int A, int B, int C, int D, int sideCount) 
    : figure("Четырёхугольник", sideCount) {
    if (sideCount != 4) {        
        throw badFigure("Четырёхугольник не создан! Количество сторон не 4");
    }  

    if (A + B + C + D != 360 ) {        
        throw badFigure("Четырёхугольник не создан! Сумма углов не 360");
    }  

    sides[0] = a;
    sides[1] = b;
    sides[2] = c;
    sides[3] = d;
    angels[0] = A;
    angels[1] = B;
    angels[2] = C;
    angels[3] = D;
}

bool quadangle::check(){
    return sideCount == 4;
}