#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cstdlib>
#include <exception>
#include <iostream>
using namespace std;


SortedBag::SortedBag(Relation r) {
    //complexity Theta(n), where n is the capacity of the SortedBag
    this->head = -1;
    this->capacity = 100;
    this->firstEmpty = 0;
    this->Size = 0;
    this->rel = r;
    this->elems = new SLLANode[this->capacity];

    for (int i = 0; i < this->capacity - 1; i++) {
        this->elems[i].next = i + 1;
        this->elems[i].frequency = 0;
    }

    this->elems[this->capacity - 1].next = -1;
}

void SortedBag::add(TComp e) {
    //complexity Theta(n), where n is the size of the SortedBag
    // 
    // 
    // If the list is empty, insert the element as the first node
    if (this->head == -1) {
        this->head = this->firstEmpty;
        this->firstEmpty = this->elems[firstEmpty].next;
        this->elems[head].element = e;
        this->elems[head].frequency = 1;
        this->elems[head].next = -1;
        this->Size++;
    }
    else {
        // If the list is full, resize it
        if (this->Size == this->capacity) {
            this->resize();
        }

        int currentNode = this->head;
        int prevNode = -1;

        // Traverse the list to find the correct position for the new element
        while (currentNode != -1 && this->rel(this->elems[currentNode].element, e)) {
            prevNode = currentNode;
            currentNode = this->elems[currentNode].next;
        }

        // Insert the new element in the list
        int newEmpty = this->firstEmpty;
        this->firstEmpty = this->elems[firstEmpty].next;
        this->elems[newEmpty].element = e;
        this->elems[newEmpty].frequency = 1;

        if (currentNode == -1) {
            // The new element should be added at the end of the list
            this->elems[newEmpty].next = -1;
            if (prevNode == -1) {
                this->head = newEmpty;
            }
            else {
                this->elems[prevNode].next = newEmpty;
            }
        }
        else {
            // The new element should be added before the current node
            this->elems[newEmpty].next = currentNode;
            if (prevNode == -1) {
                this->head = newEmpty;
            }
            else {
                this->elems[prevNode].next = newEmpty;
            }
        }

        this->Size++;
    }
}

bool SortedBag::remove(TComp e) {
    //complexity Theta(n), where n is the size of the SortedBag
    //

    //If the list is empty, return false
    if (this->head == -1) {
        return false;
    }

    int currentNode = this->head;
    int prevNode = -1;

    //Traverse the list to find the position of the element
    while (currentNode != -1 && this->elems[currentNode].element != e) {
        prevNode = currentNode;
        currentNode = this->elems[currentNode].next;
    }

    //If we reach the end of the list without finding the element, return false
    if (currentNode == -1) {
        return false;
    }

    //If the frequency of the element is bigger than 1, reduce the frequency
    if (this->elems[currentNode].frequency > 1) {
        this->elems[currentNode].frequency--;
    }
    else {
        if (prevNode == -1) {
            this->head = this->elems[currentNode].next;
        }
        else {
            this->elems[prevNode].next = this->elems[currentNode].next;
        }

        // update the next node of the removed element and the firstEmpty
        int nextNode = this->elems[currentNode].next;
        this->elems[currentNode].next = this->firstEmpty;
        this->firstEmpty = currentNode;

        if (prevNode == -1) {
            this->head = nextNode;
        }
        else {
            this->elems[prevNode].next = nextNode;
        }
    }

    this->Size--;

    return true;

}


bool SortedBag::search(TComp elem) const {
    //complexity worst=average Theta(n), where n is the size of the SortedBag
    //           best Theta(1), element is on the first position or the list is empty
    int currentNode = this->head;

    while (currentNode != -1 && this->rel(this->elems[currentNode].element, elem)) {
        if (this->elems[currentNode].element == elem) {
            return true;
        }
        currentNode = this->elems[currentNode].next;
    }

    return false;

}
int SortedBag::nrOccurrences(TComp elem) const {
    //complexity best=worst=average Theta(n), where n is the size of the SortedBag
    //          
    int currentNode = this->head;
    int count = 0;

    while (currentNode != -1 && this->rel(this->elems[currentNode].element, elem)) {
        if (this->elems[currentNode].element == elem) {
            count += this->elems[currentNode].frequency;
        }
        currentNode = this->elems[currentNode].next;
    }

    return count;
}

void SortedBag::resize() {
    //complexity best=worst=average Theta(n), where n is the capacity of the SortedBag
    this->capacity *= 2;
    SLLANode* newElems = new SLLANode[this->capacity];
    for (int i = 0; i < this->capacity / 2; i++) {
        newElems[i] = this->elems[i];
    }
    for (int i = this->capacity / 2; i < this->capacity - 1; i++) {
        newElems[i].next = i + 1;
    }
    newElems[this->capacity - 1].next = -1;
    delete[] this->elems;
    this->elems = newElems;
    this->firstEmpty = this->capacity / 2;
}


int SortedBag::size() const {
    //complexity best=worst=average Theta(1)
    return this->Size;
}



bool SortedBag::isEmpty() const {
    //complexity best=worst=average Theta(1)
    return this->Size == 0;
}


SortedBagIterator SortedBag::iterator() const {
    //complexity best=worst=average Theta(1)
    return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    //complexity best=worst=average Theta(n)
    delete[] this->elems;
}

int SortedBag::elementsWithThisFrequency(int frequency) const {
    //complexity theta(n^2) //n is the size
                            //^2 because it calld the nrOccurences function that has complexity O(n)
    if (frequency <= 0)
        throw exception();

    int currentNode = this->head;
    int count = 0;
    int previous_checked = -1;
    while (currentNode != -1) {
        if (previous_checked != this->elems[currentNode].element) {
            if (this->nrOccurrences(this->elems[currentNode].element) == frequency)
                count++;
        }
        previous_checked = this->elems[currentNode].element;
        currentNode = this->elems[currentNode].next;


        return count;
    }
}