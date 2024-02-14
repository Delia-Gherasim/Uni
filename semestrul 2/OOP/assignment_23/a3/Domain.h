#pragma once

typedef struct
{
	char name[30];
	char supplier[30];
	int quantity;
	int expirationDay;
	int expirationMonth;
	int expirationYear;

} Material;

typedef Material TElem;

//Getters
char* getMaterialName(TElem* material);
char* getMaterialSupplier(TElem* material);
int getMaterialQuantity(TElem material);
int getMaterialExpirationDay(TElem material);
int getMaterialExpirationMonth(TElem material);
int getMaterialExpirationYear(TElem material);

//Setters
void setMaterialName(TElem* material, char* newName);
void setMaterialSupplier(TElem* material, char* newSupplier);
void setMaterialQuantity(TElem material, int newQuantity);
void setMaterialExpirationDay(TElem material, int NewExpirationDay);
void setMaterialExpirationMonth(TElem material, int newExpirationMonth);
void setMaterialExpirationYear(TElem material, int newExpirationYear);


typedef struct
{
	// add OR delete OR update
	char operation[30]; 
	Material material;
} Operation; 

// Undo getters
char* getUndoOperation(Operation* undoOperation);
Material getUndoOperationMaterial(Operation undoOperation);

//Undo Setters
void setUndoOperation(Operation* undoOperation, char* newUndoOperation);
void setUndoOperationMaterial(Operation undoOperation, Material newUndoOperationMaterial);

//Redo Getters
char* getRedoOperation(Operation* redoOperation);
Material getRedoOperationMaterial(Operation redoOperation);

//Redo Setters
void setRedoOperation(Operation* redoOperation, char* newRedoOperation);
void setRedoOperationMaterial(Operation redoOperation, Material newRedoOperationMaterial);