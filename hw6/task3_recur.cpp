#include <iostream>
long long fib(int n) {
	if (n == 0) 
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib(n-1) + fib(n-2);
}		
int main () {	
	std::cout << "Введите число: ";
	int n = 0;
	std::cin >> n;
	std::cout << "Числа Фибоначчи: " << 0 << " ";	
	for (int i = 1; i < n; ++i)
		std::cout << fib(i) << " ";
	std::cout << std::endl;
	return 0;
}
