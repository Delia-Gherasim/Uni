#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Repository.h"
#include "DynamicArray.h"


BakeryDynamicArray* sortMaterialsArraybyQuantity(BakeryDynamicArray* repository);

BakeryDynamicArray* getAllMaterialsController(BakeryDynamicArray* repository);

void addMaterialFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, char* name, char* supplier,int quantity, int expirationDay,int expirationMonth, int expirationYear);

void deleteMaterialFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

void updateMaterialSupplierFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, char* newSupplier, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

void updateMaterialQuantityFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, int newQuantity, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

void updateMaterialExpirationDateFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, int newExpirationDay,int newExpirationMonth, int newExpirationYear, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

BakeryDynamicArray* MaterialsCointainingGivenString(BakeryDynamicArray* repository, char* containedString, int currentDay, int currentMonth, int currentYear);

BakeryDynamicArray* MaterialsInShortSupply(BakeryDynamicArray* repository, int quantity);

int undoFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

int redoFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);
					
void initController(BakeryDynamicArray* repository);