%n.am idee ce se intampla
%nr of occurences of an elem in a list
%occ(l1, l2, ..ln, X)={1+occ(l2,...ln), l1=x
%                      occ(l2, ..ln, X), l1!= X
%                      0, n=0}
%occ(list, element, nrOfElements)
%flow model=(i,i, o), (i,i,i)
%
