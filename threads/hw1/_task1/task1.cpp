#include <thread>
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;

int max_clients = 10;
bool queue_exists = true;

void add() {
    int n = max_clients;
    while (n-->0) {
        max_clients++;
        std::cout << "Amount clients: " << max_clients << std::endl;
        std::this_thread::sleep_for(1s);
    }
    queue_exists = false;
}

void sub() {
    while (queue_exists || max_clients > 0) {
        max_clients--;
        std::cout << "After serve: " << max_clients << std::endl;
        std::this_thread::sleep_for(2s);
    }
}

int main() {
    std::thread clients(add);
    std::thread oper(sub);

    clients.join();
    oper.join();

    return 0;
}