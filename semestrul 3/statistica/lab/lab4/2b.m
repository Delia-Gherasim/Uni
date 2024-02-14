#2b binomial distribution

n=input("n= ");#nr of trials
p=input("p= ");#prob of success
N=input("N= ");#nr of simulations
U=rand(n, N);
X=sum(U<p);
k=0:N;
p_k=binopdf(k, N, p);
U_X=unique(X);
n_X=hist(X, length(U_X));
rel_freq=n_X/N  #tells you how many of each did you get out of all data -> asta se face cu stelute
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')
