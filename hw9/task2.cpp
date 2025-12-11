#include <iostream>

void swap(int* a, int* b);

int main(int argc, char** argv)
{
	int a = 5, b = 8;
	int *ptrA{ &a }, *ptrB{ &b };

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(ptrA, ptrB);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	return 0;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


