#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;


SortedMultiMap::SortedMultiMap(Relation r) {
    this->nrofpairs = 0;
    this->capacity = 53;
    this->elems = new List[this->capacity];
    this->Relation = R;
}

SortedMultiMap::~SortedMultiMap() {
    delete[] this->elems;
}

void SortedMultiMap::add(TKey newKey, TValue newValue) {
    int pos = hashFunction(newKey);
    int i = 0;
    while (this->elems[pos].head != NULL && i < this->capacity) {
        pos = (pos + i * i) % this->capacity;
        i++;
    }
    if (i == this->capacity) {
        throw std::overflow_error("No empty slot available");
    }
    this->elems[pos].temp = this->elems[pos].head;
    bool wasAdded = false;
    while (this->elems[pos].temp != NULL && wasAdded == false) {
        if ((this->Relation(newKey, this->elems[pos].temp->key)) == true) {
            this->elems[pos].addNodeBefore(newKey, newValue, this->elems[pos].temp);
            wasAdded = true;
        }
        else {
            this->elems[pos].temp = this->elems[pos].temp->next;
        }
    }
    if (this->elems[pos].head == NULL) {
        this->elems[pos].addNodeFirst(newKey, newValue);
    }
    else if (wasAdded == false) {
        this->elems[pos].addNodeEnd(newKey, newValue);
    }
    this->nrofpairs++;
}

void SortedMultiMap::remove(std::string newKey, std::string newValue) {
    int pos = hashFunction(newKey);
    int i = 0;
    while (this->elems[pos].head != NULL && i < this->capacity) {
        if (this->elems[pos].head->key == newKey && this->elems[pos].head->value == newValue) {
            this->elems[pos].delNode(newKey, newValue);
            this->nrofpairs--;
            return;
        }
        pos = (pos + i * i) % this->capacity;
        i++;
    }
}

bool SortedMultiMap::search(TKey c) {
    int pos = hashFunction(c);
    int i = 0;
    while (this->elems[pos].head != NULL && i < this->capacity) {
        if (this->elems[pos].head->key == c) {
            l.push_back(this->elems[pos].head->value);
        }
        pos = (pos + i * i) % this->capacity;
        i++;
    }
    if (l.size() > 0) {
        return true;
    }
    else {
        return false;
    }
}

void SortedMultiMap::keys(std::vector<std::string>& l) {
    for (int i = 0; i < this->getCapacity(); i++) {
        this->elems[i].temp = this->elems[i].head;
        while (this->elems[i].temp != NULL) {
            bool exists = false;
            for (auto k : l) {
                if (k == this->elems[i].temp




vector<TValue> SortedMultiMap::search(TKey c) const {
	//TODO - Implementation
	return vector<TValue>();
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
    return false;
}


int SortedMultiMap::size() const {
	//TODO - Implementation
	return 0;
}

bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation
	return false;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation
}
