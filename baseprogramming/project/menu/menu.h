#pragma once
#include "../vehicle/vehicle.h"
#include "../vehicle/ground/ground.h"
#include "../vehicle/air/air.h"

class menu {
    public:        
        menu();
        void set_distance(int dis);
        std::string * get_races();
        int get_races_size();
        void set_type_race(int type);
        std::string get_type_race();
        int get_distance();
        std::string * get_vehicles();
        int get_arrvehicles_size();
        void add_to_reg(int typeVehic);
        std::string get_last();
        //ehicle * get_reged();
        //int get_reged_size();
    protected:
    private:
        std::string races[3];
        std::string arrVehicles[7];
        int distance{0};
        int typeRace{0};
        vehicle * regedVehc[1]{nullptr};        
};