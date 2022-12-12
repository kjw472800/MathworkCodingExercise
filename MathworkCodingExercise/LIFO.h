#pragma once
#include "Collection.h"

template<typename T>
class LIFO :
    public Collection<T>
{
public:
    void Add(T);
    T Get();
private:
    long long int top_index{-1};
};
