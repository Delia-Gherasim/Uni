                              %lab2 ex2
%Plot the graphs of the pdf and the cdf of a random variable X having a
%Binomial distribution of parameters n and p (given by the user).
n=input("Give the nr of trials (a nat number) n= ")
p=input("Give the probability of succes (a value between 0 and 1) p= ")
x=0:1:n
px=binopdf(x, n, p)
plot(x, px, 'r+')
hold on     %to have more graphs in the same window scriem hold on

##to give the values for the cdf(cumulative distribution function) you must always "simulate continuity" that is,
xx=0:0.01:n   %adica step size ff mic
fx = binocdf(xx, n, p);
plot(xx, fx, 'b')


                            %lab2 APPLICATION
%A coin is tossed 3 times. Let X denote the number of heads that appear
n=3;
p=0.5;
%a). Find the probability distribution function of X.
                                          ##pdf: f(x)=P(X=x)
x=0:1:n;
px=binopdf(x, n, p);

%b). Find the cumulative distribution function of X, FX.
                                          ##cdf: F(x)=P(X<=x)
xx=0:0.01:n;
fx = binocdf(xx, n, p);

%c). Find P(X = 0) and P(X ̸= 1)
p1=binopdf(0, 3, 0.5);
p2=1-binopdf(1, 3, 0.5);

%d) Find P(X ≤ 2), P(X < 2)
p3=binocdf(2, 3, 0.5);
p4=binocdf(1, 3, 0.5);  ##pt ca <2 poate fi luat si ca <=1

%e) Find P(X ≥ 1), P(X > 1)
##P(X>=1)=1-P(X<1)=1-P(X<=0)=1-P(X=0)
p5=1-binocdf(0, 3, 0.5);
##P(X>1)=1-P(X<=1)
p6=1-binocdf(1, 3, 0.5);

%f) Write a Matlab code that simulates 3 coin tosses and computes the value of the variable X
N=input("Number of simulations: ");
U=rand(3, N); %generates a matrix U of size 3-by-N where each element is a random number between 0 and 1.
              %The rand function is used to create random numbers.
Y=(U<0.5);  % creates a logical matrix Y by comparing each element of U with 0.5.
            % If an element in U is less than 0.5, the corresponding element in Y is set to 1 (true);
            % otherwise, it is set to 0 (false)
X=sum(Y); % This line calculates the sum of each column in the matrix Y.
          % Since each column represents the outcomes of 3 coin tosses, the sum gives the total number of heads (as heads are represented by 1).
          % X is a row vector containing the number of heads in each simulation.
clf; #osca clear figure
hist(X); #histograma




