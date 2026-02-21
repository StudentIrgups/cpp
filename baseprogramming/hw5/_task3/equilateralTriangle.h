#include "triangle.h"

class equilateralTriangle : public triangle {
    public:
    equilateralTriangle ();
    void print_info () override;
    bool check() override;
};