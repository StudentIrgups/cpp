#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Введите имя: ";
    std::string firstName;
    std::cin >> firstName;

    std::cout << "Введите фамилию: ";
    std::string lastName;
    std::cin >> lastName;

    std::cout << "Здравствуйте, " + firstName + " " + lastName + '!' << std::endl;
    
    return 0;
}
