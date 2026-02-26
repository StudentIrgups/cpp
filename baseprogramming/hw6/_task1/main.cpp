#include <iostream>
#define MODE 0
#ifndef MODE
    #error "Необходимо определить MODE"
#endif

#if MODE == 0
    #define MESSAGE "Работаю в режиме тренировки"
#elif MODE == 1
    #define MESSAGE "Работаю в боевом режиме"
    int add(int a, int b) {
        return a + b;
    }
#else
    #define MESSAGE "Неизвестный режим. Завершение работы"
#endif

int main(void) {
    std::cout << MESSAGE << std::endl;
    #if MODE == 1
        int a{0};
        std::cout << "Введите первое число: ";
        std::cin >> a;
        int b{0};
        std::cout << "Введите второе число: ";
        std::cin >> b;
        std::cout << "Результат сложения: " << add(a, b) << std::endl;
    #endif
    
    return 0;
}