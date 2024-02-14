#pragma once
#include "Domain.h"

typedef struct
{
	TElem* elements;
	int size, capacity;
} BakeryDynamicArray;

typedef Material TElem;

BakeryDynamicArray* createBakeryDynamicArray(int capacity);

void addElementToBakeryDynamicArray(BakeryDynamicArray* dynamicArray, TElem element);
void resizeBakeryDynamicArray(BakeryDynamicArray* dynamicArray);
int getBakeryDynamicArraySize(BakeryDynamicArray* dynamicArray);
int getBakeryDynamicArrayCapacity(BakeryDynamicArray* dynamicArray);
void destroyBakeryDynamicArray(BakeryDynamicArray* dynamicArray);

typedef struct
{
	Operation* elements;
	int size, capacity;
} OperationDynamicArray;

OperationDynamicArray* createOperationDynamicArray(int capacity);

void addElementToOperationDynamicArray(OperationDynamicArray* dynamicArray, Operation element);
void resizeOperationDynamicArray(OperationDynamicArray* dynamicArray);
int getOperationDynamicArraySize(OperationDynamicArray* dynamicArray);
int getOperationDynamicArrayCapacity(OperationDynamicArray* dynamicArray);
void destroyOperationDynamicArray(OperationDynamicArray* dynamicArray);