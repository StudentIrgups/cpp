 #include "triangle.h"

 class isoscelesTriangle : public triangle {
        public:
        isoscelesTriangle();
        void print_info () override;
        bool check() override;
};