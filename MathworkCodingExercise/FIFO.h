#pragma once
#include "Collection.h"

template<typename T>
class FIFO :
    public Collection<T>
{
public:
    void Add(T);
    T Get();
private:
    void resize();
    long long int front_index{0};
    long long int end_index{-1};
};
