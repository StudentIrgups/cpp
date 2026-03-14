#pragma once
#include "../main.h"

class vehicle {
    public:
        vehicle();
        ~vehicle(){};
        std::string get_name();
        svehicle get_param();
    protected:
        svehicle agvehicle;
    private:
};