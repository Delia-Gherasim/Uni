% rand(size) produces random values that are uniformly distributed over the interval (0, 1).
% randn(size) produces values that follow a Gaussian distribution (bell-shaped curve).
% randi([low, high], size) produces random integers

                %lab4 ex2
% Using a U(0, 1) (standard Uniform) random number generator, generate the common discrete probability distributions:
          #rand

%a. Bernoulli Distribution Bern(p), with parameter p ∈ (0, 1): X( 0 1; 1−p p )
N=input("N= "); #nr of simulations
p=input("probability between 0, 1: ");
U=rand(1, N); #generates n random nr in a uniform distr
X=(U < p);  %creates a logical array (X)
            %where each element is true if the corresponding element in U is less than p, and false otherwise. Essen
U_X=[0 1];  %a vector U_X containing the possible outcomes
n_X=hist(X, length(U_X)); % uses the hist function to calculate the number of occurrences of each outcome in X
rel_freq=n_X/N; %calculates the relative frequencies of each outcome by dividing the counts in n_X by the total number of trials N



%b.  Binomial Distribution Bino(p), with parameters n ∈ IN, p ∈ (0, 1): X
n=input("n= ");#nr of trials
p=input("p= ");#prob of success
N=input("N= ");#nr of simulations
U=rand(n, N); #generates N sets of n random trials
X=sum(U<p);   #counts the nr of successes in each set
k=0:N;
p_k=binopdf(k, N, p); #the theoretical probability mass function
U_X=unique(X);
n_X=hist(X, length(U_X));
rel_freq=n_X/N  #tells you how many of each did you get out of all data -> asta se face cu stelute
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')



%c. Geometric Distribution Geo(p), with parameter p ∈ (0, 1): X(k; pq^k)k∈IN
p=input("prob of success: ");
N=input("nr of simulations: ");
X=zeros(1, N);  #line vector with N entrys which contains 0
for i=1:N
  X(i)=0;
  while rand>=p #counts the nr of trials needed to achieve a success
    X(i)=X(i)+1;  #in this case success is considered a fail ca ii mai mare ca prob dar ok
  endwhile
endfor
k=0:20;     #represents the possible values of the random variable in the context of a geometric distribution.
            #un vector de la 0 la 20
p_k=geopdf(k, p); #calc the probability mass function (PMF) values for each value in the vector k for a geometric distribution with parameter p
U_X=unique(X);  # a vector containing the counts of occurrences of each unique value in X
n_X=hist(X, length(U_X));
rel_freq=n_X/N  #tells you how many of each did you get out of all data -> asta se face cu stelute
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')  #circle theoretical, starts are simulated



% d. Pascal Distribution NB(n, p) with parameters n ∈ IN, p ∈ (0, 1): X
n = input("Number of successes n: ");
p = input("Probability of success p: ");
N = input("Number of simulations: ");
X = zeros(1, N);
for i = 1:N       #This loop performs N simulations of a Pascal distribution
    successes = 0;
    trials = 0;     #In each simulation, it keeps generating random trials (using rand)
    while successes < n   #until it accumulates n successes
        if rand <= p
            successes = successes + 1;
        end
        trials = trials + 1;
    end
    X(i) = trials;  #The total number of trials needed for n successes is stored in the vector X for each simulation
end

k = 0:max(X);
p_k = nbinpdf(k, n, p);
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X / N;
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')  % Circle for theoretical, stars for simulated
xlabel('k');
ylabel('Probability');
title('Pascal (Negative Binomial) Distribution Simulation');
legend('Simulated', 'Theoretical', 'Location', 'NorthEast');



% e. Poisson Distribution Pois(λ) with parameter λ > 0: X
lambda = input("Lambda: ");
N = input("Number of simulations: ");
X = poissrnd(lambda, 1, N);  % Generate random samples from a Poisson distribution

k = 0:max(X);
p_k = poisspdf(k, lambda);
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X / N;
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')  % Circle for theoretical, stars for simulated
xlabel('k');
ylabel('Probability');
title('Poisson Distribution Simulation');
legend('Simulated', 'Theoretical', 'Location', 'NorthEast');



% f. Discrete Uniform Distribution Unif(a, b) with parameters a and b (a < b): X
a = input("Lower bound a: ");
b = input("Upper bound b: ");
N = input("Number of simulations: ");
X = unidrnd(b - a + 1, 1, N) + a - 1;  % Generate random samples from a discrete uniform distribution

k = a:b;
p_k = 1 / (b - a + 1) * ones(size(k));  % Probability mass function for discrete uniform distribution
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X / N;
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')  % Circle for theoretical, stars for simulated
xlabel('k');
ylabel('Probability');
title('Discrete Uniform Distribution Simulation');
legend('Simulated', 'Theoretical', 'Location', 'NorthEast');



% g. Hypergeometric Distribution Hypergeo(N, K, n) with parameters N, K, and n (K ≤ N, n ≤ N): X
N = input("Population size N: ");
K = input("Number of success states in the population K: ");
n = input("Number of draws n: ");
M = min(K, n);  % Maximum possible successes
N_trials = input("Number of simulations: ");
X = hygernd(N, K, n, N_trials);  % Generate random samples from a hypergeometric distribution

k = 0:M;
p_k = hygepdf(k, N, K, n);
U_X = unique(X);
n_X = hist(X, length(U_X));
rel_freq = n_X / N_trials;
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')  % Circle for theoretical, stars for simulated
xlabel('k');
ylabel('Probability');
title('Hypergeometric Distribution Simulation');
legend('Simulated', 'Theoretical', 'Location', 'NorthEast');

