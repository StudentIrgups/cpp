#include <iostream>
#define EnterName "Введите имя: "
#define Hello "Здравствуйте, "

int main()
{
    std::cout << EnterName << std::endl;
    std::string name{""};
    std::cin >> name;
    std::cout << Hello << name << "!" << std::endl;
	return 0;
}