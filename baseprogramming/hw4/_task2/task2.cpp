#include <iostream>

class figure {
    public:
        virtual void print_info() {
        }
};

class triangle: public figure {    
    public:
        triangle() {
            __a = 10;
            __b = 20;
            __c = 30;
            __A = 50;
            __B = 60; 
            __C = 70;
        }
        void print_info () override {
            std::cout << "Треугольник: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int __a, __b, __c, __A, __B, __C;
};

class rightTriangle : public triangle {
        public:
        rightTriangle() {
            __a = 10;
            __b = 20;
            __c = 30;
            __A = 50;
            __B = 60; 
            __C = 90;
        }
        void print_info () override {
            std::cout << "Прямоугольный треугольник: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << std::endl;
            std::cout << std::endl;
        }  
};

class isoscelesTriangle : public triangle {
        public:
        isoscelesTriangle() {
            __a = 10;
            __b = 20;
            __c = 30;
            __A = 50;
            __B = 60; 
            __C = 50;
        }
        void print_info () override {
            std::cout << "Равнобедренный треугольник: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << std::endl;
            std::cout << std::endl;
        }  
};

class equilateralTriangle : public triangle {
        public:
        equilateralTriangle () {
            __a = 30;
            __b = 30;
            __c = 30;
            __A = 60;
            __B = 60; 
            __C = 60;
        }
        void print_info () override {
            std::cout << "Равносторонний треугольник: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << std::endl;
            std::cout << std::endl;
        }  
};

class quadangle : public figure {    
    public:
        quadangle() {
            __a = 10;
            __b = 20;
            __c = 30;
            __d = 40;
            __A = 50;
            __B = 60; 
            __C = 70;
            __D = 80;
        }
        void print_info () override {
            std::cout << "Четырёхугольник: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << " d=" << __d << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << " D=" << __D << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int __a, __b, __c, __d, __A, __B, __C, __D;
};

class rectangle : public quadangle {    
    public:
        rectangle() {
            __a = 10;
            __b = 20;
            __c = 10;
            __d = 20;
            __A = 90;
            __B = 90; 
            __C = 90;
            __D = 90;
        }
        void print_info () override {
            std::cout << "Прямоульник: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << " d=" << __d << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << " D=" << __D << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int __a, __b, __c, __d, __A, __B, __C, __D;
};

class square : public quadangle {    
    public:
        square() {
            __a = 20;
            __b = 20;
            __c = 20;
            __d = 20;
            __A = 90;
            __B = 90; 
            __C = 90;
            __D = 90;
        }
        void print_info () override {
            std::cout << "Квадрат: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << " d=" << __d << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << " D=" << __D << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int __a, __b, __c, __d, __A, __B, __C, __D;
};

class parallelogram : public quadangle {    
    public:
        parallelogram() {
            __a = 20;
            __b = 40;
            __c = 20;
            __d = 40;
            __A = 50;
            __B = 60; 
            __C = 50;
            __D = 60;
        }
        void print_info () override {
            std::cout << "Параллелограмм: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << " d=" << __d << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << " D=" << __D << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int __a, __b, __c, __d, __A, __B, __C, __D;
};

class rum : public quadangle {    
    public:
        rum() {
            __a = 40;
            __b = 40;
            __c = 40;
            __d = 40;
            __A = 50;
            __B = 60; 
            __C = 50;
            __D = 60;
        }
        void print_info () override {
            std::cout << "Ромб: " << std::endl;
            std::cout << "Стороны: " << "a=" << __a << " b=" << __b << " c=" << __c << " d=" << __d << std::endl;
            std::cout << "Углы: " << "A=" << __A << " B=" << __B << " C=" << __C << " D=" << __D << std::endl;
            std::cout << std::endl;
        }        
    protected:
        int __a, __b, __c, __d, __A, __B, __C, __D;
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