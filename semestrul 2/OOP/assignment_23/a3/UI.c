#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UI.h"
#include "Controller.h"

void printMenu()
{
		printf("\n");

		printf(" 1. Print all materials\n");
		printf(" 2. Add a material \n");
		printf(" 3. Delete a material\n");
		printf(" 4. Update a material\n");
		printf(" 5. See all available materials past their expiration date \n");
		printf(" 6. Display all materials from a given supplier, which are in short supply\n");
		printf(" 7. Undo; \n");
		printf(" 8. Redo; \n");
		printf(" 9. Exit.\n");
}

void waitForNextInput()
{
	printf("Press any key to return.");
	getchar();
}

void printMaterialsFromDynamicArray(BakeryDynamicArray* materials)
{
	for (int i = 0; i < materials->size; i++)
		printf("%s %s %d %d %d %d \n ", getMaterialName(&materials->elements[i]), getMaterialSupplier(&materials->elements[i]), getMaterialQuantity(materials->elements[i]), getMaterialExpirationDay(materials->elements[i]), getMaterialExpirationMonth(materials->elements[i]), getMaterialExpirationYear(materials->elements[i])  );
		
}

void printAllMaterials(BakeryDynamicArray* repository)
{
	BakeryDynamicArray* allMaterials = getAllMaterialsController(repository);

	printf("All materials are listed below:\n");

	printMaterialsFromDynamicArray(allMaterials);

	destroyBakeryDynamicArray(allMaterials);
}


int read_the_quantity_input_validation()
{
	int quantity;
	char user_input_buffer[10]; // allocate a buffer to hold user input
	while (1)
	{
		printf("Enter the quantity: ");
		fgets(user_input_buffer, sizeof(user_input_buffer), stdin); // read input from user
		// check if input is valid
		if (sscanf(user_input_buffer, "%d", &quantity) == 1 && quantity >= 0)
		{
			break;
		}
		else
		{
			printf("Invalid input. Please enter a positive integer.\n");
		}
	}
	return quantity;
}

int read_the_date_day_input_validation()
{
	int expiration_day;
	char user_input_buffer[10];
	while (1)
	{
		printf("Enter the day: ");
		fgets(user_input_buffer, sizeof(user_input_buffer), stdin);
		if (sscanf(user_input_buffer, "%d", &expiration_day) == 1 && expiration_day > 0 && expiration_day < 31)
		{
			break;
		}
		else
		{
			printf("Invalid input. Please enter a positive integer smaller than 31.\n");
		}
	}
	return expiration_day;
}

int read_the_date_month_input_validation()
{
	int expiration_month;
	char user_input_buffer[10];
	while (1)
	{
		printf("Enter the month: ");
		fgets(user_input_buffer, sizeof(user_input_buffer), stdin);
		if (sscanf(user_input_buffer, "%d", &expiration_month) == 1 && expiration_month > 0 && expiration_month < 13)
		{
			break;
		}
		else
		{
			printf("Invalid input. Please enter a positive integer smaller than 13.\n");
		}
	}
	return expiration_month;
}

int read_the_date_year_input_validation()
{
	int expiration_year;
	char user_input_buffer[10];
	while (1)
	{
		printf("Enter the year: ");
		fgets(user_input_buffer, sizeof(user_input_buffer), stdin);
		if (sscanf(user_input_buffer, "%d", &expiration_year) == 1 && expiration_year > 0)
		{
			break;
		}
		else
		{
			printf("Invalid input. Please enter a positive integer.\n");
		}
	}
	return expiration_year;
}

void addMaterial(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	printf(" \n Type the name, supplier and expiration date of the new material\n");
	int quantity, expiration_day, expiration_month, expiration_year;
	char name[30], supplier[30];
	printf(" The new name is? \n");
	scanf("%s", &name);
	printf("The new supplier is? \n");
	scanf("%s", &supplier);
	quantity = read_the_quantity_input_validation();
	printf("Please enter the expiration date");
	expiration_day = read_the_date_day_input_validation();
	expiration_month = read_the_date_month_input_validation();
	expiration_year = read_the_date_year_input_validation();

	addMaterialFunction(repository, undoArray, redoArray, name, supplier, quantity, expiration_day, expiration_month, expiration_year);
}

void deleteMaterial(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	printf(" \n Type the name, supplier and expiration date of the material you want to delete\n");
	int quantity, expiration_day, expiration_month, expiration_year;
	char name[30], supplier[30];
	printf("The name of the material you want to delete is? \n");
	scanf("%s", &name);
	printf("The supplier of the material you want to delete is? \n");
	scanf("%s", &supplier);
	quantity = read_the_quantity_input_validation();
	printf("Please enter the expiration date");
	expiration_day = read_the_date_day_input_validation();
	expiration_month = read_the_date_month_input_validation();
	expiration_year = read_the_date_year_input_validation();

	deleteMaterialFunction(repository, undoArray, redoArray, name, supplier, quantity, expiration_day, expiration_month, expiration_year);
}

