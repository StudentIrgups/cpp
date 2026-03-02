#include "quadangle.h"

quadangle::quadangle(int a, int b, int c, int d, int A, int B, int C, int D) 
    : figure("Четырёхугольник", 4) {
    sides[0] = a;
    sides[1] = b;
    sides[2] = c;
    sides[3] = d;
    angels[0] = A;
    angels[1] = B;
    angels[2] = C;
    angels[3] = D;
}