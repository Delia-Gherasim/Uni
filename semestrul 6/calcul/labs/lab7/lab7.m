#divided differences lab3
#first column: x0 ... xn
#second column: f(x0) f(x1) ... f(xn)
#3rd column: f(x0, x1) ... 0
#4th: f(x0, x1, x2) ... 0 0
....
#final column: f(x0, x1, ... xn) 0  ... 0

# D0 = f(x0)
# D1 = f(x0, x1)
# D2= = f(x0, x1, x2)
# ...
# Dn = f(x0, ... xn)

#polynomial newton Nnf(x) = Ln f(x) = D0 + D1 (x-x0) + D2 (x-x0)(x-x1)


# aitken
# x0 P00
# x1 P10 P11
# x2 P20 P21 P22
# ...
# xn Pn0 Pn1 Pn2 Pn3 ... Pnn

# determinant: Pi,j = 1 / xi - x i-j
# i =  1 : n
# j = 1: i

#1
newton([1,2,3], [1,4,9], [5,6]);
x = linspace(0,1);
x0 = [0, 1/3, 1/2, 1];
f = @(x) cos(pi * x);
#plot(x, f(x));
#hold on;
#plot(x, newton(x0, f(x0), x));

x = linspace(0,1);
x0 = [1/5];
f = @(x) cos(pi * x);
newton(x0, f(x0), x);

#3
x = [1001 : 1009];
f = @ (x) log10(x);
x0 = [1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009];
newton(x0, f(x0), x);

#2
x0 = linspace(-4, 4, 9);
f = @ (x) 2.^x;
aitken(x0, f(x0), 1/2)

