%insertAtPos(l-list, E-element, P-position, R-result list)
%  flow model(i, i, i, o)
insertAtPos([], -, P, []):-P>1.
insertAtPos(L, E, 1, [E|L]).
insertAtPos([H|T], E, P, [H|TR]):-
    P>1,
    P1 is P-1,
    insertAtPos(T, E, P1, TR).

