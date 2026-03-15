#pragma once
#include "quadangle.h"

class rectangle : public quadangle {    
    public:
        rectangle();
        void print_info () override;
        bool check() override;
};