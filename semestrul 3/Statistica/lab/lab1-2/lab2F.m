##f lab 2
pkg load statistics
N=input("Number of simulations: ");
U=rand(3, N);
## n simulations
Y=(U<0.5);
X=sum(Y);
clf;
#osca clear figure
hist(X);
#histograma

