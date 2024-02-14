% binomial distribution
pkg load statistics
%trebe pus mereu
## ba asa ii coment deci nuj ce face %


## We ask the user to input the required values for the binomial
n=input("Give the nr of trials n= ")
p=input("Give the probability of succes p= ")
## n is a nat number, p is a value between 0 and 1
##x is the nr of successes/values of the pdf
x=0:1:n
px=binopdf(x, n, p)
plot(x, px, 'r+')
hold on
##to have more graphs in the same window scriem hold on
##to give the values for the cdf(cumulative distribution function) you must always "simulate continuity" that is,
xx=0:0.01:n
fx=binocdf(xx, n, p)
plot(xx, fx, 'b')

##cv ca sa invatam cum functioneaza legend cred ca iara zice de lol
##we use hold on & legend to put them toghether

##prob of X=value -> pdf
##pdf: f(x)=P(X=x)
##cdf: F(x)=P(X<=x)

##c
p1=binopdf(0, 3, 0.5);
p2=1-binopdf(1, 3, 0.5);

##d
p3=binocdf(2, 3, 0.5);
p4=binocdf(1, 3, 0.5);
  ##pt ca <2 poate fi luat si ca <=1

##e
##P(X>=1)=1-P(X<1)=1-P(X<=0)=1-P(X=0)
p5=1-binocdf(0, 3, 0.5);
##P(X>1)=1-P(X<=1)
p6=1-binocdf(1, 3, 0.5);

##X<=1 --> we get at most 1 succes

##f




