#classical formula
#u(x)=(x-x0)* ... * (x-xn)
#uj(x) = u(x)/x-xi
#lj(x) = uj(x) / uj(xj)
#Lnf(x) = sum lj(x) * fj

#baricentrical formula, same but more efficient
#Lnf(x) = u(x) * sum ((1/uj(xj)) / (x- xj)) * fj
# (1/uj(xj)) = wj adica weight

#ex 1 b
x0 = linspace(-2, 4, 10);
f = @(x) (x+1)./(3*x.^2+2*x+1);
plot(x0, f(x0),'o');
hold on;
x = linspace(-2, 4, 500);
plot(x, f(x));
plot(x, classical_Louis(x0, f(x0), x));

c = max(abs(f(x) - classical_Louis(x0, f(x0), x)))

#ex 3
x3 = [100, 121, 144];
y3 = sqrt(x3);
xi = 118;
result = classical_Louis(x3, y3, xi)
actual_result = sqrt(118)
err = abs(actual_result - result)

#ex 2
years = [1980 1990 2000 2010 2020];
population = [4451 5287 6090 6970 7821];

find = [2005, 2015];
result = barycentrical_Louis(years, population, find)

actual = [6474, 7405];
err = abs(actual - result)






