#include "menu.h"

menu::menu() {
    races[0] = "Гонка для наземного транспорта";
    races[1] = "Гонка для воздушного транспорта";
    races[2] = "Гонка для наземного и воздушного транспорта";

    arrVehicles[static_cast<int>(evehicles::camel)]           = "Верблюд";
    arrVehicles[static_cast<int>(evehicles::camelFast)]       = "Верблюд-скороход";
    arrVehicles[static_cast<int>(evehicles::centaur)]         = "Кентавр";
    arrVehicles[static_cast<int>(evehicles::allTerrainBoots)] = "Сапоги вездеходы";
    arrVehicles[static_cast<int>(evehicles::flyingCarpet)]    = "Ковёр самолёт";
    arrVehicles[static_cast<int>(evehicles::eagle)]           = "Орёл";
    arrVehicles[static_cast<int>(evehicles::broom)]           = "Метла";
}

menu::~menu() {
    delete[] regedVehc;
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

void menu::set_type_race(int type) {
    typeRace = type;
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
    return sizeof(arrVehicles)/sizeof(arrVehicles[0]);
}

std::string menu::add_to_reg(int typeVehic) {

    if (typeVehic < 0 || typeVehic > get_arrvehicles_size())
        return "Нет такого вида транспорта";

    if (typeRace == 0) {
        if (typeVehic != static_cast<int>(evehicles::camel)           &&
            typeVehic != static_cast<int>(evehicles::camelFast)       &&
            typeVehic != static_cast<int>(evehicles::allTerrainBoots) &&
            typeVehic != static_cast<int>(evehicles::centaur)) {
            return arrVehicles[typeVehic-1] + " не разрешён на " + get_type_race();
        }
    } else if (typeRace == 1) {
        if (typeVehic != static_cast<int>(evehicles::flyingCarpet) &&
            typeVehic != static_cast<int>(evehicles::eagle)        &&
            typeVehic != static_cast<int>(evehicles::broom)) {
            return arrVehicles[typeVehic-1] + " не разрешён на " + get_type_race();
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
        regedVehc[size-1] = oground;
    }    

    delete[] newArray;
    return "1";
}

std::string menu::get_last() {
    return regedVehc[size-1].get_name();
}

/* vehicle * menu::get_reged() {
    return regedVehc;
} */


