#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

//ADT SortedBag–using a SLLA with(element, frequency) pairs.Pairs are ordered based on a relation between the elements.
int main() {
	testAll();
	testAllExtended();
	testElementsWithThisFrequency();
	cout << "Test over" << endl;
	
	system("pause");

}
