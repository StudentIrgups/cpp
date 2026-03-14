#include "air.h"

air::air(int type) {
    int gvehicle_size = sizeof(gvehicles) / sizeof(gvehicles[0]);
    agvehicle = avehicles[type - gvehicle_size];
}