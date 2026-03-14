#include "vehicle.h"

vehicle::vehicle() {
}

std::string vehicle::get_name() {
    return agvehicle.name;
}

svehicle vehicle::get_param() {
    return agvehicle;
}