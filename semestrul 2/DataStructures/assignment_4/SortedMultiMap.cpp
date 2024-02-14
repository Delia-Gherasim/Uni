#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
using namespace std;

const int DELETED = -11111;

SortedMultiMap::SortedMultiMap(Relation r) 
{   
    //complexity average=worst=best=theta(1)

    this->relation = r;
    this->capacity = 8001;
    this->length = 0;
    this->elements = new Node[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->elements[i].key = NULL_TVALUE;
        this->elements[i].values.clear();
        
    }
}

int SortedMultiMap::size() const 
{
    //complexity average=worst=best=theta(1)

    return this->length;
}

bool SortedMultiMap::isEmpty() const 
{
    //complexity average=worst=best=theta(1)

    return this->length == 0;
}

SMMIterator SortedMultiMap::iterator() const 
{
    //complexity average=worst=best=theta(1)

    return SMMIterator(*this);
}

int SortedMultiMap::hash(TKey key) const
{ 
   //complexity average=worst=best=theta(1)

    return abs(key) % this->capacity;
}

int SortedMultiMap::quadratic_probe(int hash_val, int i) const
{
    //complexity average=worst=best=theta(1)

    return (int)(hash_val + 0.5 * i + 0.5 * i) % this->capacity;
}

SortedMultiMap::~SortedMultiMap() 
{
    //complexity average=worst=best=theta(1)

    delete[] this->elements;
}

void SortedMultiMap::resize() 
{
    //complexity average=worst=best=theta(capacity)

    int old_capacity = this->capacity;
    Node* old_elements = this->elements;
    this->capacity *= 2;
    this->length = 0;
    this->elements = new Node[this->capacity];
    for (int i = 0; i < old_capacity; i++) {
        this->elements[i].key = NULL_TVALUE;
        this->elements[i].values.clear();
    }

    for (int i = 0; i < old_capacity; i++) {
        if (old_elements[i].key != NULL_TVALUE && old_elements[i].key != DELETED) {
            TKey currentKey = old_elements[i].key;
            vector<TValue> currentValues = old_elements[i].values;
            for (const auto& value : currentValues) {
                this->add(currentKey, value);
            }

        }
    }

    delete[] old_elements;
}

void SortedMultiMap::add(TKey c, TValue v) 
{
    // best complexity: O(1)   -> key already exists, no resize needed
    // worst and average complexity O(capacity) 

    if (this->length == this->capacity) {
        this->resize();
    }

    int index = this->hash(c);
    int i = 0;

    while (this->elements[index].key != NULL_TVALUE && this->elements[index].key != DELETED) {
        if (this->elements[index].key == c) {
            // Key already exists, store the new value
            this->elements[index].values.push_back(v);
            // Sort the values vector based on the key using the provided relation
            this->sortValues(this->elements[index].values);
            this->length++;
            return;
        }
        i++;
        index = this->quadratic_probe(this->hash(c), i);
    }

    // Key does not exist, create a new node and store the key-value pair
    this->elements[index].key = c;
    this->elements[index].values = { v };
    this->length++;
}

void SortedMultiMap::sortElements() 
{
    //worst=average=best complexity theta(length^2) 
    for (int i = 0; i < this->length - 1; i++) {
        for (int j = 0; j < this->length - i - 1; j++) {
            if (this->relation(this->elements[j].key, this->elements[j + 1].key)==false) {
                // Swap the elements if they are in the wrong order
                Node temp = this->elements[j];
                this->elements[j] = this->elements[j + 1];
                this->elements[j + 1] = temp;
            }
        }
    }
}

vector<TValue> SortedMultiMap::search(TKey c) const {
    // best time complexity O(1)
    //worst=average complexity O(capacity)
    vector<TValue> values;
    int i = 0;
    int hash_val = this->hash(c);
    while (i < this->capacity && this->elements[hash_val].key != NULL_TVALUE && this->elements[hash_val].key != DELETED) {
        if (this->elements[hash_val].key == c) {
            for (const auto& value : this->elements[hash_val].values) {
                values.push_back(value);
            }
        }
        i++;
        hash_val = this->quadratic_probe(this->hash(c), i);
    }
    return values;
}


bool SortedMultiMap::remove(TKey c, TValue v) 
{
    //best time complexity O(1) --> key is found at the first hashed index
    //worst= average complexity O(capacity)
    int index = this->hash(c);
    int i = 0;

    while (i < this->capacity && this->elements[index].key != NULL_TVALUE && this->elements[index].key != DELETED) {
        if (this->elements[index].key == c) {
            // Key matches, search for the value in the vector of values
            auto& values = this->elements[index].values;
            for (auto it = values.begin(); it != values.end(); ++it) {
                if (*it == v) {
                    values.erase(it); // Remove the value from the vector
                    if (values.empty()) {
                        // If the vector becomes empty, mark the key as deleted
                        this->elements[index].key = DELETED;
                    }
                    // Sort the values vector based on the relation
                    sort(values.begin(), values.end(), relation);
                    this->length--;
                    return true;
                }
            }
        }
        i++;
        index = this->quadratic_probe(this->hash(c), i);
    }

    // Key not found
    return false;
}

void SortedMultiMap::sortValues(std::vector<TValue>& values) 
{
    //worst=average=best complexity theta(values.size^2) 
    for (int i = 0; i < values.size() - 1; i++) {
        for (int j = 0; j < values.size() - i - 1; j++) {
            if (this->relation(values[j], values[j + 1])==false) {
                // Swap the elements if they are in the wrong order
                TValue temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

int SortedMultiMap::getValueRange() const
{
    if (this->isEmpty())
        return -1;
    int maxvalue = -11111;
    int minvalue = 99999;

    for (int i = 0; i < this->capacity; i++) {
        if (this->elements[i].key != NULL_TVALUE && !this->elements[i].key != DELETED) {
            const std::vector<TValue>& values = this->elements[i].values;
            for (const auto& value : values) {
                if (value > maxvalue)
                    maxvalue = value;
                if (value < minvalue)
                    minvalue = value;
            }
        }
    }

    return maxvalue - minvalue;

}