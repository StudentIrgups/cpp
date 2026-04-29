#include "main.h"

int main(void) {
    std::ifstream file_in("input.txt");
    if (file_in.is_open()) {
        int c{0};
        file_in >> c;
        while (c-- > 0) {
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
            int * order = new int[n]();
            int idx{0};

            while (!qu->is_empty()) {
                order[idx++] = qu->pop();
            }
            std::cout << "Топологический порядок вершин: ";
            for (int i = n-1; i > -1; --i) {
                std::cout << order[i] << " ";
            }            
            std::cout << std::endl;
            for (int i = 0; i < n; ++i) {
                delete[] graph[i];
            }
            delete[] graph;        
            delete qu;
            delete[] order;
        }
        file_in.close();
    }
    return 0;
}