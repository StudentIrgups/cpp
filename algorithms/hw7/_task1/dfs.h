#pragma once 
#include <iostream>
#include "queue.h"

void dfs(int ** graphy, int vertex, bool * visited, int n, _queue * qu);
void dfs(int ** graphy, int n, _queue * qu);