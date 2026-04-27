#include "rabinKarp.h"

int find_substring_light_rabin_karp(std::string source, std::string pattern) {
    int p_hash = simple_string_hash(pattern);
    int skmin1_hash {0};
    int kmin1 = pattern.length();

    for (int i = 0; i <= source.length() - kmin1; ++i) {
        if (i == 0) {
            skmin1_hash = simple_string_hash(source.substr(0,kmin1));
        } else {
            skmin1_hash -= static_cast<int>(source[i-1]);
            skmin1_hash += static_cast<int>(source[i+kmin1-1]);
        }
        if (skmin1_hash != p_hash) {
            continue;
        } else {
            bool match = true;
            for (int j = 0; j < pattern.length(); ++j) {
                if (source[i+j] != pattern[j])  {
                    match = false;
                    break;
                }                        
            }
            if (match) return i;
        }        
    }

    return -1;
}