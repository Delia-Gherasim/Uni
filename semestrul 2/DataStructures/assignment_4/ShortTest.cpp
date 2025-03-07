#include <assert.h>
#include <iostream>
#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <vector>
#include "ShortTest.h"

using namespace std;

bool relation1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);
	assert(smm.size() == 0);
	assert(smm.isEmpty());
    smm.add(1,2);
    smm.add(1,3);
    assert(smm.size() == 2);
    assert(!smm.isEmpty());
    vector<TValue> v= smm.search(1);
    assert(v.size()==2);
    v= smm.search(3);
    assert(v.size()==0);
    SMMIterator it = smm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }
    assert(smm.remove(1, 2) == true);
    assert(smm.remove(1, 3) == true);
    assert(smm.remove(2, 1) == false);
    assert(smm.isEmpty());
}

void testGetValueRange()
{
    SortedMultiMap map= SortedMultiMap(relation1);

    // Test an empty map
    assert(map.getValueRange() == -1);

    // Test a map with multiple key-value pairs
    map.add(2, 20);
    map.add(2, 30);
    map.add(3, 5);
    map.add(3, 15);
    map.add(3, 25);
    map.add(4, 40);
    assert(map.getValueRange() == 35);


    cout << "getValueRange test passed" << endl;
}
