#include <iostream>

int binary_search_idx(int* a, int n, int len) {
    int left = 0;
    int right = len;

    while (left < right) {
        int mid = left + (right - left)/2;

        if (a[mid] <= n)
            left = mid + 1;
        else 
            right = mid;
    }
    return left;    
}

int cout_gt(int* a, int n, int len) {
    int idx = binary_search_idx(a, n, len);
    return len - idx;    
}

int main(void) {
    int a[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int len = sizeof(a)/sizeof(a[0]);

    std::cout << "Введите точку отсчёта: ";
    int n{0};
    std::cin >> n;

    std::cout << "Количество элементов, больших чем " << n << ": " << cout_gt(a, n, len) << std::endl;

    return 0;
}