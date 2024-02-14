#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>

#include "Repository.h"
#include "DynamicArray.h"
#include "Controller.h"


BakeryDynamicArray *sortMaterialsArraybyQuantity(BakeryDynamicArray *repository)
{
    BakeryDynamicArray* materialsSortedAscendingByTheirQuantity = createBakeryDynamicArray(2);

	for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
	{
		addElementToBakeryDynamicArray(materialsSortedAscendingByTheirQuantity, repository->elements[i]);
	}

	for (int i = 0; i < materialsSortedAscendingByTheirQuantity->size - 1; i++)
		for (int j = i + 1; j < materialsSortedAscendingByTheirQuantity->size; j++)
		{
			if (materialsSortedAscendingByTheirQuantity->elements[i].quantity > materialsSortedAscendingByTheirQuantity->elements[j].quantity)
			{
				Material aux = materialsSortedAscendingByTheirQuantity->elements[i];
				materialsSortedAscendingByTheirQuantity->elements[i] = materialsSortedAscendingByTheirQuantity->elements[j];
				materialsSortedAscendingByTheirQuantity->elements[j] = aux;
			}
		}
	return materialsSortedAscendingByTheirQuantity;
}

BakeryDynamicArray* getAllMaterialsController(BakeryDynamicArray* repository)
{
	BakeryDynamicArray* allMaterials = createBakeryDynamicArray(2);

	for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
	{
		addElementToBakeryDynamicArray(allMaterials, repository->elements[i]);
	}

	return allMaterials;
}

void addMaterialFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	redoArray->size = 0;
	BakeryDynamicArray* allMaterials = createBakeryDynamicArray(2);

	for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
	{
		addElementToBakeryDynamicArray(allMaterials, repository->elements[i]);
	}

	int materialExists = 0;
	for (int i = 0; i < getBakeryDynamicArraySize(allMaterials); i++)
	{
		if (strcmp(getMaterialName(&allMaterials->elements[i]), name) ==0)
		{
				if (strcmp(getMaterialSupplier(&allMaterials->elements[i]),supplier) == 0)
					if ((getMaterialExpirationDay(allMaterials->elements[i]) == expirationDay) && (getMaterialExpirationMonth(allMaterials->elements[i]) == expirationMonth) && (getMaterialExpirationYear(allMaterials->elements[i]) == expirationYear))
					{
						repository->elements[i].quantity += quantity;
						materialExists = 1;
					}

		}
	}

	if (!materialExists)
	{
		Material addedMaterial = addMaterialToRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
		Operation undoOperation;
		strcpy(undoOperation.operation, "add");
		undoOperation.material = addedMaterial;

		addElementToOperationDynamicArray(undoArray, undoOperation);
	}

	destroyBakeryDynamicArray(allMaterials);
}


void deleteMaterialFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	redoArray->size = 0;
	Material deletedMaterial = deleteMaterialFromRepository(repository, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);

	Operation undoOperation;
	strcpy(undoOperation.operation, "delete");
	undoOperation.material = deletedMaterial;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}


void updateMaterialSupplierFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, char* newSupplier, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	redoArray->size = 0;

	Material updatedMaterial = updateMaterialSupplierInRepository(repository, newSupplier, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.material = updatedMaterial;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

void updateMaterialQuantityFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, int newQuantity, char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	redoArray->size = 0;

	Material updatedMaterial = updateMaterialQuantityInRepository(repository, newQuantity, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.material = updatedMaterial;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

void updateMaterialExpirationDateFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, int newExpirationDay, int newExpirationMonth, int newExpirationYear ,char* name, char* supplier, int quantity, int expirationDay, int expirationMonth, int expirationYear)
{
	redoArray->size = 0;

	Material updatedMaterial = updateMaterialQuantityInRepository(repository, newExpirationDay, newExpirationMonth, newExpirationYear, name, supplier, quantity, expirationDay, expirationMonth, expirationYear);
	Operation undoOperation;
	strcpy(undoOperation.operation, "update");
	undoOperation.material = updatedMaterial;

	addElementToOperationDynamicArray(undoArray, undoOperation);
}

BakeryDynamicArray* MaterialsCointainingGivenString(BakeryDynamicArray* repository, char* containedString, int currentDay, int currentMonth, int currentYear)
{
	BakeryDynamicArray* allMaterials = createBakeryDynamicArray(2);
	for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
		addElementToBakeryDynamicArray(allMaterials, repository->elements[i]);
	BakeryDynamicArray* matchedMaterials = createBakeryDynamicArray(2);

	if (!strcmp(containedString, "") || !strcmp(containedString, "\n"))
	{
		//sortMaterialsArrayByDate(allMaterials, expirationDay, expirationMonth, expirationYear);
		for (int i = 0; i < getBakeryDynamicArraySize(allMaterials); i++)
		{
			if (getMaterialExpirationYear(allMaterials->elements[i]) < currentYear)
			{
				addElementToBakeryDynamicArray(matchedMaterials, allMaterials->elements[i]);
			}
			else if ((getMaterialExpirationYear(allMaterials->elements[i]) == currentYear))
			{
				if (getMaterialExpirationMonth(allMaterials->elements[i]) > currentMonth)
				{
					addElementToBakeryDynamicArray(matchedMaterials, repository->elements[i]);
				}
				else if (getMaterialExpirationMonth(allMaterials->elements[i]) == currentMonth && getMaterialExpirationDay(allMaterials->elements[i] )>= currentDay)
				{
					addElementToBakeryDynamicArray(matchedMaterials, allMaterials->elements[i]);
				}
			}
		}
		destroyBakeryDynamicArray(allMaterials);
		return allMaterials;
	}
	else
	{
		for (int i=0; i<getBakeryDynamicArraySize(allMaterials); i++)
			if (strstr(getMaterialName(&allMaterials->elements[i]), containedString)!=NULL)
				for (int i = 0; i < getBakeryDynamicArraySize(allMaterials); i++)
				{
					if (getMaterialExpirationYear(allMaterials->elements[i]) < currentYear)
					{
						addElementToBakeryDynamicArray(matchedMaterials, allMaterials->elements[i]);
					}
					else if ((getMaterialExpirationYear(allMaterials->elements[i]) == currentYear))
					{
						if (getMaterialExpirationMonth(allMaterials->elements[i]) > currentMonth)
						{
							addElementToBakeryDynamicArray(matchedMaterials, repository->elements[i]);
						}
						else if (getMaterialExpirationMonth(allMaterials->elements[i]) == currentMonth && getMaterialExpirationDay(allMaterials->elements[i]) >= currentDay)
						{
							addElementToBakeryDynamicArray(matchedMaterials, allMaterials->elements[i]);
						}
					}
				}
		destroyBakeryDynamicArray(allMaterials);
		return allMaterials;
	}
	}
	

BakeryDynamicArray* MaterialsInShortSupply(BakeryDynamicArray* repository, int quantity)
{
	BakeryDynamicArray* allMaterials = createBakeryDynamicArray(2);

	for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
	{
		addElementToBakeryDynamicArray(allMaterials, repository->elements[i]);
	}

	BakeryDynamicArray* matchedMaterials = createBakeryDynamicArray(2);

	for (int i = 0; i < getBakeryDynamicArraySize(allMaterials); i++)
	{
		if (getMaterialQuantity(allMaterials->elements[i]) < quantity)
			addElementToBakeryDynamicArray(matchedMaterials, allMaterials->elements[i]);
	}

	destroyBakeryDynamicArray(allMaterials);

	return matchedMaterials;
}

int undoFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	// 0 return -> success
	// 1 return -> nothing to undo (undoArray has size 0)
	if (getOperationDynamicArraySize(undoArray) == 0)
		return 1;

	Operation undoOperation = undoArray->elements[getOperationDynamicArraySize(undoArray) - 1];


	if (!strcmp(undoOperation.operation, "add"))
	{
		addElementToOperationDynamicArray(redoArray, undoOperation);
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		deleteMaterialFunction(repository, tempArray, tempArray, undoOperation.material.name, undoOperation.material.supplier, undoOperation.material.quantity, undoOperation.material.expirationDay, undoOperation.material.expirationMonth, undoOperation.material.expirationYear);
		undoArray->size--;
		destroyOperationDynamicArray(tempArray);
		return 0;
	}

	if (!strcmp(undoOperation.operation, "delete"))
	{
		addElementToOperationDynamicArray(redoArray, undoOperation);
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		addMaterialFunction(repository, tempArray, tempArray, undoOperation.material.name, undoOperation.material.supplier, undoOperation.material.quantity, undoOperation.material.expirationDay, undoOperation.material.expirationMonth, undoOperation.material.expirationYear);
		undoArray->size--;
		destroyOperationDynamicArray(tempArray);

		return 0;
	}

	if (!strcmp(undoOperation.operation, "update"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		Material materialToDelete;

		for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
		{
			if (strcmp(getMaterialName(&repository->elements[i]), getMaterialName(&undoOperation.material))==0)
			{
				Material redoMaterial;

				strcpy(redoMaterial.name, repository->elements[i].name);
				strcpy(redoMaterial.supplier, repository->elements[i].supplier);
				redoMaterial.quantity = repository->elements[i].quantity;
				redoMaterial.expirationDay = repository->elements[i].expirationDay;
				redoMaterial.expirationMonth = repository->elements[i].expirationMonth;
				redoMaterial.expirationYear = repository->elements[i].expirationYear;

				Operation newRedoOperation;
				strcpy(newRedoOperation.operation, "update");
				newRedoOperation.material = redoMaterial;

				addElementToOperationDynamicArray(redoArray, newRedoOperation);

				strcpy(materialToDelete.name, repository->elements[i].name);
				strcpy(materialToDelete.supplier, repository->elements[i].supplier);
				materialToDelete.quantity = repository->elements[i].quantity;
				materialToDelete.expirationDay = repository->elements[i].expirationDay;
				materialToDelete.expirationMonth = repository->elements[i].expirationMonth;
				materialToDelete.expirationYear = repository->elements[i].expirationYear;

				break;
			}
		}

		deleteMaterialFunction(repository, tempArray, tempArray, materialToDelete.name, materialToDelete.supplier, materialToDelete.quantity, materialToDelete.expirationDay, materialToDelete.expirationMonth, materialToDelete.expirationYear);
		addMaterialFunction(repository, tempArray, tempArray, undoOperation.material.name, undoOperation.material.supplier, undoOperation.material.quantity, undoOperation.material.expirationDay, undoOperation.material.expirationMonth, undoOperation.material.expirationYear);
		undoArray->size--;

		destroyOperationDynamicArray(tempArray);
		
		return 0;
	}
}

int redoFunction(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	if (getOperationDynamicArraySize(redoArray) == 0)
		return 1;

	Operation redoOperation = redoArray->elements[getOperationDynamicArraySize(redoArray) - 1];

	if (!strcmp(redoOperation.operation, "add"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		addMaterialFunction(repository, undoArray, tempArray,redoOperation.material.name, redoOperation.material.supplier, redoOperation.material.quantity, redoOperation.material.expirationDay, redoOperation.material.expirationMonth, redoOperation.material.expirationYear);
		redoArray->size--;
		destroyOperationDynamicArray(tempArray);
		return 0;
	}

	if (!strcmp(redoOperation.operation, "delete"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		deleteMaterialFunction(repository, undoArray, tempArray, redoOperation.material.name, redoOperation.material.supplier, redoOperation.material.quantity, redoOperation.material.expirationDay, redoOperation.material.expirationMonth, redoOperation.material.expirationYear);	
		redoArray->size--;
		destroyOperationDynamicArray(tempArray);
		return 0;
	}

	if (!strcmp(redoOperation.operation, "update"))
	{
		OperationDynamicArray* tempArray = createOperationDynamicArray(2);
		Material materialToDelete;

		for (int i = 0; i < getBakeryDynamicArraySize(repository); i++)
		{
			if (strcmp(getMaterialName(&repository->elements[i]), getMaterialName(&redoOperation.material))==0)
			{
				Material undoMaterial;
				strcpy(undoMaterial.name, repository->elements[i].name);
				strcpy(undoMaterial.supplier, repository->elements[i].supplier);
				undoMaterial.quantity = repository->elements[i].quantity;
				undoMaterial.expirationDay = repository->elements[i].expirationDay;
				undoMaterial.expirationMonth = repository->elements[i].expirationMonth;
				undoMaterial.expirationYear = repository->elements[i].expirationYear;

				Operation newUndoOperation;
				strcpy(newUndoOperation.operation, "update");
				newUndoOperation.material = undoMaterial;

				addElementToOperationDynamicArray(undoArray, newUndoOperation);

				strcpy(materialToDelete.name, repository->elements[i].name);
				strcpy(materialToDelete.supplier, repository->elements[i].supplier);
				materialToDelete.quantity = repository->elements[i].quantity;
				materialToDelete.expirationDay = repository->elements[i].expirationDay;
				materialToDelete.expirationMonth = repository->elements[i].expirationMonth;
				materialToDelete.expirationYear = repository->elements[i].expirationYear;
				break;
			}
		}

		deleteMaterialFunction(repository, tempArray, tempArray, materialToDelete.name, materialToDelete.supplier, materialToDelete.quantity, materialToDelete.expirationDay, materialToDelete.expirationMonth, materialToDelete.expirationYear);
		addMaterialFunction(repository, tempArray, tempArray, redoOperation.material.name, redoOperation.material.supplier, redoOperation.material.quantity, redoOperation.material.expirationDay, redoOperation.material.expirationMonth, redoOperation.material.expirationYear			);

		redoArray->size--;

		destroyOperationDynamicArray(tempArray);
	}
}

void initController(BakeryDynamicArray* repository)
{
	OperationDynamicArray* undoArray = createOperationDynamicArray(2);
	OperationDynamicArray* redoArray = createOperationDynamicArray(2);

	addMaterialFunction(repository, undoArray, redoArray, "flour", "mopan", 50, 9, 10, 2023);
	addMaterialFunction(repository, undoArray, redoArray, "cacao ","mopan", 2, 3, 3, 2023);
	addMaterialFunction(repository, undoArray, redoArray, "eggs"," lidl ",30, 4, 4, 2023);
	addMaterialFunction(repository, undoArray, redoArray, "sugar ","lidl", 2, 3, 3, 2023);
	addMaterialFunction(repository, undoArray, redoArray, "salt ","lidl" ,4 ,8, 2, 2023);
	addMaterialFunction(repository, undoArray, redoArray, "chocolate"," kaufland", 5 ,20 ,11 ,2021);
	addMaterialFunction(repository, undoArray, redoArray, "vanilla_extract"," selgros", 25, 14, 4, 2023);
	addMaterialFunction(repository, undoArray, redoArray, "oil"," kaufland",20, 8, 9, 2024);
	addMaterialFunction(repository, undoArray, redoArray, "rom_extract", "selgros", 34, 12, 12, 2033);
	addMaterialFunction(repository, undoArray, redoArray, "abc", "def", 4, 4, 3, 2020);

	destroyOperationDynamicArray(undoArray);
	destroyOperationDynamicArray(redoArray);
}


