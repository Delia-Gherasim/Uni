def check_prime(n):
    """
    checks if a given number n is prime
    
    :param n: n natural number
    :return : whether a number is prime 

    """
    if n<2:
        return False
    if n==2:
        return True
    for i in range(2, n):
        if n%i==0:
            return False
    return True

def composed_numbers(x):
    """
    determines how many prime divisors compose a non-prime number
    
    :prime x: natural number
    :return: number of prime divisors

    """
    if x<=5 :
        return 1
    nr=0
    for i in range(2, x):
        if x%i==0:
            nr=nr+1
        while x%i==0:
            x=x/i
    return nr


n=int(input("n natural number "))
x=1
while (n>0):
    if check_prime(x) or x==1:
        n=n-1
        x=x+1
        if n==0:
            print(x-1)
    else:
        if n-composed_numbers(x)<0:
            i=2
            while n:
                if x%i==0:
                    while x%i==0:
                        x=x/i
                n=n-1
                i=i+1
            print (i-1)                
        else:
            if n-composed_numbers(x)==0:
                last_div=1
                for i in range(2, x):
                    if x%i==0:
                        last_div=i
                        while x%i==0:
                            x=x/i
                print(last_div)
                n=0  
            else:
                n=n-composed_numbers(x)
                x=x+1
    