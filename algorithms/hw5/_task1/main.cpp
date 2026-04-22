#include "main.h"

void print_piramid(int * arr) {

}

int main(void) {
    heap * _heap = new heap();

    int * arr = new int[6]{1, 3, 6, 5, 9, 8};

    for (int i = 0; i < 6; ++i) 
        _heap->just_add(arr[i]);

    _heap->print_pyramid();
    delete[] arr;
    delete _heap;

    std::cout << std::endl;

    _heap = new heap();
    arr = new int[8]{94, 67, 18, 44, 55, 12, 6, 42};

    for (int i = 0; i < 8; ++i) 
        _heap->just_add(arr[i]);

    _heap->print_pyramid();    
    delete[] arr;
    delete _heap;

    std::cout << std::endl;

    _heap = new heap();
    arr = new int[10]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    for (int i = 0; i < 10; ++i) 
        _heap->just_add(arr[i]);

    _heap->print_pyramid();    
    delete[] arr;
    delete _heap;    
}
