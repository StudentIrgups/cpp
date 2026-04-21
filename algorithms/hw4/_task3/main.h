#pragma once
#include <iostream>

#define ENTER_FACT_SIZE "Введите фактичеcкий размер массива: "
#define ENTER_LOGIC_SIZE "Введите логический размер массива: "
#define ERROR "Ошибка! Логический размер массива не может превышать фактический!"
#define ERROR_WHEN_REMOVE "Невозможно удалить первый элемент, так как массив пустой. До свидания!"
#define QUESTION "Удалить первый элемент? "
#define THANKS "Спасибо! Ваш массив: "
#define YES "да"
#define NO "нет"

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void remove_dynamic_array_head(int*& arr, int &logic_size, int& fact_size);