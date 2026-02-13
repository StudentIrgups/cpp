#include <iostream>

struct  bankData {
    int kont;
    std::string name;
    float amount;
};

void changeAmount(bankData& data, float amount) {
    data.amount = amount;
}
int main(void) {

    bankData data;
    std::cout << "Введите счёт: ";
    std::cin >> data.kont;

    std::cout << "Введите имя: ";
    std::cin >> data.name;

    std::cout << "Введите сумму: ";
    std::cin >> data.amount;

    float amount = 0.0;
    std::cout << "Введите новую сумму: ";
    std::cin >> amount;

    changeAmount(data, amount);

    std::cout << "Ваш счёт: " << data.name << " " << data.kont << " " << data.amount << std::endl;


    return 0;
}