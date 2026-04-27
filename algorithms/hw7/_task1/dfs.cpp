#include "dfs.h"

void dfs(int ** graphy, int vertex, bool * visited, int n, _queue * qu) {
    qu->push(vertex+1);
    
    visited[vertex] = true;
    for (int v = 0; v < n;  ++v) {
        if (graphy[v][vertex] == 1 && !visited[v])
            dfs(graphy, v, visited, n, qu);            
    }
}

void dfs(int ** graphy, int n, _queue * qu) {
    bool * visited = new bool[n]{false};

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs(graphy, v, visited, n, qu);
        }
    }
    delete[] visited;
}