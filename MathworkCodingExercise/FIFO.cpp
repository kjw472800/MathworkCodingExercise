#include "FIFO.h"
#include <iostream>
#include <algorithm>

template<typename T>
void FIFO<T>::Add(T obj)
{
    if (this->size == this->max_capacity) {
        throw std::length_error("Exceeded the capacity limit");
    }

    if (this->isFull()) {
        this->resize();
    }
    ++this->size;
    this->end_index = (this->end_index + 1) % this->capacity;
    this->collection[this->end_index] = obj;
}

template<typename T>
T FIFO<T>::Get()
{
    if (this->IsEmpty()) {
        throw std::out_of_range("FIFO collection is empty");
    }
    T res = this->collection[this->front_index];
    --this->size;
    this->front_index = (this->front_index + 1) % this->capacity;
    return res;
}

// Resizes the collection and copies the data from the old storage to new storage
// 1. Allocates 2*size units of storage.
// 2. Copies the data from the old storage to the new storage.
// 3. Reorders the data of circular buffer from [front_index, end_index] to [0..size-1]
// 4. Reassigns front_index to 0 and end_index to size-1
template<typename T>
void FIFO<T>::resize()
{
    size_t old_capacity = this->capacity;
    T* oldCollection = this->collection;
    long long int old_front_index = this->front_index;
    long long int old_end_index = this->end_index;
    this->capacity = std::min(old_capacity * 2, this->max_capacity);;
    this->collection = new T[this->capacity];
    
    long long int i = old_front_index;
    long long int j = 0;
    while(j<old_capacity){
        this->collection[j] = oldCollection[i];
        if (i == old_end_index) {
            break;
        }
        ++j;
        i = (i + 1) % old_capacity;
    }
    this->front_index = 0;
    this->end_index = j;
    delete[] oldCollection;
}

template class FIFO<int>;