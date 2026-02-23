#include <iostream>

class figure {    
    public:
        figure(){
            __cSides = 0;
            _name = "Фигура";
        }
        int get_cSides(){
            return __cSides;
        }
        std::string get_name(){
            return _name;
        }
    protected:
        int __cSides;
        std::string _name{""};
};

class triangle : public figure{
    public:
        triangle(){
            __cSides = 3;
            _name = "Треугольник";
        }
};

class quadrangle : public figure{
    public:
        quadrangle(){
            __cSides = 4;
            _name = "Четырёхугольник";
        }
};

int main(void) {
    figure figure;
    triangle triangle;
    quadrangle quadrangle;
    std::cout << "Количество сторон:" << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_cSides() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_cSides() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_cSides() << std::endl;
    return 0;
}