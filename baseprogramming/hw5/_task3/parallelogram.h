#pragma once
#include "quadangle.h"

class parallelogram : public quadangle {    
    public:
        parallelogram();
        void print_info () override;
        bool check() override;
};