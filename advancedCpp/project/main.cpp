#include <iostream>
#include "ini_parser.hpp"
using std::cout;
using std::endl;


int main(void) {
    
    ini_parser myParser;

    try {
        myParser.init("input.ini");
        std::cout << myParser.get_value<double>("section1.var1") << std::endl;
        std::cout << myParser.get_value<std::string>("section2.var2") << std::endl;
        std::cout << myParser.get_value<int>("section2.var1") << std::endl;
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}