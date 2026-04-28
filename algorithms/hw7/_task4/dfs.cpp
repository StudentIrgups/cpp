#include "dfs.h"

void dfs(int ** graph, int vertex, bool * visited, int n, int * comps) {

    visited[vertex] = true;
    for (int v = 0; v < n;  ++v) {
        if (graph[vertex][v] == 1) {
            if (!visited[v]) {
                comps[v] = comps[vertex];
                dfs(graph, v, visited, n, comps);                
            }         
        }
    }
}

void dfs(int ** graph, int n, int * comps) {
    int comp = 1;
    bool * visited = new bool[n]{false};

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            comps[v] = comp++;
            dfs(graph, v, visited, n, comps);            
        }        
    }
    delete[] visited;
}