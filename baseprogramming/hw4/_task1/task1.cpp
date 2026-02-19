#include <iostream>

class figure {    
    public:
        figure(){
            __cSides = 0;
        }
        int get_cSides(){
            return __cSides;
        }
    protected:
        int __cSides;
};

class triangle : public figure{
    public:
        triangle(){
            __cSides = 3;
        }
};

class quadrangle : public figure{
    public:
        quadrangle(){
            __cSides = 4;
        }
};

int main(void) {
    figure figure;
    triangle triangle;
    quadrangle quadrangle;
    std::cout << "Количество сторон:" << std::endl;
    std::cout << "Фигура: " << figure.get_cSides() << std::endl;
    std::cout << "Треугольник: " << triangle.get_cSides() << std::endl;
    std::cout << "Четырёхугольник: " << quadrangle.get_cSides() << std::endl;
    return 0;
}