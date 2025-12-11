#include <iostream>

void print(int * mass, int size);

int main(int argc, char** argv)
{
    int mass[10] = {-1, 9, 33, 45, 146, 123, 435, 442, 123412, -500};
    print(mass, sizeof(mass)/sizeof(mass[0]));

    int mass1[2] = {6342, 213};
    print(mass1, sizeof(mass1)/sizeof(mass1[0]));

    int mass2[7] = {81324, 14212, 1243, 12351234, 6547, 23416, 14364};
    print(mass2, sizeof(mass2)/sizeof(mass2[0]));
}

void print(int* mass, int size){
	for (int i = 0; i < size; ++i)
        std::cout << *(mass + i) << "  ";
    std::cout << std::endl;
}