#include "triangle.h"
  
triangle::triangle(int a = 10, int b = 20, int c = 30, int A = 50, int B = 60, int C = 70) 
    : figure("Треугольник", 3){
    sides[0] = a;
    sides[1] = b;
    sides[2] = c;
    angels[0] = A;
    angels[1] = B; 
    angels[2] = C;
};

bool triangle::check(){
    return sideCount == 3;
}