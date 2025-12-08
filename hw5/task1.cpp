#include <iostream>

int main() {
	int mass[] = {2,3,7,1,34,87,2,6,9,11};
	int size = sizeof(mass)/sizeof(mass[0]);

	for (int i = 0; i < size; ++i) {
		if (size == i+1)
			std::cout << mass[i] << std::endl;
		else
			std::cout << mass[i] << ", ";
	}
    return 0;
}
