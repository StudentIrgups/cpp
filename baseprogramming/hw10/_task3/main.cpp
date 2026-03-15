#include <iostream>
#include "leaver.h"
#define EnterName "Введите имя: "

int main()
{   
    leaver_space::leaver oleaver;
    std::cout << EnterName;
    std::string name{""};
    std::cin >> name;
    std::cout << oleaver.leave(name) << std::endl;

	return 0;
}