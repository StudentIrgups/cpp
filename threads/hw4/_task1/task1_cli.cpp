#include <iostream>
#include "client.h"
#include <random>

int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> elem(50, 150);
    
    int n = 10;
    std::vector<int> vec(n);

    Client client;
    client.send_data();
    
    return 0;
}