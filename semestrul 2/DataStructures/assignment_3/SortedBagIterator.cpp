#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//complexity Theta(1)
	this->current = b.head;
}

TComp SortedBagIterator::getCurrent() {
	//complexity Theta(1)
	if (!this->valid())
		throw exception();
	return bag.elems[current].element;
}

bool SortedBagIterator::valid() {
	//complexity Theta(1)
	return current != -1;
}

void SortedBagIterator::next() {
	//complexity Theta(1)
	if (!this->valid())
		throw exception();
	else {
		this->current = this->bag.elems[current].next;
	}

}

void SortedBagIterator::first() {
	//complexity Theta(1)
	this->current = this->bag.head;
}
