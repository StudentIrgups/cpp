#include <iostream>

int main() {
	int mass[] = {2, 4, 32, 235, 5643, 1234, 34623, 34512345, 346,23,46, 0, -2, -1, -2};
	int size = sizeof(mass)/sizeof(mass[0]);
	std::cout << "Массив до сортировки: ";
	for (int i = 0; i < size; ++i) {
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i) {
		for (int j = i+1; j < size; ++j) {
			if (mass[i] > mass[j]) {
				int tmp = mass[j];
				mass[j] = mass[i];
				mass[i] = tmp;
			}
		}	
	}

	std::cout << "Массив после сортировки: ";
	for (int i = 0; i < size; ++i) {
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
