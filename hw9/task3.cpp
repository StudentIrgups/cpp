#include <iostream>

void reverse(int* mass, int size);
void print(int * mass, int size);

int main() {
    int mass[10] = {-1, 9, 33, 45, 146, 123, 435, 442, 123412, -500};
    print(mass, sizeof(mass)/sizeof(mass[0]));
    reverse(mass, sizeof(mass)/sizeof(mass[0]));
    print(mass, sizeof(mass)/sizeof(mass[0]));

    int mass1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(mass1, sizeof(mass1)/sizeof(mass1[0]));
    reverse(mass1, sizeof(mass1)/sizeof(mass1[0]));
    print(mass1, sizeof(mass1)/sizeof(mass1[0]));
    return 0;
}

void reverse(int* mass, int size) {

    for (int i = 0; i < size/2; ++i) {
        int tmp = mass[i];
        mass[i] = mass[size - 1 - i];
        mass[size - 1 - i] = tmp;
    }
}

void print(int* mass, int size){
	for (int i = 0; i < size; ++i)
        std::cout << *(mass + i) << "  ";
    std::cout << std::endl;
}