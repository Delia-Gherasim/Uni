# Ax=b
# x0 - gauss
# x1 = Tx0 + c
# x2 = Tx1 + c
# ...
# xk+1 = Txk + c
# || xk+1 - xk || <= 1-|| T || / || T || * epsilon

# A = M - N
# T = M ^ (-1) * N
# c = m ^ (-1) * b

# Jacobi M = D; N = L+U

n = 7;
A=5*eye(n)-diag(ones(1,n-1),1) - diag(ones(1, n-1), -1);
b=[4, 3*ones(1, n-2), 4]';
maxint = 1000;
x0 = zeros(size(b));
err = 10 ^ -5;
jacobi(A, b, x0, err, maxint)
gaussSeidel(A, b, x0, err, maxint)

# ex 2 A
A = [10 7 8 7;7 5 6 5; 8 6 10 9; 7 5 9 10];
b = [32; 23; 33; 31];
x = mldivide(A, b)
# x=inv(A) * b;

# B
b2 = [32.1; 22.9; 33.1; 30.9];
x2 = mldivide(A, b2)
input = norm(b-b2)/norm(b)
output = norm(x-x2)/norm(x)

# C
A3 = [10 7 8.1 7.2;7.8 5.04 6 5; 8 5.98 9.89 9; 6.99 4.99 9 9.98];
x3 = mldivide(A3, b)
input = norm(A-A3)/norm(A)
output = norm(x-x3)/norm(x)

# D
# pt ca mate
condNr = norm(A) * norm(inv(A))

