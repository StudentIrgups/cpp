#include <iostream>
#include <set>
#include <vector>

int main() {
    int n = 0;
    std::cout << "[IN]\nВведите количество элементов: ";
    std::cin >> n;
    std::set<int> ms;
    for (int i = 0; i < n; ++i) {
        int e = 0;
        std::cout << "Введите " << i+1 << " элемент:";
        std::cin >> e;
        ms.insert(e);
    }
    std::cout << "\n[OUT]\n";
    std::vector<int> mv(ms.rbegin(),ms.rend());
    for (auto it:mv)
        std::cout << it << std::endl;
    return 0;
}