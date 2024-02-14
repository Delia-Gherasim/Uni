#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

BakeryDynamicArray* createBakeryDynamicArray(int capacity)
{
	BakeryDynamicArray* dynamicArray = malloc(sizeof(BakeryDynamicArray));

	if (dynamicArray == NULL)
		return NULL;

	dynamicArray->capacity = capacity;
	dynamicArray->size = 0;
	dynamicArray->elements = malloc(capacity * sizeof(TElem));

	if (dynamicArray->elements == NULL)
		return NULL;

	return dynamicArray;
}

void addElementToBakeryDynamicArray(BakeryDynamicArray* dynamicArray, TElem element)
{
	if (dynamicArray->size == dynamicArray->capacity)
		resizeBakeryDynamicArray(dynamicArray);

	dynamicArray->elements[dynamicArray->size] = element;
	dynamicArray->size++;
}


void resizeBakeryDynamicArray(BakeryDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	int cap = dynamicArray->capacity * 2;

	dynamicArray->capacity *= 2;
	void* aux = realloc(dynamicArray->elements, cap * sizeof(TElem));

	if (aux == NULL)
		return;

	dynamicArray->capacity = cap;
	dynamicArray->elements = aux;
}

void destroyBakeryDynamicArray(BakeryDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	free(dynamicArray->elements);
	free(dynamicArray);
}

//Getters

int getBakeryDynamicArraySize(BakeryDynamicArray* dynamicArray)
{
	return dynamicArray->size;
}

int getBakeryDynamicArrayCapacity(BakeryDynamicArray* dynamicArray)
{
	return dynamicArray->capacity;
}

OperationDynamicArray* createOperationDynamicArray(int capacity)
{
	OperationDynamicArray* dynamicArray = malloc(sizeof(OperationDynamicArray));

	if (dynamicArray == NULL)
		return NULL;

	dynamicArray->capacity = capacity;
	dynamicArray->size = 0;
	dynamicArray->elements = malloc(capacity * sizeof(Operation));

	if (dynamicArray->elements == NULL)
		return NULL;

	return dynamicArray;
}

void addElementToOperationDynamicArray(OperationDynamicArray* dynamicArray, Operation element)
{
	if (dynamicArray->size == dynamicArray->capacity)
		resizeOperationDynamicArray(dynamicArray);

	dynamicArray->elements[dynamicArray->size] = element;
	dynamicArray->size++;
}


void resizeOperationDynamicArray(OperationDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	int cap = dynamicArray->capacity * 2;

	dynamicArray->capacity *= 2;
	void* aux = realloc(dynamicArray->elements, cap * sizeof(Operation));

	if (aux == NULL)
		return;

	dynamicArray->capacity = cap;
	dynamicArray->elements = aux;
}

void destroyOperationDynamicArray(OperationDynamicArray* dynamicArray)
{
	if (dynamicArray == NULL)
		return;

	free(dynamicArray->elements);
	free(dynamicArray);
}

int getOperationDynamicArraySize(OperationDynamicArray* dynamicArray)
{
	return dynamicArray->size;
}

int getOperationDynamicArrayCapacity(OperationDynamicArray* dynamicArray)
{
	return dynamicArray->capacity;
}