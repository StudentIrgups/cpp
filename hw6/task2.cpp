#include <iostream>

int main() {
	int mass[] = {3, 5, -3, 4, 345, 1231, 236, 2332, 1123, 234, 6643};
	std::cout << "Массив: ";
	int size = sizeof(mass)/sizeof(mass[0]);
	int max =-2147483648, min = 2147483647;

	for (int i = 0; i < size; ++i) {
		std::cout << mass[i] << " ";
		if (mass[i] > max)
			max = mass[i];
		if (mass[i] < min)
			min = mass[i];
	}

	std::cout << std::endl << "Минимальный элемент: " << min << std::endl;
	std::cout << "Максимальный элемент: " << max << std::endl;

    return 0;
}
