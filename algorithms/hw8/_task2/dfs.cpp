#include "dfs.h"

void dfs(int ** graph, int vertex, bool * visited, int n, _queue * qu) {

    visited[vertex] = true;
    for (int v = 0; v < n;  ++v) {
        if (graph[vertex][v] == 1) {            
            if (!visited[v]) {                
                dfs(graph, v, visited, n, qu);                
            }         
        }
    }
    qu->push(vertex+1);
}

void dfs(int ** graph, int n, _queue * qu) {
    int comp = 1;
    bool * visited = new bool[n]{false};

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs(graph, v, visited, n, qu);            
        }        
    }
    delete[] visited;
}