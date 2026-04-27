#include "simpleHash.h"

int simple_string_hash(std::string input) {
    int len = input.length();
    int hash{0};
    for (int i = 0; i < len; ++i) {
        char c = input[i];
        hash += c;
    }
    return hash;
}