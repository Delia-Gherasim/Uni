#Gherasim Delia-913 optional homework

"""
Test data:
b=10, h=2, x=4 
x=22, y=2, b=10
"""
def div_in_base(x, y, b):
    if b<=10:
        r=x%y
        div=x//y
        return div, r
    else:
        x_b10=0
        y_b10=0
        p=1
        for i in range (x+1):
            c=x%10
            x_b10 = x_b10 + c *p
            x=x/10
            p=p*b
        p=1
        for i in range (y+1):
            c=y%10
            y_b10 = y_b10 + c *p
            y=y/10
            p=p*b
        r=x%y
        div=x//y



def succesive_div(b, h, x):
    """
    conversion of a number between 2 bases if the destination base is smaller than the original base

    :param b: positive integer, original base
    :param h: positive integer, destination base
    :param x: positive integer, original nr

    :return: new number

        pseudocod:
    y=0
    cat timp x!=0:
        y=y*10+x mod h
        x=x/10
    returneaza y
    """
    y=0
    while (x):
        y=y*10+x%h
        x=x//h
    return y

def substitution(b, h, x):
    """
    conversion of a number between 2 bases using the substitution method

    :param b: positive integer, source base
    :param h: positive integer, destination base
    :param x: positive integer, original nr

    :return: new number

        pseudocod:
    p=0
    new=0
    cat timp x!=0:
        c=x mod 10
        x=x div 10
        power=1
        daca p>0:
            pentru i de la 0 la p:
                power=multiplication(power, h, h)      #multiplication in base h using a user-defined function
        new=addition(multiplication(power, c, h),new, h) #addition in base h using a user-defined function
        p=p+1
    returneaza new
    """

    p=0
    new=0
    while (x):
        c=x%10
        x=x//10
        power=1
        if p>0:
            for i in range(p):
                power=multiplication(power, h, h)
        new=addition(multiplication(power, c, h),new, h)
        p=p+1
    return new

def base_10(b, h, x):
    """
    conversion of a number between 2 bases using base 10 as an intermediary base

    :param b: positive integer,  source base
    :param h: positive integer, destination base
    :param x: positive integer, original nr

    :return: new number

        pseudocod
    p=1
    y=0
    cat timp x!=0:
        y=y+x mod 10*p
        p=p*b
        x=x div 10
    x=0
    cat timp y!=0:
        x=x*10+y mod h
        y=y div h
    returneaza x
    """

    p=1
    y=0
    while (x):
        y=y+x%10*p
        p=p*b
        x=x//10
    x=0
    while (y):
        x=x*10+y%h
        y=y//h
    
    p=1
    y=0
    while (x):
        y=y*10+x%10
        x=x//10
    return y
    #return x

