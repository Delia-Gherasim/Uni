#lab 3 ex 2

p=input("number p between 0.05 and 0.95 ")
for n=1:3:100
  k=0:n;
  y=binopdf(k, n, p);
  plot(k, y)
  pause(0.5)

endfor

##de fct ulima bulina prefixu poisson
##nu verifica nu fac
