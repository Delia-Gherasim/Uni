#include "SMMIterator.h"
#include "SortedMultiMap.h"


SMMIterator::SMMIterator(const SortedMultiMap& map) : map(map) 
{
    //complexity average=worst=best=theta(1)
    this->current = 0;
    this->currentValueIndex = 0;
    this->validPosition();
}

void SMMIterator::validPosition() 
{
    //best time complexity O(1) -> this->current is already a valid position, meaning the key is not NULL_TVALUE
    while (this->current < this->map.capacity && (this->map.elements[this->current].key == NULL_TVALUE ||
            this->currentValueIndex >= this->map.elements[this->current].values.size())) {
        this->current++;
        this->currentValueIndex = 0;
    }
}

void SMMIterator::first() 
{
    //complexity average=worst=best=theta(1)
    this->current = 0;
    this->currentValueIndex = 0;
    this->validPosition();
}

void SMMIterator::next() 
{
    //complexity average=worst=best=theta(1)
    if (!this->valid()) {
        throw exception();
    }
    this->currentValueIndex++;
    this->validPosition();
}

bool SMMIterator::valid() const 
{
    //complexity average=worst=best=theta(1)
    return this->current < this->map.capacity && this->currentValueIndex < this->map.elements[this->current].values.size();
}

TElem SMMIterator::getCurrent() const 
{
    //complexity average=worst=best=theta(1)
    if (!this->valid()) {
        throw exception();
    }
    return make_pair(this->map.elements[this->current].key,
        this->map.elements[this->current].values[this->currentValueIndex]);
}
