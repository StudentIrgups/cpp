#include "main.h"
#include <iostream>

int * merge(int * arr_a, int lena, int * arr_b, int lenb) {
    int ia = 0, ib = 0, ic = 0;
    int * c = new int[lena + lenb]();

    while (ia < lena || ib < lenb) {
        if (ia == lena) {
            c[ic++] = arr_b[ib++];
        } else if( ib == lenb) {
            c[ic++] = arr_a[ia++];
        } else if (arr_a[ia] < arr_b[ib]) {
            c[ic++] = arr_a[ia++];
        } else {
            c[ic++] = arr_b[ib++];
        }
    }
    return c;
}

void merge_sort(int* arr, int len) {
    if (len == 1)
        return;

    int * arr_a = new int[len/2]();
    for (int i = 0; i < len /2; ++i)
        arr_a[i] = arr[i];
    
    int * arr_b = new int[len - len/2]();
    
    for (int i = len/2; i < len; ++i)
        arr_b[i - len/2] = arr[i];

    merge_sort(arr_a, len/2);
    merge_sort(arr_b, len - len/2);

    int * arr_c = merge(arr_a, len/2, arr_b, len-len/2);

    for (int i = 0; i < len; ++i)
        arr[i] = arr_c[i];

    delete[] arr_a;
    delete[] arr_b;
    delete[] arr_c;
}

int main(void) {
    
    run_sort_test(
            {3, 43, 38, 29, 18, 72, 57, 61, 2, 33},
            {2, 3, 18, 29, 33, 38, 43, 57, 61, 72}, 
        merge_sort, "слиянием");                
    
    run_sort_test(
            {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74},
            {2, 4, 16, 25, 27, 28, 29, 49, 53, 59, 74, 87, 88, 89, 91}, 
        merge_sort, "слиянием");

    run_sort_test(
            {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62},
            {0, 7, 16, 19, 20, 24, 30, 59, 59, 60, 62, 62, 66, 79, 84, 90, 94, 95}, 
        merge_sort, "слиянием");        
    
    return 0;
}