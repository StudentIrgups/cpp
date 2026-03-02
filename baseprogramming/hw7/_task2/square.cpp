#include "square.h"

square::square(int a, int b, int c, int d, int A, int B, int C, int D, int sideCount) : quadangle(a, b, c, d, A, B, C, D, sideCount) {
    _name = "Квадрат";

    if ( a != c || a != b || a != d) {        
        throw badFigure("Квадрат не создан! Стороны не равны");
    }  

    if (A != 90 || A != B || A != C || A != D ) {        
        throw badFigure("Квадрат не создан! Не все углы 90 градусов");
    }  
}