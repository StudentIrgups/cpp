#include "triangle.h"
  
triangle::triangle(int a, int b, int c, int A, int B, int C, int sideCount) 
    : figure("Треугольник", sideCount){
    if (A + B + C != 180) {
        throw badFigure("сумма углов не равна 180");
    }    
    sides[0] = a;
    sides[1] = b;
    sides[2] = c;
    angels[0] = A;
    angels[1] = B; 
    angels[2] = C;
};

bool triangle::check() {
    int sum{0};
    for (int i = 0; i < get_sidesCount(); ++i)
        sum += angels[i];
    return sideCount == 3  && sum == 180;
}