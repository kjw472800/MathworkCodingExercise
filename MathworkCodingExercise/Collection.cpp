#include "Collection.h"
#include "iostream"
#include <algorithm>

template<typename T>
Collection<T>::Collection():capacity(4),size(0)
{
	this->collection = new T[capacity];
}

template<typename T>
Collection<T>::~Collection()
{
	if (this->collection) {
		delete[] this->collection;
	}
}


template<typename T>
bool Collection<T>::IsEmpty() const
{
	return this->size == 0;
}

template<typename T>
size_t Collection<T>::Size() const
{
	return this->size;
}

template<typename T>
bool Collection<T>::isFull() const
{
	return this->size == this->capacity;
}


// Resizes the collection and copies the data from the old storage to new storage
// 1. Allocates 2*size units of storage.
// 2. Copies the data from the old storage to the new storage.
template<typename T>
void Collection<T>::resize() {
	size_t oldCapacity = this->capacity;
	T* oldCollection = this->collection;
	this->capacity = std::min(oldCapacity * 2,this->max_capacity);
	this->collection = new T[this->capacity];
	for (unsigned int i = 0; i < oldCapacity; ++i) {
		this->collection[i] = oldCollection[i];
	}
	delete[] oldCollection;
}

template class Collection<int>;
