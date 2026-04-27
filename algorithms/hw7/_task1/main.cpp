#include "main.h"

int main(void) {
    std::ifstream file_in("input.txt");
    if (file_in.is_open()) {
        int n{0};
        file_in >> n;
        
        int ** graphy = new int*[n];
        for (int i = 0; i < n; ++i) {
            graphy[i] = new int[n]();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                file_in >> graphy[i][j];
            }
        }
        _queue * qu = new _queue(n);
        dfs(graphy, n, qu);
        std::cout << "Порядок обхода вершин: ";
        for (int i = 0; i < n; ++i) {
            std::cout << qu->pop() << " ";
        }

        file_in.close();

        for (int i = 0; i < n; ++i) {
            delete[] graphy[i];
        }
        delete[] graphy;
        delete qu;
    }
    return 0;
}