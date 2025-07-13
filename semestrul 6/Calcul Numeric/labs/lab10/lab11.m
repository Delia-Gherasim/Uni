f = @(x) 2/sqrt(pi) * exp(-x.^2);
a=0;
error=0.1;
m=4;
for b=[0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1]
  res = ad_trapezoid(f, a, b, error, m)
  int=integral(f,a,b)
 endfor
