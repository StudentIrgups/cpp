#include <iostream>
class counter {
    int __var = 1;
    public:
        counter(){}
        counter(int var) {
            __var = var;
        }
        void inc(){
            ++__var;
        }
        void dec(){
            --__var;
        }
        int get_var() {
            return __var;
        }
};

int main(void) {    
    std::string ans;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";  
    std::cin >> ans;     
    counter* activeCntr = nullptr;
    counter cntr;     

    activeCntr = &cntr;
    if (ans == "да") {
        std::cout << "ВВведите начальное значение счётчика: ";
        int n = 0;
        std::cin >> n;
        
        activeCntr = new counter(n);
        ans = "";
    } else if(ans == "нет") {        
        ans = "";
    } else {
        std::cout << "Введено что-то некорректное. Выход..." << std::endl;
        ans = "x";
    } 

    if (ans != "x")
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> ans;
        
        if (ans == "+") {
            activeCntr->inc();
            ans = "";
        } else if (ans == "-") {
            activeCntr->dec();
            ans = "";
        } else if (ans == "=") {
            std::cout << activeCntr->get_var() << std::endl;
            ans = "";
        }
    } while (ans != "x");
    delete activeCntr;
    return 0;
}