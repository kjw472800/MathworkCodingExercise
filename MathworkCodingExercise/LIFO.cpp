#include "LIFO.h"
#include <iostream>

template<typename T>
void LIFO<T>::Add(const T obj)
{
	if (this->size == this->max_capacity) {
		throw std::length_error("Exceeded the capacity limit");
	}

	if (this->isFull()) {
		this->resize();
	}
	++this->size;
	++this->top_index;
	this->collection[this->top_index] = obj;
}

template<typename T>
T LIFO<T>::Get()
{
	if (this->IsEmpty()) {
		throw std::out_of_range("LIFO collection is empty");
	}
	T res = this->collection[this->top_index];
	--this->top_index;
	--this->size;
	return res;
}


template class LIFO<int>;
