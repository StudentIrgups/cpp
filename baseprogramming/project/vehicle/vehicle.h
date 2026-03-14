#pragma once
#include "../main.h"

class vehicle {
    public:
        vehicle();
        ~vehicle(){};
        std::string get_name();
        int get_param();
    protected:
        svehicle agvehicle;
    private:
};