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
        template<typename T>
        T get_value(std::string sv) {
            int pospoint = sv.find('.');
            if (pospoint == std::string::npos) {
                throw std::runtime_error("Входящее значение должно иметь вид: sectionN.var");
            }
            std::string section = sv.substr(0,pospoint);
            std::transform(section.begin(), section.end(), section.begin(), ::toupper);
            
            auto sec = ini.find('[' + section + ']');
            if (sec == ini.end()) {
                throw std::runtime_error("Нет секции: " + sv.substr(0,pospoint));
            }
            std::string vr = sv.substr(pospoint + 1);
            std::transform(vr.begin(), vr.end(), vr.begin(), ::toupper);

            auto var = sec->second.find(vr);

            if (var == sec->second.end()) {
                throw std::runtime_error("Нет переменной: " + sv.substr(pospoint+1));
            }

            std::istringstream iss(var->second);
            T temp;
            iss >> temp;

            if (iss.fail()) {
                throw std::runtime_error("Не удалось преобразовать: " + var->second);
            }

            // Для double дополнительно проверяем, что не осталось мусора
            char c;
            if (iss >> c) {
                throw std::runtime_error("Лишние символы в числе: " + var->second);
            }

            return temp;
        }
    protected:
        void parse();
    private:
        std::vector<std::string> filecon;
        std::map<std::string, std::map<std::string, std::string>> ini;
};