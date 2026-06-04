#include <iostream>
#include "ini_parser.hpp"
using std::cout;
using std::endl;


int main(void) {
    
    ini_parser myParser;

    try {
        myParser.init("input.ini");
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}