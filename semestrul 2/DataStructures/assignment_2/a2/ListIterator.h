#pragma once
#include "IteratedList.h"


//DO NOT CHANGE THIS PART
class IteratedList;
typedef int TElem;

class ListIterator{
	friend class IteratedList;
private:
	Node* head;
	Node* tail;


	//DO NOT CHANGE THIS PART
	const IteratedList& list;
	ListIterator(const IteratedList& lista);
public:
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
	void jumpForward(int k);


};


