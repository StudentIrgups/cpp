#include <iostream>
float sum(int a, int b) {
	return (float) a + b;
}

float diff(int a, int b) {
	return (float) a - b;
}	

float multiplication(int a, int b) {
	return (float) a * b;
}

float division(int a, int b) {
	return (float) a / b;
}		

int main(int argc, char** argv)
{
	int a = 5, b = 10;

	int s = sum(a, b);
	int dif = diff(a, b);
	int mult = multiplication(a, b);
	double div = division(a, b);

	std::cout << a << " + " << b << " = " << s << std::endl;
	std::cout << a << " - " << b << " = " << dif << std::endl;
	std::cout << a << " * " << b << " = " << mult << std::endl;
	std::cout << a << " / " << b << " = " << div << std::endl;
	
	return 0;
}
