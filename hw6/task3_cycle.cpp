#include <iostream>
int main () {
	std::cout << "Введите число: ";
	int n = 0;
	std::cin >> n;

	long long mass[n]{0};
	mass[1] = 1;
	for (int i = 2; i < n; ++i)
		mass[i] = mass[i-2] + mass[i-1];

	std::cout << "Числа Фибоначчи: ";
	for (int i = 0; i < n; ++i)
		std::cout << mass[i] << " ";
	std::cout << std::endl;
	return 0;
}
