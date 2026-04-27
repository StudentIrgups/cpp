#include "main.h"

int main(void) {
    std::ifstream file_in("input.txt");
    if (file_in.is_open()) {
        int n{0};
        file_in >> n;
        
        int ** graph = new int*[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = new int[n]();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                file_in >> graph[i][j];
            }
        }
        _queue * qu = new _queue(n);
        dfs(graph, n, qu);
        std::cout << "Порядок обхода вершин: ";
        for (int i = 0; i < n; ++i) {
            std::cout << qu->pop() << " ";
        }

        file_in.close();

        for (int i = 0; i < n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;
        delete qu;
    }
    return 0;
}