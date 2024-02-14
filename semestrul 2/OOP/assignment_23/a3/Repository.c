#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "Repository.h"
#include "DynamicArray.h"
#include "Domain.h"

BakeryDynamicArray* createRepository()
{
	return createBakeryDynamicArray(2);
}

Material addMaterialToRepository(BakeryDynamicArray* repository, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	Material newMaterial;

	strcpy(newMaterial.name, name);
	strcpy(newMaterial.supplier, supplier);
	newMaterial.quantity = quantity;
	newMaterial.expirationDay = expirationDay;
	newMaterial.expirationMonth = expirationMonth;
	newMaterial.expirationYear = expirationYear;
	
	addElementToBakeryDynamicArray(repository, newMaterial);

	return newMaterial;
}

TElem* getAllMaterialsFromRepository(BakeryDynamicArray* repository)
{
	return repository->elements;
}

int getIndexOfMaterialFromRepository(BakeryDynamicArray* repository, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
	{
		if (!strcmp(getMaterialName(&repository->elements[i]), name) && !strcmp(getMaterialSupplier(&repository->elements[i]), supplier) && getMaterialExpirationDay(repository->elements[i]) ==expirationDay && getMaterialExpirationMonth(repository->elements[i]) ==expirationMonth && getMaterialExpirationYear(repository->elements[i]) ==expirationYear)
			return i;
	}
	return -1;
}

Material deleteMaterialFromRepository(BakeryDynamicArray* repository, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	int searchedIndex = getIndexOfMaterialFromRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Material searchedMaterial = repository->elements[searchedIndex];
	if (searchedIndex != -1)
	{
		for (int i = searchedIndex; i < getBakeryDynamicArraySize(repository) - 1; i++)
			repository->elements[i] = repository->elements[i + 1];

		repository->size--;
	}

	return searchedMaterial;
}

Material updateMaterialNameInRepository(BakeryDynamicArray* repository, char* newName, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	int searchedIndex = getIndexOfMaterialFromRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Material updatedMaterial = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		strcpy(repository->elements[searchedIndex].name, newName);

	return updatedMaterial;
}

Material updateMaterialSupplierInRepository(BakeryDynamicArray* repository, char* newSupplier, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	int searchedIndex = getIndexOfMaterialFromRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Material updatedMaterial = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		strcpy(repository->elements[searchedIndex].supplier, newSupplier);

	return updatedMaterial;
}

Material updateMaterialQuantityInRepository(BakeryDynamicArray* repository,	int newQuantity, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	int searchedIndex = getIndexOfMaterialFromRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Material updatedMaterial = repository->elements[searchedIndex];

	if (searchedIndex != -1)
		repository->elements[searchedIndex].quantity = newQuantity;

	return updatedMaterial;
}

Material updateMaterialExpirationDateInRepository(BakeryDynamicArray* repository, int newExpirationDay, int newExpirationMonth, int newExpirationYear, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	int searchedIndex = getIndexOfMaterialFromRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Material updatedMaterial = repository->elements[searchedIndex];

	if (searchedIndex != -1)
	{
		repository->elements[searchedIndex].expirationDay = newExpirationDay;
		repository->elements[searchedIndex].expirationMonth = newExpirationMonth;
		repository->elements[searchedIndex].expirationYear = newExpirationYear;
	}

	return updatedMaterial;
}