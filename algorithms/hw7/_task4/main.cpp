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
        int * comps = new int[n]();
        dfs(graph, n, comps);
        std::cout << "Принадлежность вершин компонентам связности: " << std::endl;
        int _max = 0;
        for (int i = 0; i < n; ++i) {
            std::cout << i + 1 << " - " << comps[i] << std::endl; 
            _max = std::max(comps[i], _max);
        }        
        std::cout << "Количество компонентов связности в графе: " << _max;
        file_in.close();

        for (int i = 0; i < n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;        
    }
    return 0;
}