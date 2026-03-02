#pragma once
#include <iostream>

class badFigure : public std::exception {
    public: 
        virtual const char* what() const noexcept;
};