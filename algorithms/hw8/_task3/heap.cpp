#include "heap.h"

heap::heap(int cap) : capacity(cap) {
    size = 0;
    arr = new vw[capacity];
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

void heap::shif_up(int idx) {
    while (idx > 0) {
        int parent = parent_idx(idx);
        if (arr[idx].weight < arr[parent].weight) {
            std::swap(arr[idx], arr[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

void heap::add(vw elem) {
    if (size >= capacity) {
        capacity *= 2;
        vw * new_arr = new vw[capacity]();
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];            
        }
        delete[] arr;
        arr = new_arr;
    }

    arr[size] = elem;     
    shif_up(size);
    ++size;
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