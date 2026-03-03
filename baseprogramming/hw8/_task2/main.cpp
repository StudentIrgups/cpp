#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

    static int gcd(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    static std::string toStr(int num) {
        std::string res{""};
        int sign = 1;
        if (num < 0) {
            sign = -1;
            num *= sign;
        }
        while (num !=0 ) {
            res += num % 10 + '0';
            num /= 10;
        }
        int len = res.length();
        for (int i = 0; i < len / 2; ++i) {
            char tmp = res[i];
            res[i] = res[len - i - 1];
            res[len - i - 1] = tmp;
        }
        return (sign < 0)?"-" + res : res;
    }
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

    bool operator == (const Fraction &other) {
        return (numerator_ * other.denominator_ == other.numerator_ * denominator_);
    }

    bool operator != (const Fraction &other) {
        return !(*this == other);
    }

    bool operator < (const Fraction &other) {
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    bool operator > (const Fraction &other) {
        return !(*this < other);
    }

    bool operator <= (const Fraction &other) {
        return numerator_ * other.denominator_ <= other.numerator_ * denominator_;
    }

    bool operator >= (const Fraction &other) {
        return numerator_ * other.denominator_ >= other.numerator_ * denominator_;
    }

    std::string print() {
        return toStr(numerator_) + "/" + toStr(denominator_);
    }

    Fraction operator + (Fraction& other) {
        int denominator = denominator_ * other.denominator_;   
        int gcdv = gcd(numerator_ * other.denominator_, other.numerator_ * denominator_);        

        return Fraction(numerator_ * other.denominator_ / gcdv + other.numerator_ * denominator_ / gcdv, denominator); 
    }

    Fraction operator - (Fraction& other) {
        int denominator = denominator_ * other.denominator_;   
        int gcdv = gcd(numerator_ * other.denominator_, other.numerator_ * denominator_);        

        return Fraction(numerator_ * other.denominator_ / gcdv - other.numerator_ * denominator_ / gcdv, denominator);         
    }

    Fraction operator * (Fraction& other) {
        int denominator = denominator_ * other.denominator_;   
        int numerator  = numerator_ * other.numerator_;
        int gcdv = gcd(numerator, denominator);        

        return Fraction(numerator / gcdv, denominator / gcdv);         
    }

    Fraction operator / (Fraction& other) {
        int denominator = denominator_ * other.numerator_;   
        int numerator  = numerator_ * other.denominator_;
        int gcdv = gcd(numerator, denominator);        

        return Fraction(numerator / gcdv, denominator / gcdv);         
    }

    Fraction& operator ++() {
        numerator_ += denominator_;
        return *this;
    }

    Fraction& operator --() {
        numerator_ -= denominator_;
        return *this;
    }    
    
    Fraction operator --(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }  
    
    Fraction operator ++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }      
};

int main() {
    int a{0}, b{0};
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> a;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> b;
	Fraction f1(a, b);
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> a;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> b;
	Fraction f2(a, b);

    std::cout << f1.print() << " + " << f2.print() << " = " << (f1 + f2).print() << std::endl;
    std::cout << f1.print() << " - " << f2.print() << " = " << (f1 - f2).print() << std::endl;
    std::cout << f1.print() << " * " << f2.print() << " = " << (f1 * f2).print() << std::endl;
    std::cout << f1.print() << " / " << f2.print() << " = " << (f1 / f2).print() << std::endl;
    std::cout << "++" << f1.print() << " * " << f2.print() << " = " << (++f1 * f2).print() << std::endl;
    std::cout << "Значение дроби 1 = " << f1.print() << std::endl;
    std::cout << f1.print() << "--" << " * " << f2.print() << " = " << (f1-- * f2).print() << std::endl;
    std::cout << "Значение дроби 1 = " << f1.print() << std::endl;
    std::cout << "Тест постфиксной записи: " << std::endl;
    std::cout << "f1++ = " << f1++.print() << " После инкремента: " << f1.print() << std::endl;
    std::cout << "Тест префисксной записи: " << std::endl;
    std::cout << "++f1 = " << (++f1).print() << " После инкремента: " << f1.print() << std::endl;

	return 0;
}