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

        std::string question{""};
        
        int * arr = new int[fact_size]();

        for (int i = 0; i < logic_size; ++i) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> arr[i];
        }
        try {
            do {
                print_dynamic_array(arr, logic_size, fact_size);

                std::cout << QUESTION;
                std::cin >> question;

                if (question == YES) {
                    if (logic_size == 0) {
                        throw std::runtime_error(ERROR_WHEN_REMOVE);
                    } else {
                        remove_dynamic_array_head(arr, logic_size, fact_size);                
                    }
                } 
            } while(question != NO);
        
            std::cout << THANKS;
            for (int i = 0; i < fact_size; ++i) {
                if (i < logic_size)
                    std::cout << arr[i] << " ";
                else 
                    std::cout << "_ ";
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
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

void remove_dynamic_array_head(int*& arr, int& logic_size, int& fact_size) {
    if (logic_size <= 0) return;
    
    if (logic_size - 1 <= fact_size / 3) {
        int new_fact_size = fact_size / 3;  

        if (new_fact_size < 1) 
            new_fact_size = 1;
        
        int* new_arr = new int[new_fact_size]();
        
        for (int i = 1; i < logic_size; ++i) {
            new_arr[i - 1] = arr[i];
        }
        
        delete[] arr;
        arr = new_arr;
        fact_size = new_fact_size;
    } else {
        for (int i = 0; i < logic_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
    }
    
    logic_size--;
}