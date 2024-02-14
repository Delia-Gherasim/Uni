#include <assert.h>
#include "Matrix.h"
#include <iostream>
#include "ShortTest.h"
using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);
}

void testSetElemsOnCol()
{
    Matrix matrix(3, 4);
    matrix.modify(0, 0, 1);
    matrix.modify(0, 1, 2);
    matrix.modify(1, 1, 3);
    matrix.modify(2, 2, 4);

    matrix.setElemsOnCol(1, 5);

    assert(matrix.element(0, 0) == 1);
    assert(matrix.element(0, 1) == 5);
    assert(matrix.element(1, 1) == 5);
    assert(matrix.element(2, 2) == 4);
    cout << "Passed set elements on column";
}