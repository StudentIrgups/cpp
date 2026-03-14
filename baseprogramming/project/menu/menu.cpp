#include "menu.h"

menu::menu() {
    races[0] = "Гонка для наземного транспорта";
    races[1] = "Гонка для воздушного транспорта";
    races[2] = "Гонка для наземного и воздушного транспорта";

    int gvehicle_size = sizeof(gvehicles) / sizeof(gvehicles[0]);
    int avehicle_size = sizeof(avehicles) / sizeof(avehicles[0]);

    delete[] arrVehicles;
    arrVehicles_size = gvehicle_size + avehicle_size;
    arrVehicles = new std::string[arrVehicles_size];

    for (int i = 0; i < gvehicle_size; ++i) {
        arrVehicles[i] = gvehicles[i].name;
    }
    for (int i = 0; i < avehicle_size; ++i) {
        arrVehicles[i+gvehicle_size] = avehicles[i].name;
    }
}

menu::~menu() {
    delete[] regedVehc;
    delete[] arrVehicles;
}

void menu::set_distance(int dis) {    
    distance = dis;
}

std::string * menu::get_races() {
    return races;
}

int menu::get_races_size() {
    return sizeof(races)/sizeof(races[0]);
}

int menu::set_type_race(int type) {
    if (type < 0 || type > sizeof(races) / sizeof(races[0]))
        return -1;
    typeRace = type;
    return 0;
}

std::string menu::get_type_race() {
    return races[typeRace];
}

int menu::get_distance() {
    return distance;
}

std::string * menu::get_vehicles() {
    return arrVehicles;
}

int menu::get_arrvehicles_size() {
    return arrVehicles_size;
}

std::string menu::add_to_reg(int typeVehic) {

    if (typeVehic < 0 || typeVehic > get_arrvehicles_size())
        return "Нет такого вида транспорта";

    if (typeRace == 0) {
        if (typeVehic != static_cast<int>(evehicles::camel)           &&
            typeVehic != static_cast<int>(evehicles::camelFast)       &&
            typeVehic != static_cast<int>(evehicles::allTerrainBoots) &&
            typeVehic != static_cast<int>(evehicles::centaur)) {
            return arrVehicles[typeVehic] + " не разрешён на " + get_type_race();
        }
    } else if (typeRace == 1) {
        if (typeVehic != static_cast<int>(evehicles::flyingCarpet) &&
            typeVehic != static_cast<int>(evehicles::eagle)        &&
            typeVehic != static_cast<int>(evehicles::broom)) {
            return arrVehicles[typeVehic] + " не разрешён на " + get_type_race();
        }
    }
       
    vehicle* newArray = new vehicle[size]; 

    if (size > 1)
        for (size_t i = 0; i < size; ++i) {
            newArray[i] = regedVehc[i]; 
        }

    delete[] regedVehc;
    
    regedVehc = new vehicle[++size];

    for (size_t i = 0; i < size-1; ++i) {
        regedVehc[i] = newArray[i]; 
    }

    if (typeVehic == static_cast<int>(evehicles::camel)           ||
        typeVehic == static_cast<int>(evehicles::camelFast)       ||
        typeVehic == static_cast<int>(evehicles::allTerrainBoots) ||
        typeVehic == static_cast<int>(evehicles::centaur)) {  
        ground oground(typeVehic);
        regedVehc[size-2] = oground;
    }    

    if (typeVehic == static_cast<int>(evehicles::flyingCarpet) ||
        typeVehic == static_cast<int>(evehicles::eagle)        ||
        typeVehic == static_cast<int>(evehicles::broom)) {
        air oair(typeVehic);
        regedVehc[size-2] = oair;
    }

    delete[] newArray;
    return "1";
}

std::string menu::get_last() {
    return regedVehc[size-2].get_name();
}

vehicle * menu::get_reged() {
    return regedVehc;
}

int menu::get_reged_size() {
    return size;
}


