def check_if_prime(n):
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

def twin(n):
    """
    determines the prime numbers p1 and p2 such that n=p1+p2

    :param n: natural number 
    """
    for p1 in range(2, n):
        if check_if_prime(p1)==True:
            p2=n-p1
            if check_if_prime(p2):
                print(p1, p2)
                return True
    return False


n=int(input("natural non-null number: "))
if n<=2:
    print("numbers do not exist")
else:
    if twin(n)==False:
        print("numbers do not exist")

