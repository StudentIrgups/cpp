#include "dfs.h"

void dfs(int ** graph, int vertex, bool * visited, int n, ways * ways_ver) {

    visited[vertex] = true;
    for (int v = 0; v < n;  ++v) {
        if (graph[vertex][v] == 1) {
                
            ways_ver[vertex].size++;                
            _queue * new_qu = new _queue(ways_ver[vertex].size);

            while (ways_ver[vertex].qu != nullptr && !ways_ver[vertex].qu->is_empty())
                new_qu->push(ways_ver[vertex].qu->pop());
                
            new_qu->push(v);                
            delete ways_ver[vertex].qu;
            ways_ver[vertex].qu = new_qu;

            if (!visited[v]) {                
                dfs(graph, v, visited, n, ways_ver);                
            }         
        }
    }
}

void dfs(int ** graph, int n, ways * ways_ver) {
    int comp = 1;
    bool * visited = new bool[n]{false};

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            ways_ver[v].qu = new _queue(ways_ver[v].size);
            dfs(graph, v, visited, n, ways_ver);            
        }        
    }
    delete[] visited;
}