#include "math.h"

int add (int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float division(int a, int b) {
    return static_cast<float>(a) / b;
}

int power(int a, int b) {
    int res{0};
    res = a;
    for (int i = 1; i < b; ++i) {
        res *= a;
    }
    return res;
}