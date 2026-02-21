#pragma once

class counter {
    int __var = 1;
    public:
        counter();
        counter(int var);
        void inc();
        void dec();
        int get_var();
};