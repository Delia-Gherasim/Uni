%seminar 3
% 1.given a list of nr & sublists of nr, substitute each sublist in which
% the sum of the elements is odd with the first eleent of the sublist

%sum(L, S)
%(i,o) ,(i,i)
sum([], 0).
sum([H|T], NewS):-
    sum(T, S),
    NewS is S+H.
%solve(L(1...n))={[], if n=0
%                 L1 U solve(L(2..n)), if L1 is list and sum(L1) is odd
%                 L1 U solve(L[2...n])
%solve(L, R)
%(i,o), (i,i)
solve([],[]).
solve([H|T],[NewH|NewT]):-
    islist(H),
    sum(H,S),
    mod(S,2)=:=1,
    !,
    H=[newH|_],
    solve(T, NewT).
