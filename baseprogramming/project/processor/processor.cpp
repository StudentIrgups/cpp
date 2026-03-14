#include "processor.h"

float processor::process(vehicle &ovehicle, int distance) {
    int param = ovehicle.get_param();
    
    return distance + param;
}