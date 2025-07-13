printf('The values of the standard method are: \n');
X1=[46 37 39 48 47 44 35 31 44 37]
printf('The values of the new method are: \n');
X2=[35 33 31 35 34 30 27 32 31 31]
printf('The significance level is : \n');
alpha=0.05

%a. at 5% significance, do the population variances differ?

#the null hypothesys H0: sigma1^2=sigma2^2 (the 2 variances are equal)
#the alternative hypothesis H1: sigma1^2 != sigma2^2
%to test the alternative hypothesis we perform a 2 tailed test

[H, PVAL, CI, STATS] = vartest2(X1, X2, 'alpha', alpha);
        #PVAL: The p-value associated with the F-test. It helps you make a decision about the null hypothesis.
             #If PVAL is less than your chosen significance level (alpha), you might reject the null hypothesis.
        #STAT: A structure containing additional statistics related to the F-test:
            #STAT.fstat: The F-statistic calculated during the test.

fprintf('Test for Equality of Variances:\n');
fprintf('P-value: %4.3f\n', PVAL);
if H == 1
    fprintf('At the %d%% significance level, that the variances are not equal.\n', alpha*100);
else
    fprintf('At the %d%% significance level, there is no evidence that the variances are different.\n', alpha*100);
end



%b.the new method is more efficient?

%the alternative hypothesis H1: sigma1>sigma2, meaning the standard method takes longer than the new
%the more efficient method being the one that takes the least amount of time
%we perform a right-tailed test, the result is given by the value of H
fprintf('\n \n Test for efficiency:\n');
[H, PVAL, CI, STATS] = ttest2(X1, X2, 'Tail', 'right', 'Alpha', alpha);
if H == 1
    printf('The standard method takes, on average, more time \n');
    fprintf('At the %g%% significance level, the new method is more efficient\n', alpha*100);

else
    printf('The new method takes, on average, more time \n');
    fprintf('At the %g%% significance level, the old method is more efficient,\n', alpha*100);

end
