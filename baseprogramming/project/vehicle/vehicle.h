#pragma once
#include "../main.h"

class vehicle {
    public:
        vehicle();
        ~vehicle(){};
        std::string get_name();
    protected:
        std::string name{""};
        int speed{0};
    private:
};