#include <iostream>

class figure {
    public:
        figure(const std::string& name, int count):_name(name), sideCount(count) {
            for (int i = 0; i < 4; ++i) {
                sides[i] = 0;
                angels[i] = 0;
            }
        }
        
        virtual ~figure(){}

        std::string get_name() const {
            return _name;
        }

        int get_sidesCount() const {
            return sideCount;
        }

        const int* get_sides() const {
            return sides;
        }

        const int* get_angels() const {
            return angels;
        }

    protected:
        std::string _name;
        int sides[4];
        int angels[4];
        int sideCount;
};

class triangle: public figure {       
    public:
        triangle(int a = 10, int b = 20, int c = 30, int A = 50, int B = 60, int C = 70) 
            : figure("Треугольник", 3){
            sides[0] = a;
            sides[1] = b;
            sides[2] = c;
            angels[0] = A;
            angels[1] = B; 
            angels[2] = C;
        }
};

class rightTriangle : public triangle {
        public:
        rightTriangle() : triangle(11, 22, 33, 50, 60, 90) {
            _name = "Прямоугольный треугольник";
        }
};

 class isoscelesTriangle : public triangle {
        public:
        isoscelesTriangle() : triangle(10, 20, 30, 50, 60, 50 ) {
            _name = "Равнобедренный треугольник";
        }
};

class equilateralTriangle : public triangle {
        public:
        equilateralTriangle () : triangle(30, 30, 30, 60, 60, 60) {
            _name = "Равносторонний треугольник";
        }
};

class quadangle : public figure {    
    public:
        quadangle(int a = 10, int b = 20, int c = 30, int d = 40, int A = 50, int B = 60, int C = 70, int D = 80) 
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
};

class rectangle : public quadangle {    
    public:
        rectangle() : quadangle(10,  20, 10, 20, 90, 90, 90, 90) {
            _name = "Прямоульник";
        }
};

class square : public quadangle {    
    public:
        square() : quadangle(20, 20, 20, 20, 90, 90, 90, 90) {
            _name = "Квадрат";
        }
};

class parallelogram : public quadangle {    
    public:
        parallelogram() : quadangle(20, 40, 20, 40, 50, 60, 50, 60) {
            _name = "Параллелограмм";
        }
};

class rum : public quadangle {    
    public:
        rum() : quadangle(40, 40, 40, 40, 50, 60, 50, 60) {
            _name = "Ромб";
        }
}; 

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
    figure* instances[20] = {nullptr};

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
        print_info(instances[i]);
    }
    for (int i = 0; i < now; ++i){
        if (instances[i] != nullptr) {
            delete instances[i];
            instances[i] = nullptr;
        }
    }
    return 0;
}