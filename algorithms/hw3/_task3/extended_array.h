#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class ExtArray {
	private:
		std::vector<T> extended_array;
		size_t _size;
	public:
		 ExtArray(std::initializer_list<T> l) : extended_array(l) {
			_size = l.size();
		}

		ExtArray(int size) : _size(size) {
			extended_array.resize(_size);
		}
				
		ExtArray(int* arr, size_t len) : _size(len) {
			extended_array.resize(len);
			for (size_t i = 0; i < len; ++i) {
				extended_array[i] = arr[i];
			}
		}

		T& operator[](size_t index) {
			return extended_array[index];
		}
		
		const T& operator[](size_t index) const {
			return extended_array[index];
		}

		size_t size() const {
			return _size;
		}
		
		T* data() {
			return extended_array.data();
		}
		
		const T* data() const {
			return extended_array.data();
		}

		bool isEqual (int* expected, size_t expected_size) {
			if (_size != expected_size) {
				return false;
			}
			
			for (size_t i = 0; i < _size; ++i) {
				if (extended_array[i] != expected[i]) {
					return false;
				}
			}
			return true;
		}
};
