#include <iostream>

int main () {
    std::cout << "Enter sex: ";
    std::string sex{};
    std::cin >> sex;

    std::cout << "Enter sign of the zodiac: ";
    std::string zod{};
    std::cin >> zod;

    std::cout << "Enter age: ";
    int age{};
    std::cin >> age;

    if (age < 40 && (zod == "rack" || zod == "ryba" || zod == "vodoley") && sex == "m") 
        std::cout << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным." << std::endl;
    else if (age >=15 && age <= 30 && (zod == "telec" || zod == "deva" || zod == "kozerog") && sex == "j")
        std::cout << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок. Будет не только весело, но и интересно: найдётся дело, которое увлечёт всех." << std::endl;
    else
        std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)" << std::endl;
    return 0;
}