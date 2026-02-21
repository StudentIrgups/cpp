#pragma once
#include <iostream>

class figure {
    public:
        virtual void print_info();
        virtual bool check();
        virtual ~figure(){}
    protected:
        int _cSides = 0;
        std::string _name = "Фигура: ";
};