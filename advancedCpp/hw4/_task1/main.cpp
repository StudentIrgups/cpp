#include <iostream>
#include <vector>

template <typename T>
T power(T a) {
    return a * a;
}

template <typename T>
std::vector<T> power(std::vector<T> a) {
    for (auto &it:a)
        it *= it;
    return a;
}

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (T val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << power(5) << std::endl;
    printVector(power([]() { std::vector<int> a = {-1, 2, 3, 4}; return a;}()));
    return 0;
}