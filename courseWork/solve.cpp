#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("in.txt");
    if (inFile.is_open()) {
        int n{}, m{};
        inFile >> n;
        inFile >> m;
        std::string mass[n][m]{"-"};
        std::string s{};
         while (std::getline(inFile, s)) {
             if (s.length() == 3) {
                 int i = s[0] - 1, j = s[2] - 1;
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