import math

def sum(n):
    s=0
    for i in range(1, n+1):
        if i%2==0:
            s=s-1/i
        else:
            s=s+1/i
    return s

def other_order(n):
    s=0
    for i in range(1, n+1, 2):
        s=s+1/n
    for i in range(2, n+1, 2):
        s=s-1/n
    return s

def main():
    n=int(input("sum of n numbers"))
    print(sum(n))
    print("ln 2= 0.693147")
    print("changing the order of summation in this series leads to ")
    print(other_order(n))
main()