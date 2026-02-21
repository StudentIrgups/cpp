#include "figure.h"
#include "triangle.h"
#include "rightTriange.h"
#include "isoscelesTriangle.h"
#include "equilateralTriangle.h"
#include "quadangle.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rum.h"

int main(void){

    int now = 0;

    figure* instances[20] = {nullptr};

    *(instances + now++) = new figure;
    *(instances + now++) = new triangle;
    *(instances + now++) = new rightTriangle;
    *(instances + now++) = new isoscelesTriangle;
    *(instances + now++) = new equilateralTriangle;
    *(instances + now++) = new quadangle;
    *(instances + now++) = new rectangle;
    *(instances + now++) = new square;
    *(instances + now++) = new parallelogram;
    *(instances + now++) = new rum; 

    for (int i = 0; i < now; ++i) {
        instances[i]->print_info();
        std::cout << std::endl;
    }

    for (int i = 0; i < 20; ++i) {
        if (instances[i] != nullptr) {  
            delete instances[i];
            instances[i] = nullptr;
        }
    }
    return 0;
}