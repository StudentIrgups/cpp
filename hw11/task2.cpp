#include <iostream>

int main(int argc, char** argv)
{
    std::string word = "";
    do {
        if (word.length() > 0)
            std::cout << "Неправильно!" << std::endl;
        std::cout << "Угадайте слово: ";
        std::cin >> word;

    } while (word != "Арбуз");
    
    std::cout << "Правильно! Вы победили! Загаданное слово — " + word << std::endl;
}



