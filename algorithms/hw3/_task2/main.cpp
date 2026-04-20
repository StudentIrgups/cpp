#include "main.h"
#include <iostream>
#include <ctime>

int pivoting(int * arr, int pi, int len) {
    int left = 0;
    int right = len - 1;
    int pivot = arr[pi];

    while (true) {
        while (arr[left] < pivot) 
            left += 1;
        while (arr[right] > pivot)
            right -= 1;
        if (left >= right) 
            return left;
        std::swap(arr[left], arr[right]);
        left += 1;
        right -= 1;
    }
}

void quick_sort(int* arr, int len) {
    if (len <= 1)
        return;
    int pi = std::rand() % len;
    int border = pivoting(arr, pi, len);

    if (border == 0)
        border = 1;
    
        if (border == len)
        border = len - 1;

    int * arr_a = new int[border]();

    for (int i = 0; i < border; ++i)
        arr_a[i] = arr[i];

    int * arr_b = new int[len - border]();

    for (int i = 0; i < len - border; ++i)
        arr_b[i] = arr[i + border];        

    quick_sort(arr_a, border);
    quick_sort(arr_b, len - border);

    for (int i = 0; i < border; ++i)
        arr[i] = arr_a[i];
    for (int i = 0; i < len - border; ++i)
        arr[border + i] = arr_b[i];

    delete[] arr_a;
    delete[] arr_b;    
}

int main(void) {
    std::srand(std::time(nullptr));
    
    run_sort_test(
            {3, 43, 38, 29, 18, 72, 57, 61, 2, 33},
            {2, 3, 18, 29, 33, 38, 43, 57, 61, 72}, 
        quick_sort, "быстрая");
    
    run_sort_test(
            {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74},
            {2, 4, 16, 25, 27, 28, 29, 49, 53, 59, 74, 87, 88, 89, 91}, 
        quick_sort, "быстрая");

    run_sort_test(
            {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62},
            {0, 7, 16, 19, 20, 24, 30, 59, 59, 60, 62, 62, 66, 79, 84, 90, 94, 95}, 
        quick_sort, "быстрая");
    
    return 0;
}