#include <iostream>

int my_pow(int value, int power) {
	int result = 1;
	for (int i = 0; i < power; ++i)
			result *= value;
	return result;
}

void print(int value, int power) {
	std::cout << value << " в степени " << power << " = " << my_pow(value, power) << std::endl;
}
int main() {
    print(5,2);
	print(3,3);
	print(4,4);
	return 0;
}
