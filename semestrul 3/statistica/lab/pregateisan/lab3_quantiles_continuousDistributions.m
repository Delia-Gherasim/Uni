          %lab3 ex1
%. Let X have one of the following distributions:
%X ∈ N(µ, σ) (Normal), for continuous data that is symmetrically distributed around a mean (μ) and has a fixed standard deviation (σ).
%X ∈ T(n)(Student), Use the t-distribution when dealing with small sample sizes or when the population standard deviation is unknown.
%X ∈ χ2(n), for situations involving the sum of squared standard normal deviates.
%or X ∈ F(m, n) (Fisher) (all continuous). for comparing variances between two independent samples.

%Compute the following:
    % I Normal:
%a) P(X ≤ 0) and P(X ≥ 0);
m=input("m= "); #mean of the normal??
sigma=input("sigma= "); #sigma>0 standard deviation
a1=normcdf(0, m, sigma); %This line calculates the cumulative distribution function (CDF) value at 0
                        %for a normal distribution with mean m and standard deviation sigma.

#P(X>=0)=1-P(X<0)=1-P(X<=0)
a2=1-normcdf(0, m, sigma);

%b) P(−1<=X<=1) and P(X<=−1 or X>=1)
                  #p(a<X<=b)=F(b)-F(a)
printf('P(-1<=X<=1) \n');
p1=normcdf(1, m, sigma)-normcdf(-1, m, sigma)
                  #daca ii continuous atunci <= si < ii tot aia

#P((X<=-1) U (X>=1))=1-P(-1<X<1)
p2=1-p1;

%c) the value xα such that P(X < xα) = P(X ≤ xα) = α,
%for α ∈ (0, 1) (xα is called the quantile of order α)

 #Quantile = "inverse" of the cdf
alfa=input("alfa= ");
x_alfa=norminv(alfa, m, sigma);

%d) the value xβ such that P(X > xβ) = P(X ≥ xβ) = β,
%for β ∈ (0, 1) (xβ is the quantile of order 1 − β)
beta=input("beta= "); #0< alfa, beta <1
x_beta=norminv(1-beta, m, sigma);

    % II Student
%a) P(X ≤ 0) and P(X ≥ 0);
n=input('pozitive integer: Degrees of freedom = ');
a1=tcdf(0, n);
a2=1-tcdf(0, n);

%b) P(−1 ≤ X ≤ 1) and P(X ≤ −1 or X ≥ 1);
p1=tcdf(1, n)-tcdf(-1, n);
p2=1-p1;

% c) the value x_alpha such that P(X < x_alpha) = P(X ≤ x_alpha) = alpha
alpha = input("alpha (between 0 and 1): ");
x_alpha = tinv(alpha, n);

% d) the value x_beta such that P(X > x_beta) = P(X ≥ x_beta) = beta
beta = input("beta (between 0 and 1): ");
x_beta = tinv(1 - beta, n);

      % III Chi2
%tot la fel da cu functia chi2(X, df), df adica tot degrees of freedom
%pt a si b chi2cdf
%pt c si d chi2inv

      %IV Fisher
%tot la fel da cu functia f(X, m, n), m si n adica tot degrees of freedom
%pt a si b fcdf
%pt c si d finv



               %lab3 ex2
%Approximations of the Binomial distribution

%Normal approximation of the Binomial distribution:
%For moderate values of p (0.05 ≤ p ≤ 0.95) and large values of n (n → ∞),
%    Bino(n, p) ≈ Norm(µ = np, σ =sqrt(np(1 − p)))
%Write a Matlab code to visualize how the Binomial distribution gradually takes
%the shape of the Normal distribution as n → inf

p=input("number p between 0.05 and 0.95 ")
for n=1:3:100
  k=0:n;      %gen vector cu val de la 0 la n
  y=binopdf(k, n, p); %la lab o fct asa deci prob ii mai bn
  y2=normpdf(k, n*p, sqrt(n*p*(1-p))); %asta ii dupa cum ii cerinta idk
  plot(k, y2)
  pause(0.5)

endfor

%Poisson approximation of the Binomial distribution:
%If n ≥ 30 and p ≤ 0.05, then Bino(n, p) ≈ Poisson(λ = np)

p=input("number p less than 0.05 ")
for n=30:3:100
  lambda = n * p;   %l.o dat in cerinta
  k=0:n;
  y=poisspdf(k, lambda);
  plot(k, y)
  pause(0.5)
endfor

%deci forurile astea de fiecare data cand se schimba n.u baga un graf nou gen o data la juma de sec
