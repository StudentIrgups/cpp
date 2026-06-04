#include "ini_parser.hpp"

void ini_parser::init(std::string filename) {
    std::ifstream file(filename);

    if (file.is_open()) {        
        std::string word{""};
        while (std::getline(file,word)) {
            word.erase(0, word.find_first_not_of(" \t"));
            word.erase(word.find_last_not_of(" \t") + 1);
            word = std::regex_replace(word, std::regex("\\s+"), " ");
            
            if ( word.length() > 1 && word[0] != ';') {
                filecon.push_back(word);
            }
        }
        file.close();
        parse();
    } else {
        throw std::runtime_error("Не получилось открыть файл");
    }
}

void ini_parser::parse() {
    std::string cursec;
    std::reverse(filecon.begin(),filecon.end());

    while (!filecon.empty()) {
        std::string line = filecon.back();
        std::regex re("^\\[section\\d+\\]$", std::regex::icase);
        
        if (std::regex_match(line, re)) {
            cursec = line;
            ini[line];            
        } else if (line.find('[') != std::string::npos && line.find(']') != std::string::npos) {
            throw std::runtime_error("Есть скобки, но не [sectionN]");
        } else {            
            size_t pos = line.find('=');
            if (pos != std::string::npos) {
                std::string key = line.substr(0, pos);
                std::string value{""};
                if (pos + 1 < line.length()) {
                    value = line.substr(pos + 1);
                    pos = value.find(';');
                    if (pos != std::string::npos) {
                        value = value.substr(0, pos);
                    }
                }
                ini[cursec][key] = value;
            }            
        }
        filecon.pop_back();
    }    
}