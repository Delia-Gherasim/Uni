%Write a predicate to generate the list of all subsets
%with all elements of a given list.
%Eg: [2, 3, 4] N=2 => [[2,3],[2,4],[3,4]]

%subsets(L-list, R-result)
%flow model:i,o
subsets1([], []).
subsets1([H | T], [H |R]) :-
    subsets1(T, R).
subsets1([_ | T], R) :-
    subsets1(T, R).

%subsets_lenght(L-list, N-nrOfElements, R-result)
%flow model:i,i,o
subsets_length([], _, []).
subsets_length([H | T], N, [H | R]) :-
    length(H, N),
    subsets_length(T, N, R).
subsets_length([_ | T], N, R) :-
    subsets_length(T, N, R).

%generate_subsets(L-list, N-nrOfElements, R-Result)
%flow model:i,i,o
generate_subsets(L, N, Result) :-
    findall(Sub, (subsets1(L, Sub), length(Sub, N)), Result).
