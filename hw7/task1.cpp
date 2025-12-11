#include <iostream>

int main(int argc, char** argv)
{
	int         _int{ 2141983731 };
	short       _short{ 32767 };
	long        _long{ 9187491 };
	long long   _longLong{ 18241846184 };
	float       _float{ 12112.1212 };
	double      _double{ 237127.12412 };
	long double _longDouble{ 2894712.83473984 };
	bool        _bool{ true };
	
	std::cout << "int: "         << &_int        << " " << sizeof(_int) << std::endl;
	std::cout << "short: "       << &_short      << " " << sizeof(_short) << std::endl;
	std::cout << "long: "        << &_long       << " " << sizeof(_long) << std::endl;
	std::cout << "long long: "   << &_longLong   << " " << sizeof(_longLong) << std::endl;
	std::cout << "float: "       << &_float      << " " << sizeof(_float) << std::endl;
	std::cout << "double: "      << &_double     << " " << sizeof(_double) << std::endl;
	std::cout << "long double: " << &_longDouble << " " << sizeof(_longDouble) << std::endl;
	std::cout << "bool: "        << &_bool       << " " << sizeof(_bool) << std::endl;


	return 0;
}
