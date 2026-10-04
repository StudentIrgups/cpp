#include <iostream>
#include <random>
#include <future>

int async_search(std::vector<int> vec, int min) {
    int imin = min;
    for (int i = imin + 1; i < vec.size(); ++i)
        imin = (vec[i] < vec[imin])?i:imin;
    return imin;
}

int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> elem(50, 150);
    
    int n = 10;
    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
        vec[i] = elem(gen);

    for (int i = 0; i < n; ++i) {
        int min = i;
        min = std::async(async_search, vec, min).get();
        std::swap(vec[i],vec[min]);
    }

    for (auto e:vec) {
        std::cout << e << " ";
    }
    
    return 0;
}