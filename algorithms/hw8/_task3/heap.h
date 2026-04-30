#pragma once
#include <iostream>



class heap {
    public:
        struct vw
        {
            int vertex;
            int weight;
        };
        heap(int cap = 100);
        int left_index(int parent_idx);
        int right_index(int parent_idx);
        int parent_idx(int child_idx);
        void add(vw elem);
        void try_up(int idx);
        void shif_up(int idx);
        void shif_down(int idx);
        int extract_min();
        bool is_empty();
        ~heap();
    private:
        vw * arr{0};
        int size;
        int capacity;
};