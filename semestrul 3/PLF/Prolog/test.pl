% define a predicate that merges 2 sorted list of integral nr and
% removes duplicate values
%ex 1,2,3,5,7 and 2,4,6,8 => 1,2,3,4,5,6,7,8


%                           mathematical model:
% merge((l1,l2,..ln),(r1,r2,...rm))=
    %l1 U merge((l2,...ln),(r1,r2,...rm)),    if l1<r1
    %r1 U merge((l1,l2,...ln),(r2,...rm)),    if r1<l1
    %l1 U merge((l2,...ln),(r2,...rm)),       if l1=r1

%appears(e, l1,...ln)= true, if e=l1
%                      appears(e, l2,..ln), if e!=l1
%                      false, otherwise

%removeDouble(l1,l2,...ln)=
%        removeDouble(l2,...ln), if l1 included in l2,...ln
%        l1 U removeDouble(l2,...ln) if l1 not included in l2,...ln


%merge(L1-list, L2-list, R-Result list) flow model:i,i,o
merge([],[],[]).
merge([], L, L).
merge(L, [], L).
merge([H1|T1], [H2|T2], [H1|R]):-
    H1<H2,
    merge(T1, [H2|T2], R).
merge([H1|T1], [H2|T2], [H2|R]):-
    H1>H2,
    merge([H1|T1], T2, R).
merge([H1|T1], [H2|T2], [H1|R]):-
    H1=:=H2,
    merge(T1, T2, R).

%appears(E-element, L-list)
%flow model:i,i
appears(E,[E|_]):-!.
appears(E, [_|T]):-
    appears(E, T).

%removeDouble(L-list, R-result list)
%flow model:i,o
removeDouble([],[]).
removeDouble([E], [E]).
removeDouble([H|T], R):-
    appears(H, T),
    removeDouble(T, R).
removeDouble([H|T], [H|R]):-
    \+appears(H,T),
    removeDouble(T, R).

%main(L1-sorted list, L2-sorted list, R-result list)
%flow model(i,i,o)
main(L1,L2,R):-
    merge(L1, L2, R1),
    removeDouble(R1, R).
