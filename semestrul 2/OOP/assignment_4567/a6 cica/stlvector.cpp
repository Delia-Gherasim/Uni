#include "stlvector.h"

template <typename Tutorial>
STLVector<Tutorial>::STLVector(int capacity)
    : elements(capacity)
{
}

template <typename Tutorial>
STLVector<Tutorial>::STLVector(const STLVector<Tutorial>& vector)
    : elements(vector.elements)
{
}


template <typename Tutorial>
STLVector<Tutorial>& STLVector<Tutorial>::operator=(const STLVector<Tutorial>& vector)
{
    if (this != &vector) {
        this->elements = vector.elements;
    }
    return *this;
}

template <typename Tutorial>
int STLVector<Tutorial>::getCapacity() const
{
    return elements.capacity();
}

template <typename Tutorial>
int STLVector<Tutorial>::getSize() const
{
    return elements.size();
}

template <typename Tutorial>
Tutorial STLVector<Tutorial>::getElement(int i) const
{
    return elements[i];
}

template <typename Tutorial>
void STLVector<Tutorial>::add(const Tutorial& element)
{
    elements.push_back(element);
}

template <typename Tutorial>
void STLVector<Tutorial>::delete_(const Tutorial& element)
{
    elements.erase(std::remove_if(elements.begin(), elements.end(), [&element](const Tutorial& tutorial_to_check) {

        return (element.getTitle() == tutorial_to_check.getTitle()) && (element.getPresenter() == tutorial_to_check.getPresenter());
        }), elements.end());
}

template <typename Tutorial>
void STLVector<Tutorial>::update(const Tutorial& element)
{
    auto iterator_value = std::find_if(elements.begin(), elements.end(), [&element](const Tutorial& tutorial_to_check) {
        return (element.getTitle() == tutorial_to_check.getTitle()); });
    if (iterator_value != elements.end()) {
        *iterator_value = element;
    }
}