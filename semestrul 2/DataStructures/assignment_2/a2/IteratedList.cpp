
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"
#include <iostream>

IteratedList::IteratedList() {
	//complexity average=worst=best=theta(1)
	this->head = nullptr;
	this->tail = nullptr;
	this->count = 0;
}

int IteratedList::size() const {
	//complexity average=worst=best=theta(1)
	return this->count;
	return 0;
}

bool IteratedList::isEmpty() const {
	//complexity average=worst=best=theta(1)
	if (this->count == 0)
		return true;
	return false;
}

ListIterator IteratedList::first() const {
	//complexity average=worst=best=theta(1)
	ListIterator it(*this);
	it.first();
	return it;
}

TElem IteratedList::getElement(ListIterator pos) const {
	//complexity average=worst=best=theta(1)
	if (!pos.valid())
		throw std::exception("Invalid");

	return pos.getCurrent();
	return NULL_TELEM;
}

TElem IteratedList::remove(ListIterator& pos) {
	//complexity average=worst=best=theta(1)
	if (!pos.valid())
		throw std::exception("Invalid ");

	TElem removed = pos.getCurrent();
	Node* nodeToRemove = pos.head;

	if (nodeToRemove == head) {
		head = head->next;
		if (head != nullptr)
			head->prev = nullptr;
	}
	else {
		nodeToRemove->prev->next = nodeToRemove->next;
		if (nodeToRemove == tail) {
			tail = tail->prev;
			if (tail != nullptr)
				tail->next = nullptr;
		}
		else {
			nodeToRemove->next->prev = nodeToRemove->prev;
		}
	}
	pos.next();
	delete nodeToRemove;
	count--;

	return removed;
}

ListIterator IteratedList::search(TElem e) const{
	//complexity average: theta(n), best theta(1), worst: theta(n)
	//as it may need to traverse the entire list to find the element e
	ListIterator it(*this);
	it.first();
	while (it.valid()) 
	{
		if (it.getCurrent() == e)
		{
			return it;
			//break;
		}
		it.next();
	}
	return it;
	throw std::exception("Element not found");
	
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
	//complexity average=worst=best=theta(1)
	if (!pos.valid())
		throw std::exception("Invalid");

	TElem old = pos.getCurrent();
	pos.head->data = e;
	return old;
	return NULL_TELEM;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
	//complexity average=worst=best=theta(1)
	if (!pos.valid())
		throw std::exception("Invalid");

	if (pos.head == tail) {
		addToEnd(e);
		pos.head = tail;
	}
	else {
		Node* newNode = new Node{ e, pos.head, pos.head->next };
		pos.head->next->prev = newNode;
		pos.head->next = newNode;
		pos.head = newNode;
		count++;
	}
 
}

void IteratedList::addToBeginning(TElem e) {
	//complexity theta(1)
	Node* newNode = new Node{ e, nullptr, head };
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		head = newNode;
	}
	count++;
}

void IteratedList::addToEnd(TElem e) {
	//complexity theta(1)
	Node* newNode = new Node{ e, tail, nullptr };
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	count++;
	
}

IteratedList::~IteratedList() {
	//complexity theta(n)
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}

}
