#define _CRT_SECURE_NO_WARNINGS
#include "Domain.h"
#include "Repository.h"
#include "Controller.h"
#include "DynamicArray.h"
#include <assert.h>

void testDomain()
{
    Material material = { "flour", "mopan", 50, 9, 10, 2023 };
    assert(strcmp(getMaterialName(&material), "flour")==0);
    assert(strcmp(getMaterialSupplier(&material), "mopan") == 0);
    assert(getMaterialQuantity(material) == 50);
    assert(getMaterialExpirationDay(material) == 9);
    assert(getMaterialExpirationMonth(material) == 10);
    assert(getMaterialExpirationYear(material) == 2023);
}

void testRepository() {
    BakeryDynamicArray* repository = createRepository();
    Material material = { "flour", "mopan", 50, 9, 10, 2023 };
    addElementToBakeryDynamicArray(repository, material);
    assert(getBakeryDynamicArraySize(repository) == 1);
    assert(strcmp(getMaterialName(&repository->elements[0]),"flour") == 0);
    assert(strcmp(getMaterialSupplier(&repository->elements[0]), "mopan") == 0);
    assert(getMaterialQuantity(repository->elements[0]) == 50);
    assert(getMaterialExpirationDay(repository->elements[0]) == 9);
    assert(getMaterialExpirationMonth(repository->elements[0]) == 10);
    assert(getMaterialExpirationYear(repository->elements[0]) == 2023);

}

void testController()
{
    BakeryDynamicArray* repository = createRepository();
    OperationDynamicArray* undoArray = createOperationDynamicArray(2);
    OperationDynamicArray* redoArray = createOperationDynamicArray(2);
   
    addMaterialFunction(repository, undoArray, redoArray, "flour", "mopan", 50, 9, 10, 2023);
    assert(getBakeryDynamicArraySize(repository) == 1);
    
    addMaterialFunction(repository, undoArray, redoArray, "cacao ", "mopan", 2, 3, 3, 2023);
    assert(getBakeryDynamicArraySize(repository) == 2);
    
    updateMaterialSupplierFunction(repository, undoArray, redoArray, "lidl","flour", "mopan", 50, 9, 10, 2023);
    assert(strcmp(getMaterialSupplier(&repository->elements[0]), "lidl")==0);
    
    updateMaterialQuantityFunction(repository, undoArray, redoArray, 20, "flour", "mopan", 50, 9, 10, 2023);
    assert(getMaterialQuantity(repository->elements[0]) == 20);
   
    updateMaterialExpirationDateFunction(repository, undoArray, redoArray, 30,2, 2024, "flour", "mopan", 50, 9, 10, 2023);
    assert(getMaterialExpirationDay(repository->elements[0]) == 30);

}

void testAll()
{
    testDomain();
    testRepository();
    testController();
}

/*
int main()
{
    testAll();
    return 0;
}*/