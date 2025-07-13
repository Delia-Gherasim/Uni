X=[7 7 4 5 9 9 ...
4 12 8 1 8 7 ...
3 13 2 1 17 7 ...
12 5 6 2 1 13 ...
14 10 2 4 9 11 ...
3 5 12 6 10 7];
n=length(X);
alfa=input("Significance level: "); %should be 0.05 or 0.01

%lab6 ex1 a).
%the null hipothesys is H0: u(miu)=8.5 (it goes toghether with u>8.5), the standard is met
%the alternative hipothesys H1: u<0.85 (the standard is not met)
%this is a left tailed test for u

printf('left tailed test for the mean when sigma is known')
printf('\n')
sigma=5;
m0=8.5; %the value we are testing

[H, PVAL, CI, ZVALUE]=ztest(X, m0, sigma, 'alpha', alfa, 'tail', 'left'); %sa nu folosim CI ca cica ii useless

zalfa=norminv(alfa, 0,1);
RR=[-inf, zalfa];

printf('H is %4.3f \n', H);
if (H==1)
  printf('The null hypothesys is rejected \n');
  printf('the data sugests that the standard is not met \n');
else
  printf('The null hypothesys is not rejected \n');
  printf('The data sugests that the standard is met \n');
endif

printf('The rejection region is: (%4.3f,%4.3f) \n', RR);
printf('The observed value of the test statistic is: %4.3f \n', ZVALUE);
printf('The PValue of the test is: %4.3f \n', PVAL);
%find the role of each

%hint for 1b: ttest -> stats ii observed value of the test statistics ii imp si ca sa aflam STATS.tstat ca ii struct
%                   ->right tailed test for the mean
%hint for 2a: vartest2 -> two tailed test for ratio of variances/comparing variances

%hint for 2b: ttest2 -> right tailed test for the difference of means
%also show the rejection region
