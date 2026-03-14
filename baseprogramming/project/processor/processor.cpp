#include "processor.h"

float processor::process(vehicle &ovehicle, int distance) {
    float value{0.0};
    svehicle vehicle = ovehicle.get_param();
    int times{0};

    value = (float)distance / vehicle.speed;
    times = value / vehicle.timeMove;
    if (vehicle.timeMove > 0 && (int)value % vehicle.timeMove == 0) {
        times--;
    }

    switch (vehicle.vehicle)
    {
    case evehicles::camel:
        if (times > 0) {
            value += 5;
            times--;
        }        
        value += times * 8;
        break;
    case evehicles::camelFast:
        if (times > 0) {
            value += 5;
            times--;
        }        
        if (times > 0) {
            value += 6.5;
            times--;
        }        
        value += times * 8;
        break;
    case evehicles::centaur:    
        value += times * 2;
        break;        
    case evehicles::allTerrainBoots:
        if (times > 0) {
            value += 10;
            times--;
        }        
        value += times * 5;    
        break;       
    case evehicles::flyingCarpet:
        if (distance < 1000)
            value = (float)distance;
        else if(distance < 5000)
            value = ((float)distance * 0.97);
        else if(distance < 10000)
            value = ((float)distance * 0.90);
        else if(distance >= 10000)
            value = ((float)distance * 0.95);
        value /= vehicle.speed;
        break;    
    case evehicles::eagle:
        value = ((float)distance * 0.94) / vehicle.speed;
        break;             
    case evehicles::broom:
        times = distance / 1000;
        value = ((float)distance * (100 - times) / 100 ) / vehicle.speed;
        break;        
    default:
        break;
    }
    return value;
}