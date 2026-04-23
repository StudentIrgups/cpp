#include "heapWalk.h"

heapWalk::heapWalk():size(0), data(nullptr), currIdx(0){};

void heapWalk::just_add(int elem) {
    int * new_arr = new int[size + 1]();
    for (int i = 0; i < size; ++i) {
        new_arr[i] = data[i];
    }

    new_arr[size] = elem;

    delete[] data;
    data = new_arr;    
    ++size;
}

void heapWalk::print_pyramid() {
    std::cout << "0 root " << data[0] << std::endl;
    for (int i = 1; i < size; ++i) {
        int parent = (i-1)/2;
        int level = 0;
        int temp = i + 1;
        while (temp > 1) {
            temp /= 2;
            ++level;
        }
        std::string relation = (i % 2 == 1) ? "left" : "right";
        std::cout << level << " " << relation << "(" << data[parent] << ") " << data[i] << std::endl;
    }
    std::cout << std::endl;
}

void heapWalk::printHeap() {
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << "Пирамида: " << std::endl;
    print_pyramid();
}

std::string heapWalk::getCurrPos(){
    std::ostringstream oos;
    int temp  = currIdx + 1;
    int level = 0;
    while (temp > 1) {
        temp /= 2;
        level += 1;
    }
    int parent = 0;
    std::string leaf{""};

    if (currIdx == 0) {
        leaf = "root";
        parent = -1;
    } else if (currIdx % 2 == 1) {
        leaf = "left";
        parent = (currIdx - 1) / 2;
    } else {
        leaf = "right";
        parent = (currIdx - 1) / 2;
    }
    if (parent < 0)
        oos << "Вы находитесь здесь: " << level << " " << leaf << data[currIdx];
    else 
        oos << "\nВы находитесь здесь: " << level << " " << leaf << "(" << data[parent] << ") " << data[currIdx];
    return oos.str();
}

std::string heapWalk::tryToMove(std::string act) {
    if (act == _up) {
        if (currIdx == 0) 
            throw std::runtime_error("Ошибка! Отсутствует родитель");    
        currIdx = (currIdx - 1) / 2;
        
    } else if (act == _left) {
        if (2 * currIdx + 1 >= size) 
            throw std::runtime_error("Ошибка! Отсутствует левый потомок");          
        currIdx = 2 * currIdx + 1;      
    } else if (act == _right) {
        if (2 * currIdx + 2>= size) 
            throw std::runtime_error("Ошибка! Отсутствует правый потомок");   
        currIdx = 2 * currIdx + 2;
    } else {
        throw std::runtime_error("Неизвестное действие");
    }
    return "Ok";
}

heapWalk::~heapWalk() {
    delete[] data;
}