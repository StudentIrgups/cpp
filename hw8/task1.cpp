#include <iostream>

void counting_function();

int main(int argc, char** argv)
{
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}

void counting_function() {
	static int count = 0;
	count += 1;
	std::cout << "Количество вызовов функции counting_function(): " << count << std::endl;
}