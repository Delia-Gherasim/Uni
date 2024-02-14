            #lab5 B
# _
# X ii average of vector X
#norminv -> quantile

#1. In a study of the size of various computer storage systems, the random variable
#X, the number of medium-sized files (in millions) that can be stored is considered.

X=[7 7 4 5 9 9 ...
4 12 8 1 8 7 ...
3 13 2 1 17 7 ...
12 5 6 2 1 13 ...
14 10 2 4 9 11 ...
3 5 12 6 10 7];

#a) Assuming that past experience indicates that σ = 5, find a 100(1−α)% confidence interval for the average number of files stored.
  %folosim de la confidence intervals 1. prima pt ca stim sigma si sample-ul ii 36>30 (36 ca atatea is in matrice)
n=length(X);
oneMinusAlfa=input("Confidence level? ");
alfa=1-oneMinusAlfa;
sigma=5;
m1=mean(X)-sigma/sqrt(n)*norminv(1-alfa/2, 0, 1);   #z din formula=norminv()
m2=mean(X)-sigma/sqrt(n)*norminv(alfa/2, 0, 1);
printf("The confidence interval for the mean when sigma is 5 is: ")
printf('(m1,m2)=(%4.3f,%4.3f)', m1, m2)
printf('\n')

#b) Assuming nothing is known about σ, find a 100(1 − α)% confidence interval for the average number of files stored.
  %large sample, we do not knoe sigma
#s -> standard diviation of the given data
m1b=mean(X)-std(X)/sqrt(n)*tinv(1-alfa/2, n-1);   #t = tinv()
m2b=mean(X)-std(X)/sqrt(n)*tinv(alfa/2, n-1);
printf("The confidence interval for the pop mean when sigma unknown is: ")
printf('(m1,m2)=(%4.3f,%4.3f)', m1b, m2b)
printf('\n')

#c) Assuming the number of files stored are approximately normally distributed, find 100(1 − α)% confidence intervals for the variance and for the standard deviation.
    %normally distributed => a normal underlying population
#s^2 is computed with var
#s is computed with std
v1=((n-1)*var(X))/chi2inv(1-alfa/2, n-1);   #X^2 ala fancy ii Chi2() distribution
v2=((n-1)*var(X))/chi2inv(alfa/2, n-1);
printf("The confidence interval for the variance ")
printf('(v1,v2)=(%4.3f,%4.3f)', v1, v2)
printf('\n')
s1=sqrt(v1);
s2=sqrt(v2);
printf("The confidence interval for the standard deviation: ")
printf('(s1,s2)=(%4.3f,%4.3f)', s1, s2)
printf('\n')


            #lab5 ex2
#It is thought that the gas mileage obtained by a particular model of automobile will be higher if unleaded premium gasoline is used in the vehicle rather than
#regular unleaded gasoline. To gather evidence in this matter, 10 cars are randomly selected from the assembly line and tested using a specified brand of premium gasoline;
#10 others are randomly selected and tested using the brand’s regular gasoline. Tests
#are conducted under identical controlled conditions and gas mileages for both types
#of gas are assumed independent and (approximately) normally distributed. These
#data result:
X1=[22.4 21.7 24.5 23.4 21.6 23.3 22.4 21.6 24.8 20.0];
X2=[17.7 14.8 19.6 19.6 12.1 14.8 15.4 12.6 14.0 12.2];

#a) Assuming σ1 = σ2, find a 100(1 − α)% confidence interval for the difference of the true means
      %folosim 3 -> a2a because sigma1=sigma2 unknown
n1=length(X1);
n2=length(X2);
oneMinusAlfa=input("Confidence level? ");
alfa=1-oneMinusAlfa;
sp=sqrt(((n1-1)*var(X1)+(n2-1)*var(X2))/(n1+n2-2));
m1=mean(X1)-mean(X2)-tinv(1-alfa/2, n1+n2-2)*sp*sqrt(1/n1+1/n2);
m2=mean(X1)-mean(X2)+tinv(1-alfa/2, n1+n2-2)*sp*sqrt(1/n1+1/n2);
printf("The confidence interval for the difference of the true means when sigma1=sigma2: ");
printf('(m1,m2)=(%4.3f,%4.3f)', m1, m2)
printf('\n')

#b) Assuming σ1 ̸= σ2, find a 100(1 − α)% confidence interval for the difference of the true means.
  %folosim 3 -> a3a because sigma1!=sigma2 unknown
c=(var(X1)/n1)/(var(X1)/n1+var(X2)/n2);
aux=c^2/(n1-1)+((1-c)^2)/(n2-1);
n=1/aux;
m1b=mean(X1)-mean(X2)-tinv(1-alfa/2, n)*sqrt((var(X1)/n1)+(var(X2)/n2))
m2b=mean(X1)-mean(X2)+tinv(1-alfa/2, n)*sqrt((var(X1)/n1)+(var(X2)/n2))

#c) Find a 100(1 − α)% confidence interval for the ratio of the variances.
  %folosim 4
s1=var(x1)
s2=var(x2)
r1=(1/finv(1-alfa/2, n1-1, n2-1))*(s1/s2)
r2=(1/finv(alfa/2, n1-1, n2-1))*(s1/s2)
printf("The confidence interval for the difference of the ratio of variances sigma1^2/sigma2^2:  ");
printf('(r1, r2)=(%4.3f, %4.3f)', r1, r2)
printf('\n')

