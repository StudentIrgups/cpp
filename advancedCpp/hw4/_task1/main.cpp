#include <iostream>
#include <vector>

template <typename T>
T power(T a) {
    return a * a;
}

template <>
std::vector<int> power(std::vector<int> a) {
    for (auto &it:a)
        it *= it;
    return a;
}

// Вспомогательная функция для вывода вектора
void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << power(5) << std::endl;
    printVector(power([]() { std::vector<int> a = {-1, 2, 3, 4}; return a;}()));
    return 0;
}