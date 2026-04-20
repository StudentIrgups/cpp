#include "main.h"
#include <iostream>
#include <ctime>

int pivoting(int* arr, int len) {
    int pi = std::rand() % len;
    int pivot = arr[pi];
    
    int left = 0;
    int right = len - 1;
    
    while (left <= right) {
        while (arr[left] < pivot) 
            ++left;
        while (arr[right] > pivot)
            --right;
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    return left - 1; 
}

void quick_sort(int* arr, int len) {
    if (len <= 1) 
        return;

    int border = pivoting(arr, len);
    
    if (border < 0) border = 0;
    if (border >= len) border = len - 1;
    
    quick_sort(arr, border + 1);          
    quick_sort(arr + border + 1, len - border - 1);  
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