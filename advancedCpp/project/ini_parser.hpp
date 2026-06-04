#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <algorithm>
#include <map>

class ini_parser {
    public:
        void init(std::string filename);
    protected:
        void parse();
    private:
        std::vector<std::string> filecon;
        std::map<std::string, std::map<std::string, std::string>> ini;
};