#include <iostream>
#include "server.h"
#include <random>

int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> elem(50, 150);
    
    int n = 10;
    std::vector<int> vec(n);

    Server serv;
    serv.recieve_and_answer();
    
    return 0;
}