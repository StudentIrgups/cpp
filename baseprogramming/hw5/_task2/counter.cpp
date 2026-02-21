#include "counter.h"
counter::counter(){}
counter::counter(int var){
    __var = var;
}
void counter::inc(){
    ++__var;
}
void counter::dec(){
    --__var;
}
int counter::get_var(){
    return __var;
}