#B2 a
X1=[22.4 21.7 24.5 23.4 21.6 23.3 22.4 21.6 24.8 20.0];
X2=[17.7 14.8 19.6 19.6 12.1 14.8 15.4 12.6 14.0 12.2];
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

#B2 b
c=(var(X1)/n1)/(var(X1)/n1+var(X2)/n2);
aux=c^2/(n1-1)+((1-c)^2)/(n2-1);
n=1/aux;
m1b=mean(X1)-mean(X2)-tinv(1-alfa/2, n)*sqrt((var(X1)/n1)+(var(X2)/n2))
m2b=mean(X1)-mean(X2)+tinv(1-alfa/2, n)*sqrt((var(X1)/n1)+(var(X2)/n2))


#B2 c
#finv is used for the last one
