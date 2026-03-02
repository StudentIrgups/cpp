#pragma once
#include <iostream>

class badFigure : public std::exception {
    public: 
        badFigure(std::string str);
        virtual std::string what();
    protected:
        std::string __error{""};
};