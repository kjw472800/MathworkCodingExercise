#pragma once

// Collections interfaces provides the abstract data type to represent collections.

template<typename T>
class Collection
{
public:
	Collection();
	~Collection();
	bool IsEmpty() const;
	size_t Size() const;
	virtual T Get() = 0;
	virtual void Add(T obj) = 0;
protected:
	const size_t max_capacity = 1024;
	virtual void resize();
	bool isFull() const;
	size_t size;
	size_t capacity;
	T* collection;
private:
};

