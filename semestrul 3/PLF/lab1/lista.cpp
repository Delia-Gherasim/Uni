#include "lista.h"
#include <iostream>

using namespace std;


PNod creare_rec(){
  TElem x;
  cout<<"x=";
  cin>>x;
  if (x==0)
    return NULL;
  else{
    PNod p=new Nod();
    p->e=x;
    p->urm=creare_rec();
    return p;
  }
}

Lista creare(){
   Lista l;
   l._prim=creare_rec();

   return l;
}

void tipar_rec(PNod p){
   if (p!=NULL){
     cout<<p->e<<" ";
     tipar_rec(p->urm);
   }
}

void tipar(Lista l){
   tipar_rec(l._prim);
}

void distrug_rec(PNod p){
   if (p!=NULL){
     distrug_rec(p->urm);
     delete p;
   }
}

void distrug(Lista l) {
	//se elibereaza memoria alocata nodurilor listei
    distrug_rec(l._prim);
}


bool contains(PNod p, TElem x) {
    if (p == nullptr) {
        return false;
    }
    if (p->e == x) {
        return true;
    }
    return contains(p->urm, x);
}

void add(PNod& p, TElem x) {
    if (!contains(p, x)) {
        PNod newNode = new Nod();
        newNode->e = x;
        newNode->urm = nullptr; 
        if (p == nullptr) {
            p = newNode; 
        }
        else {
            PNod current = p;
            while (current->urm != nullptr) {
                current = current->urm; 
            }
            current->urm = newNode; 
        }
    }
}


Lista transformToSet(Lista l) {
    Lista resultSet;
    resultSet._prim = nullptr;

    PNod p = l._prim;
    while (p != nullptr) {
        add(resultSet._prim, p->e);
        p = p->urm;
    }

    return resultSet;
}

Lista unionOfSets(Lista set1, Lista set2) {
    Lista resultSet;
    resultSet._prim = nullptr;

    PNod p1 = set1._prim;
    while (p1 != nullptr) {
        add(resultSet._prim, p1->e);
        p1 = p1->urm;
    }

    PNod p2 = set2._prim;
    while (p2 != nullptr) {
        add(resultSet._prim, p2->e);
        p2 = p2->urm;
    }

    return resultSet;
}
