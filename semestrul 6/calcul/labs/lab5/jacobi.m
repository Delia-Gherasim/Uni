function [x,nit] = jacobi(A, b, x0, err, maxint)
    M = diag(diag(A));
    N = M - A;
    c = inv(M) * b;
    T = inv(M) * N;
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
