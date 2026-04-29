#pragma once 
#include <iostream>
#include "queue.h"

void dfs(int ** graph, int vertex, bool * visited, int n, _queue * qu);
void dfs(int ** graph, int n, _queue * qu);