#include <iostream>
#include <random>
#include <future>
#include <algorithm>
#include <vector>

template <typename Iter, typename Func>
void for_each_own(Iter beg, Iter end, Func func, int depth = 0) {
    auto size = end - beg;

    if (size <= 1000 || depth >= 4) {
        std::for_each(beg, end, func);
        return;
    }

    Iter mid = beg + size / 2;

    auto future = std::async(std::launch::async, for_each_own<Iter, Func>, beg, mid, func, depth + 1);

    for_each_own(mid, end, func, depth + 1);
    future.get();
}

int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> elem(50, 150);
    
    int n = 10;
    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
        vec[i] = elem(gen);

    for (auto e:vec) {
        std::cout << e << " ";
    }        

    std::cout << std::endl;
    
    for_each_own(vec.begin(), vec.end(), [](int &x) {
        x *= 2;
    });

    for (auto e:vec) {
        std::cout << e << " ";
    }
    
    
    return 0;
}