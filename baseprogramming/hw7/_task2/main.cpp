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

void print_info(figure* figure) {
    std::cout << figure->get_name() << ":" << std::endl;

    std::cout << (figure->check()?"Правильная":"Неправильная") << std::endl;

    const int* sides = figure->get_sides();
    const int* angels = figure->get_angels();
    int count = figure->get_sidesCount();

    std::cout << "Количество сторон: " << count << std::endl;

    if (count == 0) {
        std::cout << std::endl;
        return;
    }

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

void print_res(figure* figure) {
    const int* sides = figure->get_sides();
    const int* angels = figure->get_angels();
    int count = figure->get_sidesCount();
    std::cout << figure->get_name( ) << ". (Стороны: ";    

    for (int i = 0; i < count; ++i) {
        if (i == count - 1) {
            std::cout << sides[i] << "; ";            
        } else 
            std::cout << sides[i] << ", ";
    }
    std::cout << "Углы: ";    
    for (int i = 0; i < count; ++i) {
        if (i == count - 1) {
            std::cout << angels[i] << "). Создан" << std::endl;            
        } else 
            std::cout << angels[i] << ", ";
    }
}

int main(void){

    int now = 0;
    try {
        figure* instances[10] = {nullptr};
        instances[now++] =  new figure;
        instances[now++] =  new triangle(10, 20, 30, 50, 60, 70, 3);
        print_res(instances[now-1]);
        instances[now++] =  new rightTriangle(11, 22, 33, 30, 60, 90, 3);
        print_res(instances[now-1]);
        instances[now++] =  new isoscelesTriangle(30, 20, 30, 30, 120, 30, 3);
        print_res(instances[now-1]);
        instances[now++] =  new equilateralTriangle(30, 30, 30, 60, 60, 60, 3);
        print_res(instances[now-1]);
        instances[now++] =  new quadangle(10, 20, 30, 40, 50, 60, 70, 180, 4);
        print_res(instances[now-1]);
        instances[now++] =  new rectangle(10,  20, 10, 20, 90, 90, 90, 90, 4);
        print_res(instances[now-1]);
        instances[now++] =  new square(20, 20, 20, 20, 90, 90, 90, 90, 4);
        print_res(instances[now-1]);
        instances[now++] =  new parallelogram(20, 40, 20, 40, 50, 130, 50, 130, 4);
        print_res(instances[now-1]);
        instances[now++] =  new rum(40, 40, 40, 40, 45, 135, 45, 135, 4);
        print_res(instances[now-1]);

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
        } catch (badFigure &ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}