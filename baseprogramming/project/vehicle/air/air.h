#include "../vehicle.h"

namespace vehicle_space {
    class air : public vehicle {
        public:
            air(int type);    
        private:
            float reductionFactor;
    };
}