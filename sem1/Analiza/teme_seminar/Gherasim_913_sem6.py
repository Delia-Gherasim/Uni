
"""
Using Taylor series, prove that the forward difference(f(x+h)−f(x))/happroximatesthe derivative
f′(x) with an error of orderh(first order approximation), i.e.f′(x) =f(x+h)−f(x)h+O(h),
and that the centered difference(f(x+h)−f(x−h))/2happroximates the derivativef′(x)with an error of orderh2
(second order approximation), i.e.f′(x) =f(x+h)−f(x−h)2h+O(h2).
[Python]  Choose  a  functionf,  a  pointxand  computef′(x).   
By  taking  a  range  of  smallvaluesh,  show that the errors when approximatingf′(x) with the finite differences 
aboveare proportional tohandh2, respectively.
"""

#f(x)=x^2+7x
#f'(x)=2x+7

def function(x):
    return x*x+7*x

def derivative(x):
    return 2*x+7

def first(x, h):
    f=function(x+h)
    f2=function(x)
    return (f-f2)//h

def second(x, h):
    f=function(x+h)
    f2=function(x-h)
    return (f-f2)//(2*h)

x=int(input("x=? "))

print("f'(x)= ",derivative(x))
a=int(input("range of h, h>a= "))
b=int(input ("range of h, h<b="))

for h in range(a, b+1):
    print("first approximation ", first(x, h))
    e=derivative(x)-first(x, h)
    print("with the error order ", e, "\n")
    print("second approximation ", second(x, h))
    e=derivative(x)-second(x, h)
    print("with the error order ", e)