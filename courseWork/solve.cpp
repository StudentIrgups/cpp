#include <iostream>
#include <fstream>
int toInt(std::string data);
int toInt(char data);
void massInit(std::string** arr, int n, int m);
std::string** create_two_dim_array(int n, int m);

int main() {
    std::ifstream inFile("in.txt");
    if (inFile.is_open()) {
        int n{}, m{};
        inFile >> n;
        inFile >> m;
        std::string** mass = create_two_dim_array(n,m);
        massInit(mass, n, m);
        std::string s{};
         
         while (std::getline(inFile, s)) {
            if (s.length() == 3) {
                int i = toInt(s[0]) - 1, j = toInt(s[2]) - 1;
                mass[i][j] = "*";
            } 
        } 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << mass[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inFile.close();
    }
    return 0;
}

int toInt(std::string data) {
    int n = 0;
    for (int i = 0; i < data.length(); ++i) {
        n *= 10;
        n += data[i] - '0';        
    }
    return n;
}

int toInt(char data) {
    return data - '0';
}

void massInit(std::string** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = "-";
        }
    }
}

std::string** create_two_dim_array(int n, int m){
    std::string** arr = new std::string*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new std::string[m];
    }
    return arr;
}