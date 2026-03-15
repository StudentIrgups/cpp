#include <iostream>
#include "greeter.h"
#define EnterName "Введите имя: "

int main()
{   
    greeter_space::greeter ogreeter;
    std::cout << EnterName;
    std::string name{""};
    std::cin >> name;
    std::cout << ogreeter.hello(name) << std::endl;

	return 0;
}