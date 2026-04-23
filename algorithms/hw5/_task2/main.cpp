#include "main.h"

int main(void) {
    heapWalk * _heapWalk = new heapWalk;
    
    int arr[] = {1, 3, 6, 5, 9, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; ++i) {
        _heapWalk->just_add(arr[i]);
    }
    _heapWalk->printHeap();
    std::string act{""};
    do {
        std::cout << _heapWalk->getCurrPos() << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> act;
        if (act != "exit")
            try {
                std::cout << _heapWalk->tryToMove(act);
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
    } while (act != "exit");
    delete _heapWalk;
    return 0;
}
