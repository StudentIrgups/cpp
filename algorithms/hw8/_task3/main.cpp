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
            dijkstra(graph, n, 4);
                     
            std::cout << std::endl;
            for (int i = 0; i < n; ++i) {
                delete[] graph[i];
            }
            delete[] graph;        
        }
        file_in.close();
    }
    return 0;
}