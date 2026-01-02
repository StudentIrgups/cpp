#include <iostream>
#include <fstream>
#include <unistd.h>
#include <algorithm>

int toInt(std::string data);
int toInt(char data);
void massInit(char** arr, int n, int m);
char** create_two_dim_array(int n, int m);
void delete_two_dim_array(char** arr, int n, int m);
void getStart(int n, int m, int &i, int &j, int &fi, int &fj);

int main() {
    std::ifstream inFile("in.txt");
    if (inFile.is_open()) {
        int n{}, m{};
        inFile >> n;
        inFile >> m;
        char** mass     = create_two_dim_array(n,m);
        char** mass_old = create_two_dim_array(n,m);
        massInit(mass, n, m);
        std::string s{};
         
        while (std::getline(inFile, s)) {
            if (s.length() == 3) {
                int i = toInt(s[0]), j = toInt(s[2]);
                mass[i][j] = '*';
            } 
        } 
        inFile.close();
        int index = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mass_old[i][j] = mass[i][j];
            }
        }
        bool sch = true;
        while (sch) {
            //std::system("clear");
            sch = false;

            int c_astr = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int si = i, sj = j;
                    int fi = 0, fj = 0;
                    getStart(n,m,si,sj, fi, fj);
                    //std::cout << si << ":" << fi << " " << sj << ":" << fj;
                    c_astr = 0;
                    for (int x = si; x < fi; ++x) {
                        for (int y = sj; y < fj; ++y) {
                            if (x == i && y == j) continue;
                            c_astr += (mass_old[x][y] == '*');
                        }
                    }
                    //std::cout << " " << c_astr << std::endl;
                    if ((c_astr == 3 || c_astr == 2) && mass_old[i][j] == '*') {}
                    else if (c_astr == 3 && mass_old[i][j] == '-') {
                        mass[i][j] = '*';
                    } else {
                        mass[i][j] = '-';                        
                    }
                    sch = (mass_old[i][j] != mass[i][j] || sch == true);
                }
            }
            c_astr = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    std::cout << mass_old[i][j] << " ";
                    c_astr += (mass_old[i][j] == '*');
                }
                std::cout << std::endl;
            }
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    mass_old[i][j] = mass[i][j];                    
                }
            }
            std::cout << "Generation: " <<  index << ". Alive cells: " << c_astr << std::endl;
            if (sch == false) {
                if (c_astr == 0) {
                    std::cout << "All cells are dead. Game over." << std::endl;
                } else {
                    std::cout << "The world has stagnated. Game over." << std::endl;
                }
            }
            index++;
            sleep(1);
        }
        delete_two_dim_array(mass,n,m);
        delete_two_dim_array(mass_old,n,m);        
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

void massInit(char** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = '-';
        }
    }
}

char** create_two_dim_array(int n, int m){
    char** arr = new char*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new char[m];
    }
    return arr;
}

void getStart(int n, int m, int &i, int &j, int &fi, int &fj) {
    i--;
    j--;

    if (i < 0) {
        i = 0;
        fi--;
    }
    if (j < 0) {
        j = 0;
        fj--;
    }
    //if (i == 4 && j == 0)
      //  std::cout << i << ":" << fi << " " << j << ":" << fj << std::endl;
    fi = i + 3 + fi;
    fj = j + 3 + fj;
    //if (i == 4 && j == 0)
       // std::cout << i << ":" << fi << " " << j << ":" << fj << std::endl;    
    if (fi > n)
        fi = n;
    if (fj > m)
        fj = m;
    //if (i == 4 && j == 0)
    //    std::cout << i << ":" << fi << " " << j << ":" << fj << std::endl;        
}

void delete_two_dim_array(char** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}