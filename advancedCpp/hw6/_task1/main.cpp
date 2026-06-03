#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class ifEqual {
    public:
        ifEqual(int value) : _value(value) {}
        bool operator()(int other) const {
            return other == _value;        
        }
    private:
        int _value;
};

void onlyUnique(std::vector<int> &vec) {
    std::set<int> ms;
    for (auto it:vec)
        ms.insert(it);
    vec.clear();
    for (auto it:ms)
        vec.push_back(it);
};

int main() {
    std::vector<int> vec({1, 1, 2, 5, 6, 1, 2, 4});
    std::cout << "[IN]: ";

    auto print = [&vec](){ for (auto it:vec) std::cout << it << " "; std::cout << std::endl;};
    print();
    onlyUnique(vec);
    std::cout << "[OUT]: ";
    print();
    return 0;
}