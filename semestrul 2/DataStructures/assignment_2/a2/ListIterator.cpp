#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	//complexity theta(n)
	// it needs to traverse the list in order to initialize the head and tail pointers
	this->head = this->list.head;
	this->tail = this->list.tail;
}

void ListIterator::first() {
	//complexity theta(1)
	this->head = this->list.head;
}

void ListIterator::next() {
	//complexity theta(1) 
	if (valid())
		this->head = this->head->next;
	else
		throw std::exception("Invalid");

}

bool ListIterator::valid() const {
	//complexity theta(1)
	return head != nullptr;
}

TElem ListIterator::getCurrent() const {
	//complexity theta(1)
	if (!valid())
		throw std::exception("Invalid");

	return head->data;
}

void ListIterator::jumpForward(int k)
{
	//complexity theta(k)
	if (k <= 0)
		throw std::exception("K is <=0");
	for (int i=0; i<k; i++)
		if (valid())
			this->head = this->head->next;
		else
			throw std::exception("Invalid");
}

