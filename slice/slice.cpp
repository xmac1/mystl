#include "slice.h"
#include <memory>
#include <exception>

using namespace std;

template <typename T>
slice<T>::slice(int len, int cap)
{
	this->_length = len;
	this->_capacity = cap;
	_ptr = new T[cap];
	use_count = new size_t(1);
}

template <typename T>
slice<T>& slice<T>::append(const T& e)
{
	return *this;
}

template <typename T>
slice<T>::slice(const slice<T>& other)
{
	this->_length = other._length;
	this->_capacity = other._capacity;
	_ptr = other._ptr;
	*use_count++;
}

template<typename T>
slice<T>& slice<T>::operator=(const slice<T>& right)
{
	++*right.use_count;
	if (--*use_count <= 0)
	{
		delete[] _ptr;
		delete use_count;
	}
	this->length = right._length;
	this->_capacity = right._capacity;
	_ptr = right._ptr;
	return *this;
}

template <typename T>
slice<T>::~slice()
{
	*use_count--;
	if (*use_count <= 0)
	{
		delete [] _ptr;
		delete use_count;
	}
}
