#include "figure.h"
#include "triangle.h"
#include "rightTriangle.h"
#include "isoscelesTriangle.h"
#include "equilateralTriangle.h"
#include "quadangle.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rum.h" 

void print_info(const figure* figure) {
    std::cout << figure->get_name() << ":" << std::endl;

    const int* sides = figure->get_sides();
    const int* angels = figure->get_angels();
    int count = figure->get_sidesCount();

    std::cout << "Стороны: ";
    for (int i = 0; i < count; ++i) {
        std::cout << sides[i];
        if (i < count - 1) std::cout << ", ";
    }

    std::cout << std::endl;

    std::cout << "Углы: ";
    for (int i = 0; i < count; ++i) {
        std::cout << angels[i];
        if (i < count - 1) std::cout << ", ";
    }
    std::cout << std::endl << std:: endl; 
}

int main(void){

    int now = 0;

    figure* instances[] = {
        new figure,
        new triangle(10, 20, 30, 50, 60, 70),
        new rightTriangle(11, 22, 33, 50, 60, 90),
        new isoscelesTriangle(10, 20, 30, 50, 60, 50 ),
        new equilateralTriangle(30, 30, 30, 60, 60, 60),
        new quadangle(10, 20, 30, 40, 50, 60, 70, 80),
        new rectangle(10,  20, 10, 20, 90, 90, 90, 90),
        new square(20, 20, 20, 20, 90, 90, 90, 90),
        new parallelogram(20, 40, 20, 40, 50, 60, 50, 60),
        new rum(40, 40, 40, 40, 50, 60, 50, 60) 
    };

    now = sizeof(instances) / sizeof(instances[0]);

    for (int i = 0; i < now; ++i) {
        print_info(instances[i]);
    }
    
    for (int i = 0; i < now; ++i) {
        if (instances[i] != nullptr) {  
            delete instances[i];
            instances[i] = nullptr;
        }
    }
    return 0;
}