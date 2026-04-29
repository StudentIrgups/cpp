#pragma once
#include <iostream>

class _queue {
    public:
        _queue(int n);
        void push(int e);
        int pop();    
        bool is_empty();   
        ~_queue();
    protected:    
    private:
        int * arr;
        int size{0};
        int curr{0};
};