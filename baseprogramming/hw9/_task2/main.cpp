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

int main(void){

    int now = 0;

    figure* instances[] = {
        new figure,
        new triangle,
        new rightTriangle,
        new isoscelesTriangle,
        new equilateralTriangle,
        new quadangle,
        new rectangle,
        new square,
        new parallelogram,
        new rum 
    };

    now = sizeof(instances) / sizeof(instances[0]);

    for (int i = 0; i < now; ++i) {
        instances[i]->print_info();
        std::cout << std::endl;
    }

    for (int i = 0; i < now; ++i) {
        if (instances[i] != nullptr) {  
            delete instances[i];
            instances[i] = nullptr;
        }
    }
    return 0;
}