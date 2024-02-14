#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	

	//TODO - Representation
	int index;
	int current;
	int currentValueIndex;
	void validPosition();


public:
	SMMIterator(const SortedMultiMap& map);
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

