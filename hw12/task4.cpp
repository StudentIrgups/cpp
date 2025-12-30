#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream file("in_2Dmass.txt");
    if (file.is_open()) {
        int n{}, m{};
        file >> n;
        file >> m;
        int mass[n][m]{};
        int i = 0, j = 0;
        while (file >> mass[i][j]) {
            if (j == m - 1) {
                i += 1;
            }
            j += 1;
            j %= m;
        }
        std::cout << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = m - 1; j > -1; --j) {
                std::cout << mass[i][j] << " ";
            }
            std::cout << std::endl;
        }
        file.close();
    }    
}


