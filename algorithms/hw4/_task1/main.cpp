#include "main.h"

int main(void) {
    while (true) {    
    
        std::cout << ENTER_FACT_SIZE;
        int fact_size{0};
        std::cin >> fact_size;

        std::cout << ENTER_LOGIC_SIZE;
        int logic_size{0};
        std::cin >> logic_size;    

        if (logic_size > fact_size) {
            std::cout << ERROR << std::endl;
            continue;
        }

        int * arr = new int[fact_size]();

        for (int i = 0; i < logic_size; ++i) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> arr[i];
        }
        print_dynamic_array(arr, logic_size, fact_size);

        delete[] arr;
        return 0;
    }
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size)
            std::cout << arr[i] << " ";
        else 
            std::cout << "_ ";
    }
}