def check_prime(x):
    """
    checks if a number is prime
    
    :param x: natural number
    :return: True if the number is prime or False otherwise
    """
    if x%2==0 or x<2:
        return False
    if x==2:
        return True
    for i in range(3, x):
        if x%i==0:
            return False
    return True

def twin(n):
    """
    determines the next twin prime numbers bigger than a given number n

    :param n:natural number
    """
    x=False
    p1=n
    while x==False:
        p1=p1+1
        if check_prime(p1):
            p2=p1+2
            if check_prime(p2):
                print (p1, p2)
                x=True

n=int(input('write a non-null number n:'))
twin(n)