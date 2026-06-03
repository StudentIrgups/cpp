#include <iostream>
#include <map>
#include <algorithm>

int main() {
    std::map<char,int> mp;
    std::string str = "Hello world!!&&!";

    for (int i = 0; i < str.size(); ++i) 
        mp[str[i]]++;
    std::vector<std::pair<char,int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), [](std::pair<char,int> l, std::pair<char,int> r) { return l.second > r.second;});
    std::cout << str << std::endl;
    for (auto it:vec)
        std::cout << it.first << ": " << it.second << std::endl;
    return 0;
}