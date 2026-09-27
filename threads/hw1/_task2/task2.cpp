#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <vector>
#include <random>
#include <execution>
using namespace std::chrono_literals;

void hardware_concurrency(){
    std::cout << "Количество аппаратных ядер - ";
    std::cout << std::thread::hardware_concurrency() << std::endl;
}
std::once_flag flag;

void func_thrd(std::vector<int> v1, std::vector<int> v2, int n) {
    std::call_once(flag, hardware_concurrency);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
        v1[i] += v2[i];
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    std::cout << time.count() << std::endl;
}

void create_random_vector(std::vector<int>& v, int n) {
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis(0,n);
    auto rand_num([=]() mutable {return dis(gen);});
    generate(v.begin(), v.end(), rand_num);
}

void parallel_split(
    const std::vector<int>& a, 
    const std::vector<int>& b, 
    int max_iterations, 
    std::function<void(
        const std::vector<int>&, 
        const std::vector<int>&, 
        size_t, 
        size_t
    )> processor) {
    
    for (int iter = 0; iter <= max_iterations; ++iter) {
        size_t parts = 1 << iter;
        size_t chunk_size = a.size() / parts;
        
        std::vector<int> results(parts, 0);
        std::vector<std::thread> threads;
        
        for (size_t i = 0; i < parts; ++i) {
            size_t start = i * chunk_size;
            size_t end = (i == parts - 1) ? a.size() : start + chunk_size;
            
            threads.push_back(std::thread([&, i, start, end]() {                
                processor(a, b, start, end);
            }));
        }
        
        for (auto& t : threads) {
            t.join();
        }
    }
}

int main() {
    const int n = 1000;
    std::vector<int> v1(n);
    std::vector<int> v2(n);
    create_random_vector(v1,n);
    create_random_vector(v2,n);

    auto processor = [](const std::vector<int>& a, const std::vector<int>& b, size_t start, size_t end) {
        std::vector<int> c(end);
        for (size_t i = start; i < end; ++i) 
            c[i] = a[i] + b[i];
    };

    parallel_split(v1, v2, 4, processor);

    //std::thread t(thrd);
    //t.join();

    return 0;
}