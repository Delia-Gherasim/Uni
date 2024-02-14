#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
    this->rowIndex = new int[nrLines + 1]();
    this->nrLnes = nrLines;
    this->nrCols = nrCols;
    this->capacity = 8;
    this->values = new TElem[this->capacity];
    this->colIndex = new int[this->capacity];
}

int Matrix::nrLines() const {
    //complexity Theta(1)
    return this->nrLnes;
}

int Matrix::nrColumns() const {
    //complexity Theta(1)
    return this->nrCols;
}


TElem Matrix::element(int i, int j) const {
    // best case complexity Theta(1), when the element is the first element in the row
    // worst case complexity Theta(nrCols),  when the element is the last element in the row
    // average complexity Theta(nrCols)

    if (i < 0 || i >= this->nrLnes || j < 0 || j >= this->nrCols) {
        throw exception();
    }

    // Find the starting and ending index of the row.
    int start = this->rowIndex[i];
    int end = this->rowIndex[i + 1];

    // Find the index of the column.
    for (int k = start; k < end; k++) {
        if (this->colIndex[k] == j) {
            return this->values[k];
        }
    }
    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    // best case complexity Theta(1), when the element is the first element in the row
    // worst case complexity Theta(nrCols),  when the element is the last element in the row
    // average complexity Theta(nrCols)

    if (i < 0 || i >= this->nrLnes || j < 0 || j >= this->nrCols) {
        throw exception();
    }

    int pos = this->rowIndex[i]; 
    int end = this->rowIndex[i + 1]; 
    int currCol = -1;

    // Search for the element.
    for (; pos < end; pos++) {
        currCol = this->colIndex[pos];
        if (currCol >= j) {
            break;
        }
    }

    if (currCol != j) {
        // If it's not in the matrix and the element we want add is not NULL_TELEM, insert it into the matrix.
        if (e != NULL_TELEM) {
            this->insert(i, j, pos, e);
            return NULL_TELEM;
        }
    }
    else if (e == NULL_TELEM) {
        // If we want to add a NULL_TELEM at a position we have an element at we need to remove that element.
        TElem oldValue = this->values[pos];
        this->remove(pos, i);
        return oldValue;
    }
    else {
        // replace the old element with the new element.
        TElem oldValue = this->values[pos];
        this->values[pos] = e;
        return oldValue;
    }


}

Matrix::~Matrix() {
    //complexity theta(1)
    delete[] this->values;
    delete[] this->colIndex;
    delete[] this->rowIndex;
}

void Matrix::remove(int index, int i) {
    //complexity Theta(nonzero)
    
    // Remove from values array and colIndex array.
    for (int k = index; k < this->nonZero - 1; k++) {
        this->values[k] = this->values[k + 1];
        this->colIndex[k] = this->colIndex[k + 1];
    }
    this->nonZero--;

    // Update the rowIndex array.
    for (int k = i + 1; k <= this->nrLnes; k++) {
        this->rowIndex[k] -= 1;
    }
}

void Matrix::insert(int i, int j, int index, TElem e) {
    //complexity theta(nonzero)
    // Test to see if the array is full; resize if it is.
    if (this->nonZero == this->capacity) {
        this->capacity *= 2;
        TElem* newValues = new TElem[this->capacity];
        int* newColIndex = new int[this->capacity];
        for (int k = 0; k < this->nonZero; k++) {
            newValues[k] = this->values[k];
            newColIndex[k] = this->colIndex[k];
        }
        delete[] this->values;
        delete[] this->colIndex;
        this->values = newValues;
        this->colIndex = newColIndex;
    }

    // Insert the element in the values array and in the colIndex array.
    for (int k = this->nonZero; k > index; k--) {
        this->values[k] = this->values[k - 1];
        this->colIndex[k] = this->colIndex[k - 1];
    }
    this->values[index] = e;
    this->colIndex[index] = j;

    // Update the rowIndex array.
    for (int k = i + 1; k <= this->nrLnes; k++) {
        this->rowIndex[k] += 1;
    }

    this->nonZero++;
}

void Matrix::setElemsOnCol(int col, TElem elem)
{
    //complexity is theta(nrLines*(nrLines + nonZero))

    if (col < 0 || col >= this->nrCols)
        throw exception();
    else
        for (int i = 0; i < this->nrLnes; i++)
            Matrix::modify(i, col, elem);

}

