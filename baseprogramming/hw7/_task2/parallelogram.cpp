#include "parallelogram.h"

parallelogram::parallelogram(int a, int b, int c, int d, int A, int B, int C, int D, int sideCount) : quadangle(a, b, c, d, A, B, C, D, sideCount) {
    _name = "Параллелограмм";
    if ( a != c || b != d) {        
        throw badFigure("Параллелограмм не создан! Стороны не равны попарно");
    }  

    if (A != C || B != D ) {        
        throw badFigure("Параллелограмм не создан! Углы не равны попарно");
    }  
}