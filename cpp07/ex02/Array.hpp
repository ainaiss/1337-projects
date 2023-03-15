#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
	T *_array;
	unsigned int _len;
public:
	Array() : _array(nullptr), _len(0){}
	Array(unsigned int n): _array(new T[n]()), _len(n) {}
	Array(Array const &arr) : _array(nullptr), _len(0)
	{
		std::cout << "COPY\n";
		*this = arr;
	}
	Array	&operator=(Array const &arr)
	{
		std::cout << "ASSIGNMENT\n";
		if (this != &arr)
		{
			delete [] _array;
			_len = arr._len;
			_array = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = arr._array[i];
		}
		return *this;
	}
	T	&operator[](unsigned int index)
	{
		if (index >= _len || index < 0)
			throw OutOfRange();
		return _array[index];
	}
	~Array()
	{
		delete[] _array;
	}
	unsigned int &size() const
	{
		return (_len);
	}
	class OutOfRange: public std::exception
	{
		const char *what() const throw()
		{
			return "Out of the Range";
		}
	};
};

#endif
