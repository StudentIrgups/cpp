#include "realHash.h"


long long realHash(std::string input, int p, int n) {
    int len = input.length();
    long long hash{0};
    long long power = 1;

    for (int i = 0; i < len; ++i) {
        long long char_code = static_cast<long long>(
            static_cast<unsigned char>(input[i])
        );
        hash = (hash + (char_code * power) % n) % n;
        power = (power * p) % n;
    }
    return hash % n;
}