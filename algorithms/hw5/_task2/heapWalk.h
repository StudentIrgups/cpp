#pragma once
#include <sstream>
#include <iostream>

class heapWalk {
    public:
        const std::string _up    = "up";
        const std::string _left  = "left";
        const std::string _right = "right";

        heapWalk();
        void just_add(int elem);
        void print_pyramid();
        void printHeap();
        std::string getCurrPos();
        std::string tryToMove(std::string act);
        ~heapWalk();
    protected:
    private:
        int * data;
        int size;
        int currIdx;
};