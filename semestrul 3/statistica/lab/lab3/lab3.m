#lab 3 -1a
#clear -> variabile
#clc -> clear window

m=input("m= "); #mean of the normal??
sigma=input("sigma= ");
#sigma>0 standard deviation
alfa=input("alfa= ");
beta=input("beta= ");
#0< alfa, beta <1
a1=normcdf(0, m, sigma)

#P(X>=0)=1-P(X<0)=1-P(X<=0)
a2=1-normcdf(0, m, sigma)

#p(a<X<=b)=F(b)-F(a)
#P(-1<=X<=1)=normcdf(1, m, sigma)-normcdf(-1, m, sigma)
#daca ii continuous atunci <= si < ii tot aia

#P((X<=-1) U (X>=1))=1-P(-1<X<1)

#Quantile = "inverse" of the cdf
x_alfa=norminv(alfa, m, sigma)
x_beta=norminv(1-beta, m, sigma)


#pt fishers law: fcdf
#trebe numa sa cautam in help pdf ce prefix punem pt pdf si restu ii exact la fel nu te panica


