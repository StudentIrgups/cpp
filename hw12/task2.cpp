#include <iostream>
#include <fstream>
int toInt(std::string data) {
    int n = 0;
    for (int i = 0; i < data.length(); ++i) {
        n *= 10;
        n += data[i] - '0';        
    }
    return n;
}
int main(int argc, char** argv)
{
    std::ifstream file("in_mass.txt");
    if (file.is_open()) {
        std::string data{};
        file >> data;
        int n = toInt(data);
        
        int mass[n] {};
        while (file >> data) {
            if (n < 0) break;
            mass[n-1] = toInt(data);
            n -= 1;
        }        
        file.close();
        for (int i = 0; i < sizeof(mass)/sizeof(mass[0]); ++i){
            std::cout << mass[i] << " ";
        }
        std::cout << std::endl;
    }    
}



