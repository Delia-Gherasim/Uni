/*a. Write a predicate to determine if a list has even numbers of elements without counting the elements from
the list.
b. Write a predicate to delete first occurrence of the minimum number
from a list.*/

%candidate(L-list, E-element)
%i,o
candidate([E|_], E).
candidate([_|T],E):-
    candidate(T, E).

%iterate(L-list, R-result)
%i,o
iterate([_], 0).
iterate([_|T], Result):-
    iterate(T, R),
    R =:= 0,
    Result is 1.
iterate([_|T], Result):-
    iterate(T, R),
    R =:=1,
    Result is 0.

/*
%nrOfOcc(L-list, E-elem, R-result)
%i,i,o
nrOfOcc([], _, 0).
nrOfOcc([E], E, 1).
nrOfOcc([H|T], E, R):-
    H=:=E,
    nrOfOcc(T, E, R2),
    R is R2+1.
nrOfOcc([H|T], E, R):-
    H=\=E,
    nrOfOcc(T, E, R).

% minimum(E-elementToCheck, N-itsNumberOfOcc, M-minNrOfOcc, X-element,
% R-resultElement) i,i,i,i,o
minimum(_, 0, M, X, X):-
    M>0.
minimum(E,N,M,_, E):-
    N<M.

%delete(L-list, E-element, R-res)
%i,i,o
deleteE([],_, []).
deleteE([E|T], E, T).
deleteE([H|T], E, [H|R]):-
    H=\=E,
    delete(T, E, R).

%minNrOcc(L-list, E-element, M-minCount)
minNrOcc([], 0, _).
minNrOcc([H|T], Min, H):-
    nrOfOcc([H|T], H, R),
    minNrOcc(T, RestMin, _),
    Min is min(R, RestMin),
    Min=:=R.
minNrOcc([H|T], Min, X):-
    nrOfOcc([H|T], H, R),
    minNrOcc(T, RestMin, X),
    Min is min(R, RestMin),
    Min=:=RestMin.

createVector([],[]).
createVector([E],[E, 1]).
createVector([H|T], [H, N|R]):-
    nrOfOcc([H|T], H, N),
    createVector(T, R).


findMinim([[H1,N1]|T], H1, N1):-
    findMinim(T, _, N2),
    N1<N2.
findMinim([], _, 99999).
findMinim([E, 1], E, 1).
findMinim([[_, N1]|T], H2, N2):-
    findMinim(T, H2, N2),
    N2<N1.

findMinim([],_,_).
findMinim([[H, N]|T], H, N):-
    findMinim(T, _, N2),
    N<N2.

da([], []).
da(L, R):-
    createVector(L, V),
    findMinim(V, E, _),
    deleteE(L, E, R).



findMinimum([H|T], H):-
    findMinimum(T, Res),
    H<Res.
findMinimum([H|T], Res):-
    findMinimum(T, Res),
    H>=Res.
findMinimum([], _).
findMinimum([E], E).
%delete(L-list, E-element, R-res)
%i,i,o
deleteE([],_, []).
deleteE([E|T], E, T).
deleteE([H|T], E, [H|R]):-
    H=\=E,
    delete(T, E, R).
da([], []).
da(L, R):-
    findMinimum(L, E),
    deleteE(L, E, R).

*/


% Base case: an empty list has no minimum element to delete
delete_min([], []).

% Case 1: If X is the minimum element and it is the first occurrence,
% then skip it and proceed with the rest of the list
delete_min([X|Xs], Xs) :-
    min(Xs, Min),
    X =:= Min.

% Case 2: If X is not the minimum element, keep it and recurse on the rest of the list
delete_min([X|Xs], [X|Ys]) :-
    min(Xs, Min),
    X =\= Min,
    delete_min(Xs, Ys).

% Helper predicate to find the minimum element in a list
min([X], X).
min([X,Y|Rest], Min) :-
    X =< Y,
    min([X|Rest], Min).
min([X,Y|Rest], Min) :-
    X > Y,
    min([Y|Rest], Min).
