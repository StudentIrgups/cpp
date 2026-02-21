#pragma once
#include "figure.h"

class quadangle : public figure {    
    public:
        quadangle();
        void print_info () override;
        bool check() override;
    protected:
        int _a, _b, _c, _d, _A, _B, _C, _D;
};