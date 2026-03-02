#include "rectangle.h"

rectangle::rectangle(int a, int b, int c, int d, int A, int B, int C, int D, int sideCount) : quadangle(a, b, c, d, A, B, C, D, sideCount) {
    _name = "Прямоульник";

    if ( a != c || b != d) {        
        throw badFigure("Прямоульник не создан! Стороны не равны попарно");
    }  

    if (A != 90 || A != B || A != C || A != D ) {        
        throw badFigure("Прямоульник не создан! Не все углы 90 градусов");
    }  
}