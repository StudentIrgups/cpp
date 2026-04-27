#include "queue.h"

_queue::_queue(int n){
    size = n;
    curr = 0;
    arr = new int[size]();
}

void _queue::push(int e) {
    for (int i = curr; i > 0; --i) {
        arr[i] = arr[i-1];
    }
    arr[0] = e;
    curr++;
}

int _queue::pop() {    
    curr--;
    return arr[curr];
}

_queue::~_queue(){
    delete[] arr;
}