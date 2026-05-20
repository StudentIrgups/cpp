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
            if (idx < 0 || idx > _size) 
                throw std::out_of_range("Не корректный индекс");
            return _arr[idx-1];
        }
        smartArray& operator =(smartArray& other) {            
            this->_arr  = new int[other._size];
            this->_curr = 0;
            this->_size = other._size;
            for (int i = 0; i < other._size; ++i)
                this->add_element(other.get_element(i+1));
            return * this;
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

        smartArray new_array(2);
        new_array.add_element(44); 
        new_array.add_element(34);

        arr = new_array;
        int idx = 1;
        while(true) {
            std::cout << arr.get_element(idx++) << " ";
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}