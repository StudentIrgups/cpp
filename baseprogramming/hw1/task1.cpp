#include <iostream>
enum class months {
    january,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    octorber,
    november,
    december,
};

int main (void){
    int n = 0;
    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> n;
        if (n < 0 || n > 12) {
            std::cout << "Введён не корректный номер" << std::endl;
            continue;
        }
        switch (n)
        {
        case static_cast<int>(months::january):
            std::cout << "Январь" << std::endl;
            break;
        case static_cast<int>(months::february):
            std::cout << "Февраль" << std::endl;
            break;
        case static_cast<int>(months::march):
            std::cout << "Март" << std::endl;
            break;
        case static_cast<int>(months::april):
            std::cout << "Апрель" << std::endl;
            break;
        case static_cast<int>(months::may):
            std::cout << "Май" << std::endl;
            break;
        case static_cast<int>(months::june):
            std::cout << "Июнь" << std::endl;
            break;
        case static_cast<int>(months::july):
            std::cout << "Июль" << std::endl;
            break;
        case static_cast<int>(months::august):
            std::cout << "Август" << std::endl;
            break;
        case static_cast<int>(months::september):
            std::cout << "Сентябрь" << std::endl;
            break;
        case static_cast<int>(months::octorber):
            std::cout << "Октябрь" << std::endl;
            break;
        case static_cast<int>(months::november):
            std::cout << "Ноябрь" << std::endl;
            break;
        case static_cast<int>(months::december):
            std::cout << "Декабрь" << std::endl;
            break;
        default:            
            break;
        }
    } while (n != 0);
    return 0;
}