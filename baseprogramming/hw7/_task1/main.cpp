#include <iostream>
std::string toStr(int num);

class bad_length : public std::exception {
    public:
        virtual const char* what() const noexcept {
            return "Вы ввели слово запретной длины! До свидания";
        }
};

std::string getLength(std::string str, int forbiddenLength) {
    int len = str.length() / 2;
    if (len == forbiddenLength) { 
        throw bad_length();       
    }
    return "Длина слова \"" + str + "\" равна: " + toStr(len);
}

int main(void) {
    int forbiddenLength{0};
    std::cout << "Введите запретную длину: ";
    std::cin >> forbiddenLength;

    while (true) {
        try {
            std::cout << "Введите слово: ";
            std::string word{""};
            std::cin >> word;
            std::cout << getLength(word, forbiddenLength) << std::endl;
        } catch(const bad_length &ex) {
            std::cout << ex.what() << std::endl;
            break;
        }
    }
    
    return 0;
}

std::string toStr(int num) {
    std::string res{""};
    while (num !=0 ) {
        res += num % 10 + '0';
        num /= 10;
    }
    int len = res.length();
    for (int i = 0; i < len / 2; ++i) {
        char tmp = res[i];
        res[i] = res[len - i - 1];
        res[len - i - 1] = tmp;
    }
    return res;
}