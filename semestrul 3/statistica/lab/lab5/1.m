#B 1a
X=[7 7 4 5 9 9 ...
4 12 8 1 8 7 ...
3 13 2 1 17 7 ...
12 5 6 2 1 13 ...
14 10 2 4 9 11 ...
3 5 12 6 10 7];
n=length(X);
oneMinusAlfa=input("Confidence level? ");
alfa=1-oneMinusAlfa;

# _
# X ii average of vector X
#norminv -> quantile

sigma=5;
m1=mean(X)-sigma/sqrt(n)*norminv(1-alfa/2, 0, 1);
m2=mean(X)-sigma/sqrt(n)*norminv(alfa/2, 0, 1);
printf("The confidence interval for the mean when sigma is 5 is: ")
printf('(m1,m2)=(%4.3f,%4.3f)', m1, m2)
printf('\n')


#B 1b
#s -> standard diviation of the given data
m1b=mean(X)-std(X)/sqrt(n)*tinv(1-alfa/2, n-1);
m2b=mean(X)-std(X)/sqrt(n)*tinv(alfa/2, n-1);
printf("The confidence interval for the pop mean when sigma unknown is: ")
printf('(m1,m2)=(%4.3f,%4.3f)', m1b, m2b)
printf('\n')



#B ic
#s^2 is computed with var
#s is computed with std
v1=((n-1)*var(X))/chi2inv(1-alfa/2, n-1);
v2=((n-1)*var(X))/chi2inv(alfa/2, n-1);
printf("The confidence interval for the variance ")
printf('(v1,v2)=(%4.3f,%4.3f)', v1, v2)
printf('\n')
s1=sqrt(v1);
s2=sqrt(v2);
printf("The confidence interval for the standard deviation: ")
printf('(s1,s2)=(%4.3f,%4.3f)', s1, s2)
printf('\n')


