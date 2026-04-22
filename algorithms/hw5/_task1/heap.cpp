#include "heap.h"

heap::heap() {
    size = 0;
    arr = nullptr;
}

int heap::root() {
    return arr[0];
}

int heap::from_index(int idx) {
    return arr[idx];
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

void heap::just_add(int elem) {
    int * new_arr = new int[size + 1]();
    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }

    new_arr[size] = elem;

    delete[] arr;
    arr = new_arr;    
    ++size;
}

int * heap::get_arr() {
    return arr;
}

void heap::print_pyramid() {
    std::cout << "0 root " << root() << std::endl;
    for (int i = 1; i < size; ++i) {
        int parent = (i-1)/2;
        int level = 0;
        int temp = i + 1;
        while (temp > 1) {
            temp /= 2;
            ++level;
        }
        std::string relation = (i % 2 == 1) ? "left" : "right";
        std::cout << level << " " << relation << "(" << arr[parent] << ") " << arr[i] << std::endl;
    }
}

heap::~heap() {
    delete[] arr;
}