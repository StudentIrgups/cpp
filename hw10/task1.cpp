#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Введите размер массива: ";
    int n{};
    std::cin >> n;
    int * ptrMass = new int[n];
    for (int i = 0; i < n; ++i) {
        int el{};        
        std::cout << "arr[" << i << "] = ";
        std::cin >> el;
        ptrMass[i] = el;
    }
    std::cout << "Введённый массив: ";
    for (int i = 0; i < n; ++i)
        std::cout << ptrMass[i] << " ";
    std::cout << std::endl;

    delete[] ptrMass;
    return 0;
}
