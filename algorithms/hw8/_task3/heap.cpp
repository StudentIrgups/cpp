#include "heap.h"

heap::heap() {
    size = 0;
    arr  = nullptr;
}

int heap::left_index(int parent_idx) {
    return 2 * parent_idx + 1;
}

int heap::right_index(int parent_idx) {
    return 2 * parent_idx + 2;
}

int heap::parent_idx(int child_idx) {
    return (child_idx - 1) / 2;
}

void heap::try_up(int idx) {
    if (idx == 0)
        return;
    int parent_idx = this->parent_idx(idx);
    vw parent = arr[parent_idx];
    if (parent.weight > arr[idx].weight) {
        std::swap(arr[idx], arr[parent_idx]);
        try_up(parent_idx);
    }
}

void heap::add(vw elem) {
    vw * new_arr = new vw[size + 1]();
    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }

    new_arr[size] = elem;

    delete[] arr;
    arr = new_arr;    
    ++size;
    try_up(size-1);
}

void heap::shif_down(int idx) {
    while (true) {  
        int smallest = idx;
        int left = left_index(idx);
        int right = right_index(idx);
        
        if (left < size && arr[left].weight < arr[smallest].weight) {
            smallest = left;
        }
        
        if (right < size && arr[right].weight < arr[smallest].weight) {
            smallest = right;
        }
        
        if (smallest != idx) {
            std::swap(arr[idx], arr[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
}

int heap::extract_min() {
    if (size == 0) return -1;
    
    int min_vertex = arr[0].vertex;
    
    std::swap(arr[0], arr[size - 1]);
    size--;
    
    if (size > 0) {
        shif_down(0);
    }
    
    return min_vertex;
}

bool heap::is_empty(){
    return (size == 0);
}

heap::~heap() {
    delete[] arr;
}