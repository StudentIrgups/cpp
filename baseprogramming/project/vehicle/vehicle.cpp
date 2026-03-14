#include "vehicle.h"

vehicle::vehicle() {
}

std::string vehicle::get_name() {
    return agvehicle.name;
}

int vehicle::get_param() {
    return agvehicle.param;
}