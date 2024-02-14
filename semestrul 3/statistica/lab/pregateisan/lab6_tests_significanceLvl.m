      #lab6 ex1
#1. In a study of the efficiency of various large computer storage systems, the random
#variable X, the number of (medium-sized) files (in millions) that can be stored is
#considered. If the storage system cannot store at least 8.5 millions (medium-sized)
#files, on average, it does not meet the efficiency standard and has to be improved.
#These data are obtained:
X=[7 7 4 5 9 9 ...
4 12 8 1 8 7 ...
3 13 2 1 17 7 ...
12 5 6 2 1 13 ...
14 10 2 4 9 11 ...
3 5 12 6 10 7];
#a. Assuming that past experience indicates that σ = 5, at the 5% significance level,
#does the data suggest that the standard is met? What about at 1%?

n=length(X);
alfa=input("Significance level: "); %should be 0.05 or 0.01
%the null hipothesys is H0: u(miu)=8.5 (it goes toghether with u>8.5), the standard is met
%the alternative hipothesys H1: u<0.85 (the standard is not met)
%this is a left tailed test for u
printf('left tailed test for the mean when sigma is known \n')
sigma=5;
m0=8.5; %the value we are testing
[H, PVAL, CI, ZVALUE]=ztest(X, m0, sigma, 'alpha', alfa, 'tail', 'left'); %sa nu folosim CI ca cica ii useless
zalfa=norminv(alfa, 0,1);   % tt alfa=zalfa()
RR=[-inf, zalfa];   %prima formula din tests
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
printf('The PValue of the test is: %4.3f \n', PVAL); %the probability of obtaining results as extreme as, or more extreme than, the observed results under the assumption that the null hypothesis is true

#b. Without the assumption on σ, does the data suggest that, on average, the number
#of files stored exceeds 5.5? (same significance level)
alfa=0.05 %significance lvl
%the null hypothesys is H0: u<=5.5
%the alternative hypothesys H1: u>5.5
%right tailed test for u
oneminusalfa=1-alfa;
m0=5.5; %value we are testing
[H, PVAL, CI, ZVALUE]=ztest(X, m0, sigma, 'alpha', alfa, 'tail', 'right');
zalfa=norminv(oneminusalfa, 0, 1);
RR=[zalfa, +inf];
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


                #lab6 ex2
#It is thought that the gas mileage obtained by a particular model of automobile will be higher if unleaded premium gasoline is used in the vehicle rather than
#regular unleaded gasoline. To gather evidence in this matter, 10 cars are randomly selected from the assembly line and tested using a specified brand of premium gasoline;
#10 others are randomly selected and tested using the brand’s regular gasoline. Tests
#are conducted under identical controlled conditions and gas mileages for both types
#of gas are assumed independent and (approximately) normally distributed. These
#data result:
X1=[22.4 21.7 24.5 23.4 21.6 23.3 22.4 21.6 24.8 20.0];
X2=[17.7 14.8 19.6 19.6 12.1 14.8 15.4 12.6 14.0 12.2];

#a. At the 5% significance level, is there evidence that the variances of the two populations are equal?
#the null hypothesys H0: sigma1^2=sigma2^2 (the 2 variances are equal)
#the alternative hypothesis H1: sigma1^2 != sigma2^2
alpha = 0.05;
[H, PVAL, CI, STAT] = vartest2(X1, X2, 'alpha', alpha);
        #PVAL: The p-value associated with the F-test. It helps you make a decision about the null hypothesis.
             #If PVAL is less than your chosen significance level (alpha), you might reject the null hypothesis.
        #STAT: A structure containing additional statistics related to the F-test. For example:
            #STAT.hratio: The hypothesized ratio of variances.
            #STAT.fstat: The F-statistic calculated during the test.

fprintf('Test for Equality of Variances:\n');
fprintf('Hypothesized variances ratio: %4.3f\n', STAT.hratio);
fprintf('F-statistic: %4.3f\n', STAT.fstat);
fprintf('P-value: %4.3f\n', PVAL);
if H == 1
    fprintf('At the %d%% significance level, there is evidence that the variances are not equal.\n', alpha*100);
else
    fprintf('At the %d%% significance level, there is no evidence that the variances are different.\n', alpha*100);
end


#b. Based on the result in part a., at the same significance level, does gas mileage
#seem to be higher, on average, when premium gasoline is used
[H, PVAL, CI, STATS] = ttest2(premium, regular, 'Tail', 'right', 'Alpha', alpha);
if H == 1
    fprintf('At the %g%% significance level, there is evidence that gas mileage is higher,\n', alpha*100);
    fprintf('on average, when premium gasoline is used.\n');
else
    fprintf('At the %g%% significance level, there is no evidence that gas mileage is higher,\n', alpha*100);
    fprintf('on average, when premium gasoline is used.\n');
end

fprintf('P-value for the test: %g\n', PVAL);
fprintf('95%% Confidence Interval for the difference of means: [%g, %g]\n', CI(1), CI(2));
fprintf('t-statistic for the test: %g\n', STATS.tstat);
fprintf('Degrees of freedom: %g\n', STATS.df);
