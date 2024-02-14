#include "DynamicVector.h"
#include "tutorials.h"
#include <iostream>

template <typename T>
DynamicVector<T>::DynamicVector(int capacity) : capacity{ capacity }, size{ 0 }
{
	this->elements = new T[this->capacity];
}
template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elements;
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;

	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vector.elements[i];
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& vector)
{
	if (this == &vector)
		return *this;

	this->size = vector.size;
	this->capacity = vector.capacity;

	delete[] this->elements;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vector.elements[i];

	return *this;
}
template <typename T>
void DynamicVector<T>::resize()
{
	this->capacity *= 2;

	T* newData = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
		newData[i] = this->elements[i];

	delete[] this->elements;

	this->elements = newData;
}

template <typename T>
int DynamicVector<T>::getCapacity() const
{
	return this->capacity;
}
template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}
template <typename T>
T DynamicVector<T>::getElement(int i) const
{
	return this->elements[i];
}
template <typename T>
void DynamicVector<T>::add(const T& element)
{

	if (this->size >= this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
	
}

template <typename T>
void DynamicVector<T>::delete_(const T& element)
{
	int index_of_element_to_be_deleted = -1;
	for (int i = 0; i < this->size; i++)
	{
		if ((element.getTitle() == this->elements[i].getTitle()) && (element.getPresenter() == this->elements[i].getPresenter())) {
			index_of_element_to_be_deleted = i;
		}
	}
	if (index_of_element_to_be_deleted != -1) {
		for (int i = index_of_element_to_be_deleted; i < this->size - 1; i++) {
			this->elements[i] = this->elements[i + 1];
		}
		
		this->size--;
	}
}


template <typename T>
void DynamicVector<T>::update(const T& element)
{
	for (int i = 0; i < this->size; i++)
		if (this->elements[i].getTitle() == element.getTitle())
		{

			std::string temporary_hold_new_presenter = element.getPresenter();
			this->elements[i].setPresenter(temporary_hold_new_presenter);

			std::string temporary_hold_new_link = element.getLink();
			this->elements[i].setLink(temporary_hold_new_link);

			int temporary_hold_duration = element.getDurationMinutes();
			this->elements[i].setDurationMinutes(temporary_hold_duration);

			temporary_hold_duration = element.getDurationSeconds();
			this->elements[i].setDurationSeconds(temporary_hold_duration);

			int temporary_hold_number_of_likes = element.getNumberOfLikes();
			this->elements[i].setNumberOfLikes(temporary_hold_number_of_likes);

		}
}