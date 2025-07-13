#spline(nodes, f(nodes),x) - deBoor spline??
#spline(nodes, [ _ , f(nodes), _ ], x) -complete spline
#pchip(nodes, f(nodes),x ) -piecenies

#Least Squares
#polyfit(nodes, f(nodes), 1)
#polynal(p,x)

#Hernite newton

# 1
f = @ (x) (x+1)/(3*x^2+2*x+1);

# 2
f = @ (x) x.*sin(pi*x);
nodes = [-1, -1/2, 0, 1/2, 1, 3/2];
lspc = linspace(-1, 3/2);
hermite = pchip(nodes, f(nodes), lspc);
y = f(lspc);
s = spline(nodes, f(nodes), lspc);
aa= [pi, f(nodes), -1];
s2 = spline(nodes, f(aa), lspc);
plot(lspc, y);
hold on;
scatter(nodes, f(nodes), 'o');
hold on;
plot(lspc, hermite);
hold on;
plot(lspc ,s);
hold on;
plot(lspc ,s2);
hold off;

#3
x = [0.5 1.5 2 3 3.5 4.5 5 6 7 8];
f = [5 5.8 5.8 6.8 6.9 7.6 7.8 8.2 9.2 9.9];

scatter(x, f, 'o');
hold on;

p = polyfit(x, f, 1);
lspc = linspace(0.5, 8);
f2 = polyval(p, lspc);
plot(lspc, f2);
hold on;

est = polyval(p, 4)
err = norm(polyval(p, x) - f)

hermite = pchip(x, f, lspc);







