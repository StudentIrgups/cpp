#include <iostream>

class figure {
    public:
        virtual void print_info() {
            std::cout <<  _name << std::endl;
            std::cout << (check()?"Правильная":"Неправильная") << std::endl;
            std::cout << "Количество сторон: " << _cSides << std::endl;
        }
        virtual bool check() {
            return _cSides == 0;
        }
    protected:
        int _cSides = 0;
        std::string _name = "Фигура: ";
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
            _cSides = 3;
            _name = "Треугольник: ";
        }
        void print_info () override {
            figure::print_info();
            std::cout << "Стороны: " << "a=" << _a << " b=" << _b << " c=" << _c << std::endl;
            std::cout << "Углы: " << "A=" << _A << " B=" << _B << " C=" << _C << std::endl;
        }     
        bool check() override {
            return _cSides == 3 && (_A + _B + _C) == 180;
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
            _A = 30;
            _B = 59; 
            _C = 91;
            _cSides = 3;
            _name = "Прямоугольный треугольник: ";
        }
        void print_info () override {            
            triangle::print_info();
        }  
        bool check() override {
            return triangle::check() && _C == 90;
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
            _cSides = 3;
            _name = "Равнобедренный треугольник: ";
        }
        void print_info () override {
            triangle::print_info();
        }  
        bool check() override {
            return triangle::check() && _A == _C && _a == _b;
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
            _cSides = 3;
            _name = "Равносторонний треугольник: ";
        }
        void print_info () override {
            triangle::print_info();
        }  
        bool check() override {
            return triangle::check() && _A == _B && _B == _C && _a == _b && _b == _c;
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
            _cSides = 4;
            _name = "Четырёхугольник: ";
        }
        void print_info () override {
            figure::print_info();
            std::cout << "Стороны: " << "a=" << _a << " b=" << _b << " c=" << _c << " d=" << _d << std::endl;
            std::cout << "Углы: " << "A=" << _A << " B=" << _B << " C=" << _C << " D=" << _D << std::endl;
        } 
        bool check() override {
            return _cSides == 4 && (_A + _B + _C + _D) == 360;
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
            _cSides = 4;
            _name = "Прямоульник: ";
        }
        void print_info () override {
            quadangle::print_info();
        } 
        bool check() override {
            return quadangle::check() 
                && _A == 90 && _B == 90 && _C == 90 && _D == 90 
                && _a == _c && _b == _d;
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
            _cSides = 4;
            _name = "Квадрат: ";
        }
        void print_info () override {
            quadangle::print_info();
        }    
        bool check() override {
            return quadangle::check() 
                && _A == 90 && _B == _A && _C == _A && _D == _A
                && _a == _c && _b == _d && _a == _b;
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
            _cSides = 4;
            _name = "Параллелограмм: ";
        }
        void print_info () override {
            quadangle::print_info();
        } 
        bool check() override {
            return quadangle::check() 
                && _a == _c && _b == _d
                && _A == _C && _B == _D;
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
            _cSides = 4;
            _name = "Ромб: ";
        }
        void print_info () override {
            quadangle::print_info();
        }     
        bool check() override {
            return quadangle::check() 
                && _a == _c && _b == _d && _a == _b
                && _A == _C && _B == _D && _A == _B;
        }            
}; 

int main(void){

    int now = 0;
    figure* instances[20];

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
    delete[] instances[20];
    return 0;
}