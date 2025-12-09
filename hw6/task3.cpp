#include <iostream>

int main() {
    int mass[3][6] = {
		{ 2, 5, -9, 213, 3, 1 },
		{ 3, 562, 36, 1, 0, 1 },
		{ 1, 12, 35, 215, 23, 99 }
	}; 
	int rows = sizeof(mass) / sizeof(mass[0]);
	int columns = sizeof(mass[0]) / sizeof(mass[0][0]);

	int max = -2147483648, min = 2147483647;
	int mini = 0, minj = 0, maxi = 0, maxj = 0;

	std::cout << "Массив: \n";

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (mass[i][j] > max) {
				max = mass[i][j];
				maxi = i;
				maxj = j;
			}
			if (mass[i][j] < min) {					
				min = mass[i][j];
				mini = i;
				minj = j;
			}
			std::cout << mass[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "Индекс минимального элемента: " << mini << " " << minj << std::endl;
	std::cout << "Индекс максммального элемента: " << maxi << " " << maxj << std::endl;
	return 0;
}
