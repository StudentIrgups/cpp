#pragma once
#include "figure.h"

class triangle: public figure {       
    public:
        triangle();
        void print_info () override;
        bool check() override ;
    protected:
        int _a, _b, _c, _A, _B, _C;
};