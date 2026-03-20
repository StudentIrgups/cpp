#include "extended_array.h"
#include <cassert>
#include <sstream>
#include <string>

template <typename T, typename U>
void AssertEq(const T& valueA, const U& valueB) {
    std::ostringstream err;
    if (valueA != valueB) {        
        err << "Assertion failed: " << valueA << " != " << valueB;
        throw std::runtime_error(err.str());
    }    
}

template <typename TestFunc>
void RunOneTest(TestFunc tfunc, const std::string& test_name) {
    try
    {
        tfunc();
        std::cerr << test_name << " OK" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
}

void test_mean() {
    ExtArray<int> v1{ };
    AssertEq(v1.mean(), 0);
}

void test_mean_1() {
    ExtArray<int> v2{ 1, 4, 4, -6, 6, 7 };
    AssertEq(v2.mean(2, 5), 2);
}

void test_median() {
    ExtArray<double> v2{ };
    AssertEq(v2.median(), 0);
}

void test_checkSum_double() {
    ExtArray<double> v1{ };
    AssertEq(v1.checkSum(), 0);
}

void test_checkSum_int() {
    ExtArray<int> v1{ };
    AssertEq(v1.checkSum(), 0);
}

void test_checkSum_bool() {
    ExtArray<bool> v1{ };
    AssertEq(v1.checkSum(), 0);
}

void test_checkSum_bool_noe() {
    ExtArray<bool> v1{ 0, 1, 0, 1, 1, 0};
    AssertEq(v1.checkSum(), 3);
}

void test_checkSum_int_exi2() {
    ExtArray<int> v1{ 0, 2, 0, 1, 1, 0};
    AssertEq(v1.checkSum(), 2);
}

void test_checkSum_int_ok() {
    ExtArray<int> v1{ 0, 1, 0, 1, 1, 0};
    AssertEq(v1.checkSum(), 3);
}

void test_mode() {
    ExtArray<int> v1{  };
    assert(v1.mode() == std::pair(0, 0));
    std::cout << "Mode test OK" << std::endl;
}

void RunAllTest() {
    RunOneTest(test_mean, "mean()");
    RunOneTest(test_mean_1, "mean(2,5)");
    RunOneTest(test_median, "median");
    RunOneTest(test_checkSum_double, "checkSum<double>");
    RunOneTest(test_checkSum_int, "checkSum<int>");
    RunOneTest(test_checkSum_bool, "checkSum<bool>");
    RunOneTest(test_checkSum_bool_noe, "checkSum[0, 1, 0, 1, 1, 0]");
    RunOneTest(test_checkSum_int_exi2, "checkSum[0, 2, 0, 1, 1, 0]");
    RunOneTest(test_checkSum_int_ok, "checkSum[0, 1, 0, 1, 1, 0]");
    test_mode();
}
