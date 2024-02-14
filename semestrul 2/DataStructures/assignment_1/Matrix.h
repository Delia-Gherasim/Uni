#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix {

private:
		TElem* values;
		int* rowIndex;
		int* colIndex;
		int nrLnes;
		int nrCols;
		int capacity;
		int nrElements;
		int* rows;
		int* columns;
		int nonZero;

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	~Matrix();

	void remove(int index, int i);

	void insert(int i, int j, int index, TElem e);

	void setElemsOnCol(int col, TElem elem);

};


