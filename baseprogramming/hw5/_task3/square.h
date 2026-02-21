#pragma once
#include "quadangle.h"

class square : public quadangle {    
    public:
        square();
        void print_info () override;
        bool check() override;
};