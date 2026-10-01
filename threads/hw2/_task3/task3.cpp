#include <iostream>
#include <mutex>
#include <string>

class Data {
public:
    int value;
    std::string name;
    std::mutex mtx;

    Data(int v = 0, const std::string& n = "") : value(v), name(n) {}
};

void swap_lock(Data& a, Data& b) {
    if (&a == &b) return;
    std::lock(a.mtx, b.mtx);
    std::swap(a.value, b.value);
    std::swap(a.name, b.name);
    a.mtx.unlock();
    b.mtx.unlock();
}

void swap_scoped(Data& a, Data& b) {
    if (&a == &b) return;
    std::scoped_lock lock(a.mtx, b.mtx);
    std::swap(a.value, b.value);
    std::swap(a.name, b.name);
}

void swap_unique(Data& a, Data& b) {
    if (&a == &b) return;
    std::unique_lock<std::mutex> la(a.mtx, std::defer_lock);
    std::unique_lock<std::mutex> lb(b.mtx, std::defer_lock);
    std::lock(la, lb);
    std::swap(a.value, b.value);
    std::swap(a.name, b.name);
}

int main() {
    Data a(1, "A");
    Data b(2, "B");

    swap_lock(a, b);
    std::cout << a.name << " " << a.value << " | " << b.name << " " << b.value << std::endl;

    swap_scoped(a, b);
    std::cout << a.name << " " << a.value << " | " << b.name << " " << b.value << std::endl;

    swap_unique(a, b);
    std::cout << a.name << " " << a.value << " | " << b.name << " " << b.value << std::endl;

    return 0;
}