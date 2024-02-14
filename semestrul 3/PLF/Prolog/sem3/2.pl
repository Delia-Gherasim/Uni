%given a list of numbers and sublist of numbers, remove the odd num bers
% from the sublists that have a mountain aspect
%
% mountain aspect -> urca si coboara ex [6 7 6], [1 2 3 4 3]
%                                       nu ii: [1 2 3], [3 2 1]
%                -> fa.ma doamne piatra tare sa rezist la suparare
%
%remove_odd(l1,...ln)={[], if n=0
%                       l1 U remove_odd(l2,...ln), if l1 is even,
%                       remove_odd(l2,...ln) otherwise
remove_odd([],[]).
remove_odd([H|T], R):-
    /+ odd, !,
    remove_odd(T, R1),
    R=[H|R1].
remove_odd([H|T], R):-
    remove_odd(T, R).

%mountain(l1...ln, b)={true, n=1 and b=1,
%                   mountain(l2....ln, 1), if l1>l2 and b=0,
%                   mountain(l2...ln, 0), if b=0 and l1<l2,
%                   false, otherwise
mountain([],1).
mountain([H1, H2|T], _):-
    H1>H2,
    mountain([H2|T], 1).
mountain([H1, H2|T], 0):-
    H1<H2,
    mountain([H2|T], 0).
%solve(l1, ...ln)={
