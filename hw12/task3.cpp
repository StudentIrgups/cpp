#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ofstream file("out_mass.txt");
    if (file.is_open()) {
        std::cout << "Введите размер массива: ";
        int data{};
        std::cin >> data;
        file << data << std::endl;

        int * mass = new int[data];
        for (int i = data-1; i > -1; --i) {
            std::cout << "a[" << data-(i+1) << "] = ";
            std::cin >> mass[i];
        }
        for (int i = 0; i < data; ++i)
            file << *(mass+i)  << " ";
        file.close();
        delete[] mass;
    }    
}



