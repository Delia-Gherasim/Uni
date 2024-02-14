%Sort a list, removing the double values.

%concat(L-list,E-element,R-result)
%flow model:i,i,o
concatList([],X,X).
concatList([H|T],X,[H|R]) :-
    concatList(T,X,R).

%insertEl(L-list, E-element, R-result)
%flow model:i,i,o
insertEl([],E,[E]).
insertEl([H|T],E,R) :-
    H =< E,
    concatList([H],R1,R),
    insertEl(T,E,R1).
insertEl([H|T],E,R) :-
    concatList([E],[H|T],R).

%sort(L-list,R-result)
%flow model:i,o
sortList([],[]).
sortList([H|T],R) :-
    sortList(T,R1),
    insertEl(R1,H,R).

%member(E-element, l-list)
%flow model(i,o)
member(E, [E|_]):-!.
member(E,[_|L]):- member(E,L).

%removeDouble(L-list, R-result)
%flow model(i,o)
removeDouble([],[]).
removeDouble([X], [X]).
removeDouble([H|T], R):-
    member(H, T),
    removeDouble(T, R).
removeDouble([H|T], [H|R]):-
    \+ member(H,T),
    removeDouble(T, R).

%a(L-list, R-result)
%flow model(i, o)
a([], []).
a(L, R):-
    removeDouble(L, Res),
    sortList(Res, R).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% For a heterogeneous list, formed from integer numbers and list of numbers,
%write a predicate to sort every sublist with removing the doubles

%b(L-list, R-result)
%flow model(i,o)
b([], []).
b([H|T], [R|Result]):-
    is_list(H),
    !,
    a(H, R),
    b(T, Result).
b([H|T], [H|Result]):-
    \+ is_list(H),
    b(T, Result).
