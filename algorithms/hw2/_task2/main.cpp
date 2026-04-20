#include <iostream>

int fibo(int n, int* arr) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (arr[n] != 0)
        return arr[n];
    int res = fibo(n-1, arr) + fibo(n-2, arr);
    arr[n] = res;
    return res;
}

int main(void) {
    std::cout << "Введите число: ";
    int n{0};
    std::cin >> n;

    int* arr = new int[n]();    

    std::cout << "Ответ: " << fibo(n, arr) << std::endl;

    delete[] arr;
    return 0;
}