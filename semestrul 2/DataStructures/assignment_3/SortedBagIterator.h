#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	int current;
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);



public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};
