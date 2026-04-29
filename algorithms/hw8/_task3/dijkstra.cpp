#include "dijkstra.h"

void dijkstra(int ** graph, int n, int s) {
    int32_t * d = new int[n];
    for (int i = 0; i < n; ++i) {
        d[i] = INT32_MAX;
    }
    d[s] = 0;
    heap * hp = new heap();
    int * marked = new int[n]{0};
    int size = n;
    heap::vw new_item{s, d[s]};
    hp->add(new_item);

    while (size-- > 0) {
        int curr = hp->extract_min();

        for (int v = 0; v < n; ++v) {
            if (d[curr] + graph[curr][v] < d[v]) {
                d[v] = d[curr] + graph[curr][v];
                heap::vw new_item{v, d[v]};
                hp->add(new_item);
            }
        }
        marked[curr] = d[curr];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << marked[i] << " ";
    }
    std::cout << std::endl;

    delete[] d;
    delete hp;
    delete[] marked;
}