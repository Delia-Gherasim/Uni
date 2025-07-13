function x= forward(A, b)
  n=length(b);
  x=zeros(n,1);
  for k = 1:n
    x(k) = (b(k) - A(k, 1:k-1)* x(1:k-1))/A(k,k);
  endfor

