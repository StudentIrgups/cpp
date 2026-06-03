#include <iostream>
#include <vector>


template <typename T>
void move_vectors(std::vector<T>& from, std::vector<T>& to) {
    to = std::move(from);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << "Before move size of one is: " << one.size() << std::endl;
    std::cout << "Before move size of two is: " << two.size() << std::endl;
    move_vectors(one, two);
    
    std::cout << "Size of one after: " << one.size() << std::endl;
    std::cout << "Size of two after: : " << two.size() << std::endl;
    return 0;
}