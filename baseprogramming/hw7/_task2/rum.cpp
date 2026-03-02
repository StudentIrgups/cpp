#include "rum.h"

rum::rum(int a, int b, int c, int d, int A, int B, int C, int D, int sideCount) : quadangle(a, b, c, d, A, B, C, D, sideCount) {
    _name = "Ромб";
    if ( a != c || a != b || a != d) {        
        throw badFigure("Ромб не создан! Стороны не равны");
    }  

    if (A != C || B != D) {        
        throw badFigure("Ромб не создан! Углы не равны попарно");
    }  
}