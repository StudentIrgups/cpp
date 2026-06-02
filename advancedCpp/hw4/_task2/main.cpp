#include <iostream>

template <typename T>
class Table {
public:
    Table(int rows, int cols) : _rows(rows), _cols(cols) {
        data = new T*[_rows];
        for (int i = 0; i < _rows; ++i) {
            data[i] = new T[_cols];
        }
    }
    
    ~Table() {
        for (int i = 0; i < _rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    T* operator[](int index) {
        return data[index];
    }

    const T* operator[](int index) const {
        return data[index];
    }
    
    void Size(int& rows, int& cols) const {
        rows = _rows;
        cols = _cols;
    }
    
private:
    T** data;
    int _rows;
    int _cols;
};

int main() {
    Table<int> table(4, 6);
        
    table[0][0] = 5;
    table[1][2] = 10;
        
    std::cout << table[0][0] << std::endl; 
    std::cout << table[1][2] << std::endl; 
        
    int rows, cols;
    table.Size(rows, cols);
    std::cout << "Размер: " << rows << "x" << cols << std::endl; 

    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0]; // выводит 4
    return 0;
}