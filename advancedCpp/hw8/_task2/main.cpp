#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class big_integer {
private:
    std::vector<int> digits; // Цифры числа в обратном порядке (младший разряд в начале)
    
    void remove_leading_zeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }
    
public:    
    big_integer(const std::string& str) {
        for (int i = str.size() - 1; i >= 0; --i) {
            digits.push_back(str[i] - '0');
        }
        remove_leading_zeros();
    }
        
    big_integer() : digits{0} {}
        
    big_integer(const big_integer& other) : digits(other.digits) {}
        
    big_integer(big_integer&& other) noexcept : digits(std::move(other.digits)) {}
    
    big_integer& operator=(const big_integer& other) {
        if (this != &other) {
            digits = other.digits;
        }
        return *this;
    }
    
    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }
    
    big_integer operator+(const big_integer& other) const {
        big_integer result;
        result.digits.clear();
        
        int carry = 0;
        size_t max_size = std::max(digits.size(), other.digits.size());
        
        for (size_t i = 0; i < max_size || carry; ++i) {
            int sum = carry;
            if (i < digits.size())
                sum += digits[i];
            
            if (i < other.digits.size()) 
                sum += other.digits[i];
            
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        
        result.remove_leading_zeros();
        return result;
    }
    
    big_integer operator*(int num) const {
        if (num == 0) return big_integer("0");
        
        big_integer result;
        result.digits.clear();
        
        int carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            long long product = carry;
            if (i < digits.size()) 
                product += static_cast<long long>(digits[i]) * num;
            
            result.digits.push_back(product % 10);
            carry = product / 10;
        }
        
        result.remove_leading_zeros();
        return result;
    }
        
    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }
};

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << std::endl;
    
    auto product = number1 * 3;
    std::cout << product << std::endl; 
    
    auto number3 = std::move(number1);
    std::cout << number3 << std::endl;     
    return 0;
}