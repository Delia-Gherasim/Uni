f([], 0).
f([H|T], S):-
    f(T, S1),
    max(H, S1, S).
   % S is S1,
   %S1<H,
    %!,
    %S is H.
%f([_|T], S):-
   % f(T, S1),
   %S is S1.

max(A,B,M) :- A>B, M is A.
max(_,B,B).

g([],[]).
g([H|T],S):-H mod 2 =:=0,
    g(T,S).

g([H|T],[H|S]):-g(T,S).

h(1,1):-!.
h(K,X):- K1 is K-1,
    h(K1, Y),
    Y>1,
    !,
    K2 is K1-1,
    X is K2.

h(K, X):-K1 is K-1,
    h(K1, Y),
    Y>0.5,
    !,
    X is Y.
h(K, X):-K1 is K-1,
    h(K1, Y),
    X is Y-1.
p(1).
p(2).
q(1).
q(2).
r(1).
r(2).
s:-p(X),
   !,
   q(Y),
   r(Z),
   write(X),
   write(Y),
   write(Z).

candidate([E|_], E).
candidate([_|T], E):- candidate(T,E).

permaux(N, _, Col, N, Col, _):-!.
permaux(N, V, L, Lg, [H|T], Li):-
    candidate(Li, I),
    %ACI AR VENI COND
    \+ member(I, [H|T]),
    Lg1 is Lg +1,
    permaux(N, V, L, Lg1, [I, H|T], Li).
permutations(N, V, L, Li):-
    candidate(Li, I),
    permaux(N, V, L, 1, [I], Li).

sumOfElements([], 0).
sumOfElements([H|T], S):-
    sumOfElements(T, S1),
    S is S1 + H.

% Base case: an empty list has only one subset, the empty set.
subsets([], []).
% Recursive case: generate subsets by including or excluding the first element.
subsets([H|T], [H|Sub]):-
    subsets(T, Sub).
subsets([_|T], Sub):-
    subsets(T, Sub).
condition(L, R1):-
    subsets(L, R1),
    sumOfElements(R1, S),
    S mod 3 =:=0.

produs([], 1).
produs([X], X).
produs([H|T],Res):-
    produs(T, R1),
    Res is R1 * H.
aranAux(K, _, _, K, Col, Col):-!.
aranAux(K, P, Li, Lg, [H|T], R):-
    candidate(Li, I),
    \+member(I, [H|T]),
    produs([I,H|T], Prod),
    Prod=:=P,
    Lg1 is Lg+1,
    aranAux(K, P, Li, Lg1, [I,H|T], R).
aranjamente(K, P, Li, R):-
    candidate(Li, I),
    aranAux(K, P, Li, 1, [I], R).

%  plf 2019 ex1
%  generate the list of subsets of n elements from a list
subst([],[]).
subst([_|T],Res):-subst(T,Res).
subst([H|T],[H|Res]):-
    subst(T, Res).
gen_subst(L, N, R):-
    findall(Res,(subst(L,Res), length(Res, N)), R).
% given a list, computes the list in reversed order
reverse1([],[]).
reverse1([H|T], [Res| HRev]):-
    is_list(H),
    !,
    reverse1(H, HRev),
    reverse1(T, Res).
reverse1([H|T], [Res|H]):-
    reverse1(T, Res).

%  2019 ex3
% subsets of even lenght
even_len(L, true):-
    length(L, N),
    N mod 2 =:=0,!.
even_len(_, false).
da(L, N, R):-
    findall(Res, (subst(L, Res), even_len(Res, N)),R).

%comb
candidateN(N,N).	%candidate pt elem de la 1 la n
candidateN(N, I):-
	N>1,
	N1 is N-1,
	candidateN(N1, I).
comb([H|_], 1, [H]).
comb([_|T], K, C):- comb(T, K, C).
comb([H|T], K, [H|C]):-K>1,
    K1 is K-1,
    comb(T, K1, C).
is_even(L, true):-sum(L, N),
    N mod 2=:=0.
is_even(_, false).
sum([], 0).
sum([H|T], S):-
    sum(T, S1),
    S is S1+H.
genComb(L, K, R):-
    findall(Res, (comb(L, K, Res), is_even(Res, true)), R).
