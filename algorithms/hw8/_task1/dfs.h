#pragma once 
#include <iostream>
#include "queue.h"
struct ways
{
    int size{0};
    _queue * qu;
};
void dfs(int ** graph, int vertex, bool * visited, int n, ways * ways_ver);
void dfs(int ** graph, int n, ways * ways_ver);