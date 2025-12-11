#include <iostream>

double* createArray(int size);

int main(int argc, char** argv)
{
	std::cout << "Введите размер массива: ";
    int n{};
    std::cin >> n;
	double *mass = createArray(n);

    std::cout << "Массив: ";
    for (int i = 0; i < n; ++i)
        std::cout << mass[i] << " ";
	std::cout << std::endl;
	delete[] mass;
}

double* createArray(int size){
	return new double[size]();
}

