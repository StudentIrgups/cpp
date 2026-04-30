#include "dijkstra.h"

void dijkstra(int ** graph, int n, int s, int * done) {
    int32_t * d = new int[n];
    for (int i = 0; i < n; ++i) {
        d[i] = INT32_MAX;
    }
    d[s] = 0;
    heap * hp = new heap();    
    int size = n;
    heap::vw new_item{s, d[s]};
    hp->add(new_item);

    while (size-- > 0) {
        int curr = hp->extract_min();
        if (curr < 0) continue;

        for (int v = 0; v < n; ++v) {
            if (graph[curr][v] == 0) continue;
            if (d[curr] + graph[curr][v] < d[v]) {
                d[v] = d[curr] + graph[curr][v];
                heap::vw new_item{v, d[v]};
                hp->add(new_item);
            }
        }
        done[curr] = d[curr];
    }

    delete[] d;
    delete hp;
}