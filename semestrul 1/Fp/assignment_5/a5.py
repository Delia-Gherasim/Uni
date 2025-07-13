
# Write below this comment 
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values

def complex_nr(a, b):
    """
    this function creates a complex number using the real and imaginary values

    param a: int number equal to the real part
    param b: int number equal to the imaginary part
    return list consisting of the complex nr
    """
    return [a, b]

def list_of_nr(l, z):
    """
    function creates a list of all the complex nr

    param z: list of nr
    return list l
    """
    l.append(z)
    return l

# Write below this comment 
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values

dictionary ={
}

def dict_of_nr(a, b, nr):
    """
    function creates a dictionary of all the complex nr

    param a: real part
    param b: imaginary part
    param nr: position in the dictionary
    return dictionary
    """
    dictionary[nr]=a
    dictionary[nr+1]=b
    return dictionary
      
# Write below this comment 
# Functions that deal with subarray/subsequence properties
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values

def maxsum(l):
    """computes the maximum sum 
    param l: list
    return: first and last element of the subarray
    """
    maxs=-999999
    current=0
    first=0
    last=0
    f=0
    for i in range(0, len(l)):
        current=current+l[i][0]
        if current>maxs:
            maxs=current
            first=f
            last=i
        if current<0:
            current=0
            f=i+1
    return [first, last]

import math

def modulus(z):
    """
    function computes the modulus of a complex number z

    :param z: complex number
    :return: the modulus
    """
    mod=z[0]*z[0]+z[1]*z[1]
    mod=math.sqrt(mod)
    return mod
    
def subarray_mod(l):
    """
    function computes the maximum lenght of a subarray of nr with the modulus between 0 and 10

    param l: list of complex nr
    return: the first and last element of the subarray if found, 0 otherwise
    """
    lenght=0
    firstel=0
    lastel=0
    lmax=0
    for i in range(0, len(l)):
        z=[l[i][0],l[i][1]]
        if modulus(z)>=0 and modulus(z)<=10:
            if lenght==0:
                first=i
            lenght=lenght+1
            if lenght>lmax:
                lmax=lenght
                firstel=first
                lastel=i
        else:
            lenght=0
    if lmax==0:
        return 0
    return [firstel, lastel]

import random

def generate():
    """
    generates a random number betweem -100 and 100
    
    return: number
    """
    n=random.randint(-100, 100)
    return n 

def generate_list():
    """
    generates a 10 element list of complex numbers

    return: list
    """
    l=[]
    for i in range (0, 10):
        a=generate()
        b=generate()
        l=list_of_nr(l,complex_nr(a, b))
    return l

# Write below this comment 
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities
def print_4(first, last, l):
    """
    function prints a subarray 

    param first: natural nr equal to the first element of a subarray
    param last: natural nr equal to the last element of a subarray
    param l: list of complex nr

    """
    print("subarray with biggest sum: ")
    for i in range(first, last+1):
        a=l[i][0]
        b=l[i][1]
        print("z=",a,"+",b,"*i")
    print("having the lenght equal to: ", last-first+1)

def print_3(first, last, l):
    """
    function prints a subarray 

    param first: natural nr equal to the first element of a subarray
    param last: natural nr equal to the last element of a subarray
    param l: list of complex nr

    """
    print("longest subarray: ")
    for i in range(first, last+1):
        a=l[i][0]
        b=l[i][1]
        print("z=",a,"+",b,"*i")
    print("having the lenght equal to: ", last-first+1)

def read_nr(message):
    """
    inputs a number 

    return: int val
    """
    try:
        val=int(input(message))
        return val
    except:
        print("a number is expected")
        return 0

def display_list(l):
    for i in range(0, len(l)):
        a=l[i][0]
        b=l[i][1]
        print("z=",a,"+",b,"*i")

def display_dictionary(dictionary, n):
    for i in range (0, n-1):
        a=dictionary[str(i)]
        i=i+1
        b=dictionary[str(i)]
        print("z=",a,"+",b,"*i")

def print_options():
    #function prints the menu 
    print("Main Menu: ")
    print("1. Read a new list")
    print("2. Display")
    print("3. Length and elements of a longest subarray of numbers where each number's modulus is in the [0, 10] range ")
    print("4. The length and elements of a maximum subarray sum, when considering each number's real part")
    print("5. Exit \n")
    print("What option would you like? ")

def menu():
    #function prints and executes the menu and allows the user to choose an option
    l=None
    while(True):
        print_options()
        x=int(input("Please enter the coresponding number: "))
        if x==1:
           n=int(input("how many nr do you want to input?"))
           l=[]
           for i in range (0, n):
                nr=0
                a=read_nr("real part: ") 
                b=read_nr("imaginary part")
                #l=dict_of_nr(a, b, nr)
                nr=nr+2
                l=list_of_nr(l,complex_nr(a, b))
        elif x==2:
            if l is not None:
               display_list(l)
               #n=len(l)
               #display_dictionary(dictionary, n)
            else:
               l=generate_list()
               print("list generated randomly: ")
               display_list(l)
        elif x==3:
            if l is not None:
                z=[]
                z=subarray_mod(l)
                print_3(z[0], z[1], l)
            else:
                print("first input a list using the nr 1 option or generate a list randomly using nr 2")
        elif x==4:
            if l is not None:
                z=[]
                z=maxsum(l)
                print_4(z[0], z[1], l)
            else:
                print("first input a list using the nr 1 option or generate a list randomly using nr 2")
        elif x==5:
            print("goodbye")
            break
        else:
            print("not an option\n")
        
menu()
    


