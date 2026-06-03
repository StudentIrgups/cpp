#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename T>
void print_container(T container) {
    for (auto it:container) 
        std::cout << it << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> mv({1, 4, 6, 2, 653, 1, 3});
    std::set<std::string> ms({"cat", "cat", "dog", "cow", "elephant", "eagle", "chicken"});
    std::list<float> ml({1.3, 345.6, 0.3, 0.123123, 0.1});

    print_container(mv);
    print_container(ms);
    print_container(ml);
    return 0;
}