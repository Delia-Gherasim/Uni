#ifndef STLVECTOR_H
#define STLVECTOR_H

#include "tutorials.h"
#include <vector>

template <typename Tutorial>
class STLVector
{
private:
    std::vector<Tutorial> elements;

public:
    STLVector(int capacity = 10);
    STLVector(const STLVector<Tutorial>& vector);
    STLVector<Tutorial>& operator=(const STLVector<Tutorial>& v);

    int getCapacity() const;
    int getSize() const;
    Tutorial getElement(int i) const;
    void add(const Tutorial& element);
    void delete_(const Tutorial& element);
    void update(const Tutorial& element);
};



#endif