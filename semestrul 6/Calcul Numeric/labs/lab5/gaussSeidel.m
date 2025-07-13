function [x,nit] = gaussSeidel(A, b, x0, err, maxint)
    L = tril(A,-1);
    U = -triu(A,1);
    M = diag(diag(A)) - L;
    N = U;
    T = inv(M) * N;
    c = inv(M) * b;
    x = x0;
    for k=1:maxint
       x = T * x + c;
       if norm(x - x0, inf) <= ((1-norm(T,inf))/(norm(T,inf)))*err
           nit = k;
           return
       end
       x0 = x;
    end
    error('too dificult')
end
