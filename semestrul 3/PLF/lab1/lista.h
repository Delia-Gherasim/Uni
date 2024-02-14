#ifndef LISTA_H
#define LISTA_H


//tip de data generic (pentru moment este intreg)
typedef int TElem;

//referire a structurii Nod;
struct Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod *PNod;

typedef struct Nod{
    TElem e;
	PNod urm;
};

typedef struct{
//prim este adresa primului Nod din lista
	PNod _prim;
} Lista;

//operatii pe lista - INTERFATA

//crearea unei liste din valori citite pana la 0
    Lista creare();
//tiparirea elementelor unei liste
    void tipar(Lista l);
// destructorul listei
	void distruge(Lista l);

// Function to transform a list into a set
	Lista transformToSet(Lista l);

// Function to check if an element is already in the set (list)
	bool contains(PNod p, TElem x);

// Function to add an element to the set (list)
	void add(PNod& p, TElem x);

// Function to determine the union of two sets (lists)
	Lista unionOfSets(Lista set1, Lista set2);

#endif
