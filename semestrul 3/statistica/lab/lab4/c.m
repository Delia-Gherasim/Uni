p=input("prob of success: ");
N=input("nr of simulations: ");
X=zeros(1, N);  #line vector with N entrys which contains 0
for i=1:N
  X(i)=0;
  while rand>=p
    X(i)=X(i)+1;
  endwhile
endfor
k=0:20;
p_k=geopdf(k, p);
U_X=unique(X);
n_X=hist(X, length(U_X));
rel_freq=n_X/N  #tells you how many of each did you get out of all data -> asta se face cu stelute
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')  #circle theoretical, starts are simulated
