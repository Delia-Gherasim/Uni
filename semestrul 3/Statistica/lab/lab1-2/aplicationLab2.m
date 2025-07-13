pkg load statistics

##aplication 2 a.
##the distribution followed by x is a binomial one
##it's parameters are
##n=3, p=0.5
x=0:1:3
px=binopdf(x, 3, 0.5)
##the probability distribution of x is 0 1 2 3
                                ##1/8, 3/8, 3/8, 1/8

xx=0:0.01:3
fx=binocdf(xx, fx, 'b')
