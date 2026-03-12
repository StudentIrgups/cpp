#include "../vehicle.h"

class air : public vehicle {
    public:
        air(int type);    
    private:
        float reductionFactor;
};
