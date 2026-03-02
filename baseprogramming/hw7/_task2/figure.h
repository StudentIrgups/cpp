#pragma once
#include "exception.h"

class figure {    
    public:
        figure(const std::string& name = "Фигура", int count = 0):_name(name), sideCount(count) {
            for (int i = 0; i < 4; ++i) {
                sides[i] = 0;
                angels[i] = 0;
            }
            sideCount = count;
        }
        virtual ~figure();

        std::string get_name() const;

        int get_sidesCount() const;

        const int* get_sides() const;

        const int* get_angels() const;
        
        virtual bool check();            
    
        protected:
        std::string _name;
        int sides[4];
        int angels[4];
        int sideCount;        
};