void updateMaterial(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	printf("\n Type the name, supplier, quantity and expiration date of the material you want to update \n");
	int quantity, expiration_day, expiration_month, expiration_year;
	char name[30], supplier[30];
	int new_quantity, new_expiration_day, new_expiration_month, new_expiration_year;
	char new_supplier[30];

	printf("The name is? \n");
	scanf("%s", &name);
	printf("The supplier is? \n");
	scanf("%s", &supplier);
	printf("The new supplier is? \n");
	scanf("%s", &supplier);
	quantity = read_the_quantity_input_validation();
	printf("Please enter the expiration date");
	expiration_day = read_the_date_day_input_validation();
	expiration_month = read_the_date_month_input_validation();
	expiration_year = read_the_date_year_input_validation();

	printf("Please enter the new supplier, quantity and expiration date");
	printf("The new supplier is? \n");
	scanf("%s", &new_supplier);
	new_quantity = read_the_quantity_input_validation();
	printf("Please enter the new expiration date");
	new_expiration_day = read_the_date_day_input_validation();
	new_expiration_month = read_the_date_month_input_validation();
	new_expiration_year = read_the_date_year_input_validation();

	updateMaterialSupplierFunction(repository, undoArray, redoArray, new_supplier, name, supplier, quantity, expiration_day, expiration_month, expiration_year);
	updateMaterialQuantityFunction(repository, undoArray, redoArray, new_quantity, name, supplier, quantity, expiration_day, expiration_month, expiration_year);
	updateMaterialExpirationDateFunction(repository, undoArray, redoArray, new_expiration_day, new_expiration_month, new_expiration_year, name, supplier, quantity, expiration_day, expiration_month, expiration_year);

}

void printExpiredMaterials(BakeryDynamicArray* repository)
{

	char containedString[30] = "";
	printf("Please enter the contained string to search for: ");
	fgets(containedString, sizeof(containedString), stdin);
	fgets(containedString, sizeof(containedString), stdin);
	containedString[strlen(containedString) - 1] = '\0';

	int current_date_day, current_date_month, current_date_year;
	printf(" Please enter the date with which you wish to compare the materials \n");
	current_date_day = read_the_date_day_input_validation();
	current_date_month = read_the_date_month_input_validation();
	current_date_year = read_the_date_year_input_validation();

	BakeryDynamicArray* foundMaterials = MaterialsCointainingGivenString(repository, containedString, current_date_day, current_date_month, current_date_year);
	{
	

		printMaterialsFromDynamicArray(foundMaterials);

		destroyBakeryDynamicArray(foundMaterials);

	}
}

void getMaterialsInShortSupply(BakeryDynamicArray* repository)
{
	int quantity;
	char supplier[30];
	printf("The supplier is? \n");
	scanf("%s", &supplier);
	printf(" Provide a value to describe what short supply means to you \n");
	printf("( Material should be less than ...?) \n");
	quantity = read_the_quantity_input_validation();

	BakeryDynamicArray* foundMedicines =MaterialsInShortSupply(repository, quantity);

	printMaterialsFromDynamicArray(foundMedicines);

	destroyBakeryDynamicArray(foundMedicines);
}

int inputCommand()
{
	int command;
	printf("\nPlease type your option number: \n>");
	scanf("%d", &command);

	return command;
}

void undo(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	int result = undoFunction(repository, undoArray, redoArray);

	if (result == 1)
	{
		printf("Can not perform any undoes \n");
		return;
	}

	printf("Operation undone\n");
}

void redo(BakeryDynamicArray* repository, OperationDynamicArray* undoArray,	OperationDynamicArray* redoArray)
{
	int result = redoFunction(repository, undoArray, redoArray);

	if (result == 1)
	{
		printf("Can not perform any redoes \n");
		return;
	}

	printf("Operation redone \n");
}

int interpretCommand(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, int userSelectedCommand)
{
	switch (userSelectedCommand)
	{
	case 1:
		printAllMaterials(repository);
		waitForNextInput();
		break;

	case 2:
		addMaterial(repository, undoArray, redoArray);
		break;

	case 3:
		deleteMaterial(repository, undoArray, redoArray);
		break;

	case 4:
		updateMaterial(repository, undoArray, redoArray);
		break;

	case 5:
		printExpiredMaterials(repository);
		waitForNextInput();
		break;

	case 6:
		getMaterialsInShortSupply(repository);
		waitForNextInput();
		break;

	case 7:
		undo(repository, undoArray, redoArray);
		waitForNextInput();
		break;

	case 8:
		redo(repository, undoArray, redoArray);
		waitForNextInput();
		break;

	case 9:
		return 1;

	default:
		break;
	}

	return 0;
}

void runConsole(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray)
{
	while (1)
	{
		printMenu();
		int userSelectedCommand = inputCommand();
		int result = interpretCommand(repository, undoArray, redoArray, userSelectedCommand);
		if (result)
			break;
	}
}

