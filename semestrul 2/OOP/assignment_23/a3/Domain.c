#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Domain.h"

char* getMaterialName(TElem* material)
{
	return material->name;
}

char* getMaterialSupplier(TElem* material)
{
	return material->supplier;
}

int getMaterialQuantity(TElem material)
{
	return material.quantity;
}

int getMaterialExpirationDay(TElem material)
{
	return material.expirationDay;
}

int getMaterialExpirationMonth(TElem material)
{
	return material.expirationMonth;
}

int getMaterialExpirationYear(TElem material)
{
	return material.expirationYear;
}

void setMaterialName(TElem* material, char* newName)
{
	strcpy(material->name, newName);
}

void setMaterialSupplier(TElem* material, char* newSupplier)
{
	strcpy(material->supplier, newSupplier);
}

void setMaterialQuantity(TElem material, int newQuantity)
{
	material.quantity = newQuantity;
}

void setMaterialExpirationDay(TElem material, int NewExpirationDay)
{
	material.expirationDay = NewExpirationDay;
}

void setMaterialExpirationMonth(TElem material, int newExpirationMonth)
{
	material.expirationMonth = newExpirationMonth;
}

void setMaterialExpirationYear(TElem material, int newExpirationYear)
{
	material.expirationYear = newExpirationYear;
}




char* getUndoOperation(Operation* undoOperation)
{
	return undoOperation->operation;
}

Material getUndoOperationMaterial(Operation undoOperation)
{
	return undoOperation.material;
}

void setUndoOperation(Operation* undoOperation, char* newUndoOperation)
{
	strcpy(undoOperation->operation, newUndoOperation);
}

void setUndoOperationMaterial(Operation undoOperation, Material newUndoOperationMaterial)
{
	undoOperation.material = newUndoOperationMaterial;
}

char* getRedoOperation(Operation* redoOperation)
{
	return redoOperation->operation;
}

Material getRedoOperationMaterial(Operation redoOperation)
{
	return redoOperation.material;
}

void setRedoOperation(Operation* redoOperation, char* newRedoOperation)
{
	strcpy(redoOperation->operation, newRedoOperation);
}

void setRedoOperationMaterial(Operation redoOperation, Material newRedoOperationMaterial)
{
	redoOperation.material = newRedoOperationMaterial;
}