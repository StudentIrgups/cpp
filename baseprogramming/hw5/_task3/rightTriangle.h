#pragma once
#include "triangle.h"

class rightTriangle : public triangle {
        public:
        rightTriangle();
        void print_info () override;
        bool check() override;
};