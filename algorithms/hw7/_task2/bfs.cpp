#include "bfs.h"

void bfs(int ** graph, int vertex, int n, _queue * qu) {
    bool * visited = new bool[n]{false};
    _queue * intQu = new _queue(n);

    for (int i = vertex; i < n; ++i) {
        if (!visited[i]) {            
            intQu->push(i);

            while (!intQu->is_empty()) {
                int next = intQu->pop();
                qu->push(next+1);

                visited[next] = true;
                
                for (int j = 0; j < n; ++j) {
                    if (graph[next][j] == 1 && !visited[j]) {
                        visited[j] = true;
                        intQu->push(j);
                    }
                }
            }
        }
    }

    delete[] visited;
    delete intQu;
}