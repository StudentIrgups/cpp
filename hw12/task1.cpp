#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream file("in.txt");
    if (file.is_open()) {
        std::string data{};
        while (file >> data) {
            std::cout << data << std::endl;
        }
        file.close();
    }    
    
    return 0;
}
