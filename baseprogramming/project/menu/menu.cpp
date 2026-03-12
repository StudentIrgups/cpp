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

void menu::add_to_reg(int typeVehic) {
    int old_size = sizeof(regedVehc) / sizeof(regedVehc[0]);
    
    vehicle* newArray[old_size + 1] {nullptr}; 

    for (size_t i = 0; i < old_size; ++i) {
        newArray[i] = regedVehc[i]; 
    }

    for (int i = 0; i < old_size; ++i) {
        if (regedVehc[i] != nullptr) {  
            delete regedVehc[i];
            regedVehc[i] = nullptr;
        }
    }

    for (size_t i = 0; i < old_size; ++i) {
        regedVehc[i] = newArray[i]; 
    }

    if (typeVehic == static_cast<int>(evehicles::camel)           ||
        typeVehic == static_cast<int>(evehicles::camelFast)       ||
        typeVehic == static_cast<int>(evehicles::allTerrainBoots) ||
        typeVehic == static_cast<int>(evehicles::centaur)) {  
        regedVehc[old_size] = new ground(typeVehic);
    }    

    for (int i = 0; i < old_size + 1; ++i) {
        if (newArray[i] != nullptr) {  
            delete newArray[i];
            newArray[i] = nullptr;
        }
    }
}

std::string menu::get_last() {
    return regedVehc[sizeof(regedVehc) / sizeof(regedVehc[0])]->get_name();
}

/* vehicle * menu::get_reged() {
    return regedVehc;
} */


