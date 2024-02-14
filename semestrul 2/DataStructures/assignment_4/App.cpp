#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

//36.ADT SortedMultiMap–using  a  hashtable  with  open  addressing  and  quadratic  probing  in which (key, value) pairs are stored. 
//If a key has multiple values, it appears in multiple pairs. 

int main(){
	testGetValueRange();
    testAll();
	testAllExtended();

    std::cout<<"Finished SMM Tests!"<<std::endl;
	system("pause");
}
