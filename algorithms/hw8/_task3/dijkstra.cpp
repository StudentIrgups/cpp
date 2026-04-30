#include "dijkstra.h"

void dijkstra(int ** graph, int n, int s, int * done) {
    int32_t * d = new int[n];
    for (int i = 0; i < n; ++i) {
        d[i] = INT32_MAX;
    }
    d[s] = 0;
    heap * hp = new heap();        
    hp->add({s, d[s]});
    bool* visited = new bool[n]{false};

    while (!hp->is_empty()) {
        int curr = hp->extract_min();
        if (curr == -1 || visited[curr]) continue;
        visited[curr] = true;
        done[curr] = d[curr];

        for (int v = 0; v < n; ++v) {
            if (graph[curr][v] == 0 || visited[v]) continue;

            // Защита от переполнения
            if (d[curr] == INT32_MAX) continue;

            if (d[curr] + graph[curr][v] < d[v]) {
                d[v] = d[curr] + graph[curr][v];                
                hp->add({v, d[v]});
            }
        }
        
    }

    delete[] d;
    delete hp;
    delete[] visited;
}