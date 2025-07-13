A=[1, 2; 3,4];
det(A);
inv(A)*A;
A.*A;
A.^2;
A^2;

v=1:100;
v=1:-0.1:0;
v.^2;
v.^(-1);
v';

#ex 1
x=-4:0.1:7.2;
px=x.^5-5*x.^4-16*x.^3+16*x.^2-17*x+21;
plot(x, px);
p=[1, -5, -16, 16, -17, 21];
polyval(p, -2.5);
roots(p);
polyval(p, 7);

#ex 2
#f,g,h:[0.2 pi] ->R
#f(x)=sin x
x=0:0.1* pi : 2* pi;
f= sin(x);
g=sin(2*x);
h=sin(3*x);
subplot(3,1,1);
plot(x, f);
subplot(3,1,2);
plot(x, g);
subplot(3,1,3);
plot(x, h);

#ex 3
R=3.8;
r=1;
t=0:0.1*pi:10*pi;
xt=(R+r)*cos(t)-r*cos((R/r+1)*t);
yt=(R+r)*sin(t)-r*sin((R/r+1)*t);
clf
plot(xt, yt);

#ex 4
[x, y]=meshgrid(-2:0.1:2, 0.5:0.1:4.5);
z=sin(exp(x)).*cos(log(y));
mesh(x, y, z);
plot3(x, y,z);
clf
#ex5
#f(0)=1+1=2
#f(1)=1+1/2=3/2
# ...
#f(n+1)=1+1/f(n)
ex5(100)
#1.6181 = 1+ radical de 5 /2 golden ration?

