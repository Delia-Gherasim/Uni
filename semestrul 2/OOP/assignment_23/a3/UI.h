#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "DynamicArray.h"

void printMenu();

void printAllMaterials(BakeryDynamicArray* repository);

int read_the_quantity_input_validation();

int read_the_date_day_input_validation();

int read_the_date_month_input_validation();

int read_the_date_year_input_validation();

void addMaterial(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

void updateMaterialQuantity(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

void deleteMaterial(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

void updateMaterial(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

void printExpiredMaterials(BakeryDynamicArray* repository);

int inputCommand();

void undo(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

void redo(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);

int interpretCommand(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray, int userSelectedCommand);

void runConsole(BakeryDynamicArray* repository, OperationDynamicArray* undoArray, OperationDynamicArray* redoArray);