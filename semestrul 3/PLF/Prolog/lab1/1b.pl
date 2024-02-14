/*b. Write a predicate to add a value v after 1-st, 2-nd, 4-th, 8-th, … element in a list.*/

%insert(L-list, P-position, E-element, R-result)
%flow model(i,i,i, o)
insert(L,1, E, [E|L]).
insert([H|T], P, E, [H|TR]):-
    P>1,
    P1 is P-1,
    insert(T, P1, E, TR).

%insertAtPositions(L-list, E-element,P-position,R-result)
%flow model(i,i,i,o)
insertAtPositions(L,_,P,L):-P>4.
insertAtPositions(L,E,P,R):-
    P=<4,
    insert(L, P, E, TempList),
    P1 is P*2,
    insertAtPositions(TempList, E, P1, R).

b(L,E,R):-insertAtPositions(L,E,1,R).
