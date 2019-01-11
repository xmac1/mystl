#pragma once

#include <memory>

template <typename T>
class slice
{
public:
	slice(int len = 0, int cap = 0);
	slice(const slice&);
	slice& operator=(const slice&);

	slice& append(const T&);

	~slice();

	std::size_t len() { return _length; };
	std::size_t cap() { return _capacity; };

	T& operator[](std::size_t n) { return _ptr[n]; };
private:
	std::size_t _length;
	std::size_t _capacity;
	T* _ptr;
	std::size_t* use_count;
};