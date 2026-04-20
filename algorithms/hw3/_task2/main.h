#include "extended_array.h"
#include <cassert>
#include <sstream>
#include <string>
#include <functional>

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
void test(TestFunc tf, int* arr, int len, int* expected) {
    ExtArray<int> v(arr, len);
        
    int* data = v.data();    
    tf(data, len);

    // Копируем отсортированные данные обратно в arr
    for (int i = 0; i < len; ++i) {
        arr[i] = data[i];
    }
    
    AssertEq(v.isEqual(expected, len), true);
}

void print_array(const std::string& label, int* arr, int len) {
    std::cout << label;
    for (int i = 0; i < len; ++i) 
        std::cout << arr[i] << (i < len - 1 ? ", " : "");
    std::cout << std::endl;
}

template <typename SortFunc>
void run_sort_test(const std::vector<int>&        input, 
                   const std::vector<int>&        expected, 
                   SortFunc                       sort_func,
                   const std::string&             algorithm_name = "сортировка") {
    int len = input.size();
    int* arr = new int[len];
    int* exp = new int[len];
    
    for (int i = 0; i < len; ++i) {
        arr[i] = input[i];
        exp[i] = expected[i];
    }
    
    std::cout << "\nТест массива (" << algorithm_name << "):" << std::endl;
    print_array(" Input: ", arr, len);
    
    bool test_passed = true;
    std::string error_msg;
    
    try {
        test(sort_func, arr, len, exp);
    } catch (std::exception& e) {
        test_passed = false;
        error_msg = e.what();
    }
    
    print_array("Output: ", arr, len);
    
    if (test_passed) {
        std::cout << "Status: OK" << std::endl;
    } else {
        std::cout << "Status: FAIL - " << error_msg << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    
    delete[] arr;
    delete[] exp;
}
