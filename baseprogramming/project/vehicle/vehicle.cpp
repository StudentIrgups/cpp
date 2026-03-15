#include "vehicle.h"

vehicle_space::vehicle::vehicle() {
}

std::string vehicle_space::vehicle::get_name() {
    return agvehicle.name;
}

svehicle vehicle_space::vehicle::get_param() {
    return agvehicle;
}