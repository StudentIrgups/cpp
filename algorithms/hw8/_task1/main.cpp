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
        ways * ways_ver = new ways[n]();

        dfs(graph, n, ways_ver);

        for (int i = 0; i < n; ++i) {
            std::cout << i + 1 << ": ";
            if (ways_ver[i].size == 0) {
                std::cout << "нет";
            } else {
                while (!ways_ver[i].qu->is_empty()) {
                    std::cout << ways_ver[i].qu->pop()+1 << " ";
                }
            }
            std::cout << std::endl;
            delete ways_ver[i].qu;
        }
        delete[] ways_ver;
        file_in.close();

        for (int i = 0; i < n; ++i) {
            delete[] graph[i];
        }
        delete[] graph;        
    }
    return 0;
}