#include "extended_array.h"
#include <cassert>
#include <sstream>
#include <string>

template <typename T, typename U>
void AssertEq(const T& valueA, const U& valueB) {
    std::ostringstream err;
    if (valueA != valueB) {        
        err << "Assertion failed: Сортировка не работает";
        throw std::runtime_error(err.str());
    }    
}

template <typename TestFunc>
void RunOneTest(TestFunc tfunc, const std::string& test_name) {
    try
    {
        tfunc();
        std::cerr << test_name << "OK" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
}

template <typename TestFunc>
void test_1(TestFunc tf, int* arr, int len, int* expected) {
    ExtArray<int> v(arr, len);
        
    int* data = v.data();    
    tf(data, len);

    // Копируем отсортированные данные обратно в arr
    for (int i = 0; i < len; ++i) {
        arr[i] = data[i];
    }
    
    AssertEq(v.isEqual(expected, len), true);
}

#include <functional>

void run_sort_test(const std::vector<int>& input, 
                   const std::vector<int>& expected, 
                   std::function<void(int*, int)> sort_func,
                   const std::string& algorithm_name = "сортировка") {
    int len = input.size();
    int* arr = new int[len];
    int* exp = new int[len];
    
    for (int i = 0; i < len; ++i) {
        arr[i] = input[i];
        exp[i] = expected[i];
    }
    
    RunOneTest(
        [&]() { 
            std::ostringstream name;
            name << "\nТест массива (" << algorithm_name << "):\n Input: ";
            for (int i = 0; i < len; ++i) 
                name << arr[i] << (i < len - 1 ? ", " : "\n");
            
            test_1(sort_func, arr, len, exp);
            
            std::cout << name.str() << "Output: ";
            for (int i = 0; i < len; ++i) 
                std::cout << arr[i] << (i < len - 1 ? ", " : "");
        },
        "\n everything is " 
    );
    
    delete[] arr;
    delete[] exp;
}

template <typename SortFunc>
void run_sort_test(const std::vector<int>& input, 
                   const std::vector<int>& expected, 
                   SortFunc sort_func) {
    run_sort_test(input, expected, sort_func, "сортировка");
}

