#include "dfs.h"

void dfs(int ** graph, int vertex, bool * visited, int n, _queue * qu) {
    qu->push(vertex+1);
    
    visited[vertex] = true;
    for (int v = 0; v < n;  ++v) {
        if (graph[v][vertex] == 1 && !visited[v])
            dfs(graph, v, visited, n, qu);            
    }
}

void dfs(int ** graph, int n, _queue * qu) {
    bool * visited = new bool[n]{false};

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs(graph, v, visited, n, qu);
        }
    }
    delete[] visited;
}