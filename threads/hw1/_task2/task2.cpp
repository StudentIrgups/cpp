#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
#include <string>

void sum_chunk(const std::vector<int>& a, const std::vector<int>& b,
               size_t start, size_t end, long long& result) {
    long long sum = 0;
    for (size_t i = start; i < end; ++i) {
        sum += static_cast<long long>(a[i]) + b[i];
    }
    result = sum;
}

long long parallel_sum(const std::vector<int>& a, const std::vector<int>& b, 
                       int num_threads) {
    size_t parts = num_threads;
    size_t chunk_size = a.size() / parts;
    
    std::vector<long long> results(parts, 0);
    std::vector<std::thread> threads;
    
    for (size_t i = 0; i < parts; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == parts - 1) ? a.size() : start + chunk_size;
        
        threads.push_back(std::thread([&, i, start, end]() {
            sum_chunk(a, b, start, end, results[i]);
        }));
    }
    
    for (auto& t : threads) t.join();
    
    long long total = 0;
    for (long long r : results) total += r;
    return total;
}

int main() {
    std::vector<size_t> sizes = {1000, 10000, 100000, 1000000};
    std::vector<int> thread_counts = {1, 2, 4, 8, 16};
    
    std::cout << "Количество аппаратных ядер - " 
              << std::thread::hardware_concurrency() << std::endl << std::endl;
    
    std::cout << std::setw(16) << "";
    for (size_t size : sizes) {
        std::cout << std::setw(15) << size;
    }
    std::cout << std::endl;
    
    for (int threads : thread_counts) {
        std::cout << std::setw(2) << threads << " потоков";
        if (threads == 1) std::cout << " ";
        
        for (size_t size : sizes) {
            std::vector<int> a(size, 1);
            std::vector<int> b(size, 2);
            
            auto start = std::chrono::high_resolution_clock::now();
            parallel_sum(a, b, threads);
            auto end = std::chrono::high_resolution_clock::now();
            
            std::chrono::duration<double> elapsed = end - start;
            
            std::cout << std::setw(15) << std::fixed << std::setprecision(7) 
                      << elapsed.count() << "s";
        }
        std::cout << std::endl;
    }
    
    return 0;
}