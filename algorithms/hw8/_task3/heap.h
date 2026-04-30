#pragma once
#include <iostream>



class heap {
    public:
        struct vw
        {
            int vertex;
            int weight;
        };
        heap();
        int left_index(int parent_idx);
        int right_index(int parent_idx);
        int parent_idx(int child_idx);
        void add(vw elem);
        void try_up(int idx);
        void shif_down(int idx);
        int extract_min();
        ~heap();
    private:
        vw * arr{0};
        int size;
};