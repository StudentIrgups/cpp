#include <iostream>

class figure {
    public:
        virtual void print_info() {
        }
    protected:
        std::string _name;
};

class triangle: public figure {       
    public:
        triangle() {
            _a = 10;
            _b = 20;
            _c = 30;
            _A = 50;
            _B = 60; 
            _C = 70;
            _name = "Треугольник: ";
        }
        void print_info () override {
            std::cout <<  _name << std::endl;
            std::cout << "Стороны: " << "a=" << _a << " b=" << _b << " c=" << _c << std::endl;
            std::cout << "Углы: " << "A=" << _A << " B=" << _B << " C=" << _C << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int _a, _b, _c, _A, _B, _C;
};

class rightTriangle : public triangle {
        public:
        rightTriangle() {
            _a = 11;
            _b = 22;
            _c = 33;
            _A = 50;
            _B = 60; 
            _C = 90;
            _name = "Прямоугольный треугольник: ";
        }
        void print_info () override {            
            triangle::print_info();
        }  
};

 class isoscelesTriangle : public triangle {
        public:
        isoscelesTriangle() {
            _a = 10;
            _b = 20;
            _c = 30;
            _A = 50;
            _B = 60; 
            _C = 50;
            _name = "Равнобедренный треугольник: ";
        }
        void print_info () override {
            triangle::print_info();
        }  
};

class equilateralTriangle : public triangle {
        public:
        equilateralTriangle () {
            _a = 30;
            _b = 30;
            _c = 30;
            _A = 60;
            _B = 60; 
            _C = 60;
            _name = "Равносторонний треугольник: ";
        }
        void print_info () override {
            triangle::print_info();
        }  
};

class quadangle : public figure {    
    public:
        quadangle() {
            _a = 10;
            _b = 20;
            _c = 30;
            _d = 40;
            _A = 50;
            _B = 60; 
            _C = 70;
            _D = 80;
            _name = "Четырёхугольник: ";
        }
        void print_info () override {
            std::cout << _name << std::endl;
            std::cout << "Стороны: " << "a=" << _a << " b=" << _b << " c=" << _c << " d=" << _d << std::endl;
            std::cout << "Углы: " << "A=" << _A << " B=" << _B << " C=" << _C << " D=" << _D << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int _a, _b, _c, _d, _A, _B, _C, _D;
};

class rectangle : public quadangle {    
    public:
        rectangle() {
            _a = 10;
            _b = 20;
            _c = 10;
            _d = 20;
            _A = 90;
            _B = 90; 
            _C = 90;
            _D = 90;
            _name = "Прямоульник: ";
        }
        void print_info () override {
            quadangle::print_info();
        } 
};

class square : public quadangle {    
    public:
        square() {
            _a = 20;
            _b = 20;
            _c = 20;
            _d = 20;
            _A = 90;
            _B = 90; 
            _C = 90;
            _D = 90;
            _name = "Квадрат: ";
        }
        void print_info () override {
            quadangle::print_info();
        }        
};

class parallelogram : public quadangle {    
    public:
        parallelogram() {
            _a = 20;
            _b = 40;
            _c = 20;
            _d = 40;
            _A = 50;
            _B = 60; 
            _C = 50;
            _D = 60;
            _name = "Параллелограмм: ";
        }
        void print_info () override {
            quadangle::print_info();
        } 
};

class rum : public quadangle {    
    public:
        rum() {
            _a = 40;
            _b = 40;
            _c = 40;
            _d = 40;
            _A = 50;
            _B = 60; 
            _C = 50;
            _D = 60;
            _name = "Ромб: ";
        }
        void print_info () override {
            quadangle::print_info();
        }        
}; 

int main(void){

    int now = 0;
    figure* instances[20];

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
    }
    delete[] instances[20];
    return 0;
}