#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <typeinfo>

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

		T& operator[](size_t index) {
			return extended_array[index];
		}

		size_t size() {
			return _size;
		}

		double mean() {
			double sum = 0;
			for (size_t i = 0; i < _size; i++)
			{
				sum += extended_array[i];
			}
			if (_size == 0)
				return 0;
			return sum / _size;
		}

		double mean(int a, int b) {
			if (a >= b)
				throw std::invalid_argument("Первый аргумент больше или равен второму");
			double sum = 0;
			for (size_t i = a-1; i < b; i++)
			{
				sum += extended_array[i];
			}
			if (_size == 0)
				return 0;
			return sum / (b-a+1);
		}

		double median() {
			std::vector<T> temp_array;
			std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
			std::sort(temp_array.begin(), temp_array.end());
			if (_size == 0)
				return 0;
			if (_size % 2 == 1)
			{
				return temp_array[_size / 2];
			}
			else
			{
				return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
			}
		}

		std::pair<T, int> mode() {
			if (_size == 0)
				return std::pair<T, int>(0, 0);
			T max = extended_array[0], cmax = 0, rmax = 0;
			for (int i = 0; i < _size; i++) 
			{
				if (cmax > rmax) 
				{
					rmax = cmax;
					max = extended_array[i - 1];
				}
				cmax = 0;
				for (int j = i; j < _size; j++)
				{
					if (extended_array[j] == extended_array[i])
					{
						cmax++;
					}
				}
			}
			return std::pair<T, int>(max, rmax);
		}

		int checkSum() {
			if (typeid(extended_array) != typeid(std::vector<bool>) && typeid(extended_array) != typeid(std::vector<int>))
				throw std::bad_typeid();
			int counti{0};
			for (size_t i = 0; i < _size; i++)
			{
				if (extended_array[i] != 0 && extended_array[i] != 1)
					throw std::logic_error("Разрешены только 1 и 0 в качестве элементов массива");
				counti += (extended_array[i] == 1);
			}
			if (_size == 0)
				return 0;
			return counti;
		}
};
