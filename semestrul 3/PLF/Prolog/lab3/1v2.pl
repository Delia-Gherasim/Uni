%Write a predicate to generate the list of all subsets
%with all elements of a given list.
%Eg: [2, 3, 4] N=2 => [[2,3],[2,4],[3,4]]

% comb(L-list, N-nrOfElements, R-result)
% flow model:i, i, o
comb([H | _], 1, [H]).
comb([_ | T], N, R) :-
    comb(T, N, R).
comb([H | T], N, [H | R]) :-
    N > 1,
    N1 is N-1,
    comb(T, N1, R).

%generate_subsets(L-list, N-nrOfElements, R-Result)
%flow model:i,i,o
generate_subsets(L, N, Result) :-
    findall(R, comb(L,N,R), Result).

