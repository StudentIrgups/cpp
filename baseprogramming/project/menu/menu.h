#pragma once
#include "../vehicle/vehicle.h"
#include "../vehicle/ground/ground.h"
#include "../vehicle/air/air.h"
#include "../processor/processor.h"

class menu {
    public:        
        menu();
        ~menu();
        void set_distance(int dis);
        std::string * get_races();
        int get_races_size();
        void set_type_race(int type);
        std::string get_type_race();
        int get_distance();
        std::string * get_vehicles();
        int get_arrvehicles_size();
        std::string add_to_reg(int typeVehic);
        std::string get_last();
        vehicle * get_reged();
        int get_reged_size();
    protected:            
    private:
        std::string races[3];
        std::string * arrVehicles;
        int arrVehicles_size{0};
        int distance{0};
        int typeRace{0};
        int size = 1;
        vehicle * regedVehc{nullptr}; 
           
};