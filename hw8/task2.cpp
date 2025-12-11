#include <iostream>

namespace add {
	int calc(int a, int b) {		
		return a + b;
	};
}

namespace subtract {
	int calc(int a, int b) {		
		return a - b;
	};
}

namespace multiplay {
	int calc(int a, int b) {		
		return a * b;
	};
}

namespace division {
	int calc(int a, int b) {		
		return a / b;
	};
}

int main(int argc, char** argv)
{
	int x = 6, y = 9;
	std::cout << "x = " << x << " y = " << y << std::endl;
	std::cout << "Сложение: " << add::calc(x,y)<< std::endl;
	std::cout << "Вычитание: " << subtract::calc(x,y)<< std::endl;
	std::cout << "Умножение: " << multiplay::calc(x,y)<< std::endl;
	std::cout << "Деление: " << division::calc(x,y)<< std::endl;
	return 0;
}