def rapid_conv(b, h, x):
    """
    conversion of a number between 2 bases using the rapid conversions table

    :param b: positive integer,  source base
    :param h: positive integer, destination base
    :param x: positive integer, original nr
    :return: new number
    """
    x=str(x)
    bases=[["0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"],
        ["00", "01", "02", "03", "10", "11", "12", "13", "20", "21", "22", "23", "30", "31", "32", "33"],
        ["000", "001", "002", "003", "004", "005", "006", "007", "010", "011", "012", "013", "014", "015", "016", "017"],
        ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']]
    nr=[]
    if b==2:
        b=0
        while x:
            if len(x)>=4:
                a=x[-4:]
                x=x[:-4]
            else:
                if len(x)==1:
                    a="000"
                    a+=x
                elif len(x)==2:
                    a="00"
                    a+=x
                elif len(x)==3:
                    a="0"
                    a+=x
            nr.append(a)
    elif b==4:
        b=1
        while x:
            if len(x)>=2:
                a=x[-2:]
                x=x[:-2]
            else:
                if len(x)==1:
                    a="0"
                    a+=x
            nr.append(a)
    elif b==8:
        b=2
        while x:
            if len(x)>=3:
                a=x[-3:]
                x=x[:-3]
            else:
                if len(x)==1:
                    a="00"
                    a+=x
                elif len(x)==2:
                    a="0"
                    a+=x
            nr.append(a)
    elif b==16:
        b=3
        while x:
            a=x[-1:]
            x=x[:-1]
            nr.append(a)
    new=0
    
    if h==2:
        h=0
    elif h==4:
        h=1
    elif h==8:
        h=2
    elif h==16:
        h=3

    for i in range(len(nr)-1, 0, -1):
        if nr[i] in bases[b]:
            ind=bases[b].index(nr[i])
            new=new*pow(10, h)+bases[h][ind]
    
    return new

def addition(x, y, b):
    """
    addition of two numbers in a given base

    :param x: positive integer, natural number
    :param y: positive integer, natural number
    :param b: positive integer, base

    :return: result

        pseudocod
    z=0
    p=1
    result=0
    cat timp x!=0 sau y!=0:
        digit=x mod 10+y mod 10+result
        x=x div 10
        y=y div 10
        result=digit div b
        remainder=digit mod b
        z=z+remainder*p
        p=p*10
    return z
    """
    z=0
    p=1
    result=0
    while x or y:
        digit=x%10+y%10+result
        x=x//10
        y=y//10
        result=digit//b
        remainder=digit%b
        z=z+remainder*p
        p=p*10
    return z

def subtraction(x, y, b):
    """
    substraction of two numbers in a given base

    :param x: positive integer, natural number
    :param y: positive integer, natural number
    :param b: positive integer, base

    :return: result

        pseudocod
    daca x<y:
        interschimbare(x, y)
    z=0
    p=1
    cat timp y>0:
        daca x mod 10<y mod 10:
            x=x-10
            digit=x mod 10+b-y mod 10
        else:
            digit=x mod 10-y mod 10
        x=x div 10
        y=y div 10
        z=digit*p+z
        p=p*10
    return z
    """
    #if x<y:
     #   x,y=y,x
    z=0
    p=1
    while y>0:
        if x%10<y%10:
            x=x-10
            digit=x%10+b-y%10
        else:
            digit=x%10-y%10
        #if digit>b:
         #   digit=base_10(10, b, digit)
        x=x//10
        y=y//10
        z=digit*p+z
        p=p*10
    return z

def multiplication(x, y, b):
    """
    multiplication of two numbers in a given base

    :param x: positive integer, natural number
    :param y: positive integer, natural number
    :param b: positive integer, base

    :return: result

        pseudocod
    z=0
    p=1
    cat timp x!=0:
        result=x mod 10*y mod b
        remainder=x%10*y div b
        z=result*p+z
        p=p*10
        x=x div 10+remainder
    return z
    """
    z=0
    p=1
    while x:
        result=x%10*y%b
        remainder=x%10*y//b
        z=result*p+z
        p=p*10
        x=x//10+remainder
    return z

def division(x, y, b):
    """
    division of two numbers in a given base

    :param x: positive integer, natural number
    :param y: positive integer, natural number
    :param b: positive integer, base

    :return: result

    z=0
    aux=x
    nr=0
    p=1
    cat timp aux!=0:
        p=p*10
        aux=aux div 10
    remainder=0
    cat timp x!=0:
        d=(x div p)%10+remainder*10
        power=1
        daca d>=b:
            z=z*power+d div b
            remainder=d mod b
            power=power*10
        altfel:
            remainder=d
            z=z*power
            power=power*10
        p=p div 10
    return z
    """
    
    z=0
    aux=x
    nr=0
    p=1
    while aux:
        p=p*10
        aux=aux//10
    remainder=0
    while x>0:
        d=(x//p)%10+remainder*10
        power=1
        if d>=b:
            z=z*power+d//b
            remainder=d%b
            power=power*10
        else:
            remainder=d
            z=z*power
            power=power*10
        p=p//10
    return z

def print_options():
    print("^^ Gherasim Delia group 913 optional homework ^^")
    print("1. algorithm for the method of successive divisions")
    print("2. algorithm for the substitution method")
    print("3. algorithm for conversion using 10 as an intermediate base")
    print("4. rapid conversions (executable form) between two bases p,qÎ{2, 4, 8, 16}.")
    print("5. addition of two numbers in a base")
    print("6. subtraction of two numbers in a base")
    print("7. multiplication of a number by a digit in a base")
    print("8. division of a number by a digit in a base")
    print("9. exit")

def menu():
    while (True):
        print_options()
        o=int(input("option "))
        if o==1:
            b=int(input("source base: "))
            h=int(input("destination base: "))
            if h>=b:
                print("destination base should be smaller")
            else:
                x=int(input("number:"))
                print(succesive_div(b, h, x))
        elif o==2:
            b=int(input("source base: "))
            h=int(input("destination base: "))
            x=int(input("number:"))
            print(substitution(b, h, x))
        elif o==3:
            b=int(input("source base: "))
            h=int(input("destination base: "))
            x=int(input("number:"))
            print(base_10(b, h, x))
        elif o==4:
            b=int(input("source base: "))
            h=int(input("destination base: "))
            x=int(input("number:"))
            print(rapid_conv(b, h, x))
        elif o==5:
            b=int(input("source base: "))
            x=int(input("first number:"))
            y=int(input("second number: "))
            print(addition(x, y, b))
        elif o==6:
            b=int(input("source base: "))
            x=int(input("first number:"))
            y=int(input("second number: "))
            print(subtraction(x, y, b))
        elif o==7:
            b=int(input("source base: "))
            x=int(input("first number:"))
            y=int(input("second number: "))
            if x<y:
                x,y=y,x
            if y>=b:
                print("the digit should be in the given base")
            else:
                print(multiplication(x, y, b))
        elif o==8:
            b=int(input("source base: "))
            x=int(input("first number:"))
            y=int(input("second number: "))
            if x<y:
                x,y=y,x
            if y>=b:
                print("the digit should be in the given base")
            else:
                print(division(x, y, b))
        else: 
            break

menu()
    


