#pragma once
#include <iostream>

class heap {
    private:
        int * arr{0};
        int size;
    public:
        heap();
        int root();
        int from_index(int idx);
        int left_index(int parent_idx);
        int right_index(int parent_idx);
        int parent_idx(int child_idx);
        void add(int elem);
        void just_add(int elem);
        void try_up(int idx);
        int * get_arr();
        void print_pyramid();
        ~heap();
};