#include "lista.h"
#include <iostream>

int main()
{
   Lista l1, l2;
   l1=creare();
   tipar(l1);
   l2 = creare();
   tipar(l2);
   std::cout << std::endl;

   Lista set1, set2;
   set1 = transformToSet(l1);
   set2 = transformToSet(l2);

   std::cout << "First list as a set:   ";
   tipar(set1);
   std::cout << std::endl;
   std::cout << "Second list as a set:   ";
   tipar(set2);
   std::cout << std::endl;

   Lista uniune;
   uniune = unionOfSets(set1, set2);
   std::cout << "Union of sets:   ";
   tipar(uniune);


}
