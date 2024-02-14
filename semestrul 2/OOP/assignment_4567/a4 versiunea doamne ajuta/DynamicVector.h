#pragma once
#include "tutorials.h"


template <typename T>
class DynamicVector
{
private:
	T* elements;
	int capacity, size;



public:
	
	DynamicVector(int capacity = 100);
	~DynamicVector();
	void resize();
	DynamicVector(const DynamicVector& vector);
	DynamicVector& operator=(const DynamicVector& vector);

	void add(const T& element);
	void delete_(const T& element);
	void update(const T& element);

	T getElement(int i) const;
	int getCapacity() const;
	int getSize() const;
};

template class DynamicVector<Tutorials>;
