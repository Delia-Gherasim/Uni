function x= bckw(A, b)
  n=length(b);
  x=zeros(n,1);
  for k = n:-1:1
    x(k) = (b(k) - A(k, k+1 : n)* x(k+1:n))/A(k,k);
  endfor
