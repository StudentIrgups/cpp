#include "dfs.h"

bool dfs(int ** graph, int vertex, bool * visited, int n, int prev) {

    visited[vertex] = true;
    for (int v = 0; v < n;  ++v) {
        if (graph[vertex][v] == 1) {
            if (!visited[v]) {
                if (dfs(graph, v, visited, n, vertex))
                    return true; 
            } else if(v != prev) {
                return true;
            }         
        }
    }
    return false;
}

bool dfs(int ** graph, int n) {
    bool * visited = new bool[n]{false};

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            if (dfs(graph, v, visited, n, -1)) {
                delete[] visited;
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}