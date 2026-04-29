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
    int parent = arr[parent_idx];
    if (parent < arr[idx]) {
        std::swap(arr[idx], arr[parent_idx]);
        try_up(parent_idx);
    }
}

void heap::add(int elem) {
    int * new_arr = new int[size + 1]();
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
    if (idx == size - 1)
        return;
    int min_child = std::min(arr[left_index(idx)], arr[right_index(idx)]);
    if (arr[idx] > arr[min_child]) {
        std::swap(arr[idx], arr[min_child]);
        shif_down(min_child);
    }
}

int heap::extract_min() {
    int mine = arr[0];
    arr[0] = arr[size-1];
    size--;
    int * new_arr = new int[size]();

    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }
    delete arr;
    arr = new_arr;
    shif_down(0);

    return mine;
}

heap::~heap() {
    delete[] arr;
}