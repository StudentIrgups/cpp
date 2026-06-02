#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class someFunctor {
    public:
        void operator()(T num) {
            if (num % 3 == 0) {
                this->_sum += num;
                this->_count += 1;
            }
        }
        T get_sum() const {
            return _sum;
        }
        T get_count() const {
            return _count;
        }
    private:
        T _sum;
        T _count;
};

int main() {
    
    std::vector<int> numbers = {4, 1, 3, 6, 25, 54};
    
    someFunctor<int> counter;
        
    counter = std::for_each(numbers.begin(), numbers.end(), counter);
    
    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}