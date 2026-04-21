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

        int act{0};
        
        int * arr = new int[fact_size]();

        for (int i = 0; i < logic_size; ++i) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> arr[i];
        }
        do {
            print_dynamic_array(arr, logic_size, fact_size);

            std::cout << ENTER_ELEM;
            std::cin >> act;

            if (act != 0) {
                append_to_dynamic_array(arr, logic_size, fact_size);
                arr[logic_size - 1] = act;
            } 
        } while(act != 0);
    
        std::cout << THANKS;
        for (int i = 0; i < fact_size; ++i) {
            if (i < logic_size)
                std::cout << arr[i] << " ";
            else 
                std::cout << "_ ";
        }
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
    std::cout << std::endl;
}

void append_to_dynamic_array(int*& arr, int &logic_size, int& fact_size) {
    if (logic_size == fact_size) {    
        fact_size = 2*logic_size;    
        int * new_arr = new int[fact_size]();
        
        for (int i = 0; i < logic_size; ++i) {
            new_arr[i] = arr[i];            
        }
        
        delete[] arr;
        arr = new_arr;
    }    
    logic_size++;
}   