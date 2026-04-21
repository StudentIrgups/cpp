#pragma once
#include <iostream>

#define ENTER_FACT_SIZE "Введите фактичеcкий размер массива: "
#define ENTER_LOGIC_SIZE "Введите логический размер массива: "
#define ERROR "Ошибка! Логический размер массива не может превышать фактический!"

void print_dynamic_array(int* arr, int logical_size, int actual_size);