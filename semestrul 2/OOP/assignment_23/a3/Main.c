#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "Repository.h"
#include "DynamicArray.h"
#include "Controller.h"
#include "UI.h"

int main(int argc, char** argv)
{
	BakeryDynamicArray* repository = createRepository();
	OperationDynamicArray* undoArray = createOperationDynamicArray(2);
	OperationDynamicArray* redoArray = createOperationDynamicArray(2);

	//initController(repository);

	runConsole(repository, undoArray, redoArray);
	
	destroyBakeryDynamicArray(repository);
	destroyOperationDynamicArray(undoArray);
	destroyOperationDynamicArray(redoArray);

	return 0;
}