#pragma once

#include "Domain.h"
#include "DynamicArray.h"

BakeryDynamicArray* createRepository();

Material addMaterialToRepository(BakeryDynamicArray* repository, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

Material deleteMaterialFromRepository(BakeryDynamicArray* repository, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

Material updateMaterialNameInRepository(BakeryDynamicArray* repository, char* newName, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

Material updateMaterialSupplierInRepository(BakeryDynamicArray* repository, char* newSupplier, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

Material updateMaterialQuantityInRepository(BakeryDynamicArray* repository, int newQuantity, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);

Material updateMaterialExpirationDateInRepository(BakeryDynamicArray* repository, int newExpirationDay, int newExpirationMonth, int newExpirationYear, char* name, char* supplier);

int getIndexOfMaterialFromRepository(BakeryDynamicArray* repository, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear);
                                            
TElem* getAllMaterialsFromRepository(BakeryDynamicArray* repository);