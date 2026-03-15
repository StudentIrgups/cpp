#pragma once
#include "quadangle.h"

class rum : public quadangle {   
    public:
        rum();
        void print_info () override;
        bool check() override;
}; 