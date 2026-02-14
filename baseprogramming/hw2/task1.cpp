#include <iostream>

class calculator {
    double __num1;
    double __num2;
    public:
        double add(){
            return __num1 + __num2;
        }
        double multiply(){
            return __num1 * __num2;
        }
        double subtract_1_2(){
            return __num1 - __num2;
        }
        double subtract_2_1(){
            return __num2 - __num1;
        }
        double divide_1_2(){
            return __num1 / __num2;
        }
        double divide_2_1(){
            return __num2 / __num1;
        }
        bool set_num1(double num1) {
            if (num1 == 0)
                return false;
            __num1 = num1;
            return true;
        }
        bool set_num2(double num2) {
            if (num2 == 0)
                return false;
            __num2 = num2;
            return true;
        }
};

int main(void) {
    do{
        {
            calculator calc;
            int n = 0;
            do {
                std::cout << "Введите num1: ";
                std::cin >> n;

                if (!calc.set_num1(n)) {
                    std::cout << "Неверный ввод!" << std::endl;
                    continue;
                }
                n = 0;
                break;
            } while (true);

            do {
                std::cout << "Введите num2: ";
                std::cin >> n;

                if (!calc.set_num2(n)) {
                    std::cout << "Неверный ввод!" << std::endl;
                    continue;
                }
                n = 0;
                break;
            } while (true);        
            std::cout << "num1 + num2 = " << calc.add() << std::endl;
            std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
            std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
            std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
            std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
            std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
        }
    } while (true);
}