#include <iostream>

class smartArray{
    public:
        smartArray(int size) {
            _size = size;
            _arr = new int[size];
            _curr = 0;
        }
        void add_element(int n) {
            if (_curr >= _size)
                throw std::out_of_range("Массив полон");
            _arr[_curr] = n;
            _curr++;
        };
        int get_element(int idx) {
            if (idx < 0 || idx > _size - 1) 
                throw std::out_of_range("Не корректный индекс");
            return _arr[idx-1];
        }
        ~smartArray(){
            delete[] _arr;
        }
    protected:
        int _size;
        int * _arr;
        int _curr;
};

int main(void) {
    try {
        smartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}