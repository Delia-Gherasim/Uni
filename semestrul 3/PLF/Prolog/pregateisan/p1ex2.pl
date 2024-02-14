%2.a. Write a predicate to remove all occurrences of a certain atom from a list.
%b. Define a predicate to produce a list of pairs (atom n) from an initial list of atoms. In this initial list atom has n occurrences.
%Eg.: numberatom([1, 2, 1, 2, 1, 3, 1], X) => X = [[1, 4], [2, 2], [3, 1]].

%removeOccurance(L-list, E-element, R-result)
%i,i,o
removeOcc([],_,[]).
removeOcc(E, E, []).
removeOcc([H|T], E, R):-
      H=:=E,
      removeOcc(T, E, R).
removeOcc([H|T], E, [H|R1]):-
     H\=E,
     removeOcc(T, E, R1).

%countEl(L-list, E-element, R-result)
%i,i,o
countEl([],_, 0).
countEl(E, E, 1).
countEl([H|T], E, R):-
     H=:=E,
     countEl(T, E, R2),
     R is R2+1.
countEl([H|T], E, R):-
     H\=E,
     countEl(T, E, R).
