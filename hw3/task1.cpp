#include <iostream>

int main () {
    std::cout << "Operator: ||" << std::endl;

    std::cout << std::boolalpha;
    std::cout << "true"  << " true " << (true || true) << std::endl;
    std::cout << "false" << " true " << (false || true) << std::endl;
    std::cout << "true"  << " false " << (true || false) << std::endl;
    std::cout << "false" << " false " << (false|| false) << std::endl;

    std::cout << std::endl << "Operator: &&" << std::endl;
    std::cout << "true"  << " true " << (true && true) << std::endl;
    std::cout << "false" << " true " << (false && true) << std::endl;
    std::cout << "true"  << " false " << (true && false) << std::endl;
    std::cout << "false" << " false " << (false && false) << std::endl;

    return 0;
}