"""
Input: non-zero natural number n
 Output:
1. the number of associative operations on a set A = {a1, . . . , an}
2. the operation table of each associative operation (for n ≤ 4)

"""
import random
import string
import numpy
import itertools

random.choice(string.ascii_letters)
def ex1(n):
    """
    function computes the number of associative operations on a set A = {a1, . . . , an}, using the formula:
    number of associative op = n ^( (n^2+n)/2)
    :param n: non-zero natural number
    """
    n2=pow(n, 2)
    n2=(n2+n)//2
    return pow(n, n2)

def matrix(n):
    """function computes an example matrix, such as
        x y
        z t    ∈ M2(A) 
    :param n: non-zero natural number
    """

    m=[]
    arr=[]
    for j in range(n):
        for i in range(n):
            arr.append(random.choice(string.ascii_letters))
        m.append(n)

    return m
    
def operation_table(n):
    """function computes an example operation table, such as
          a1 a2
        a1 x y
        a2 z t    
    :param n: non-zero natural number
    """
    a=[]

    m=matrix(n)
    m=numpy.mat(m)

    for i in range(1,n+1): 
        var="a"
        i=str(i)
        var=var+i
        a.append(var)

    m=numpy.insert(m, 0, a, axis=1)
    m.append(a)
    return m
    
def ex2(n):
    """ function computes operation tables of the associative operations on A = {a1, . . . , an} by first computing a vector, arr, which contains the values on A
    than, using the function itertools, we compute all posible combinations of the elements in A, such as {a1, a1, a1...}, {a1, a1,... an}, ... {an, an, ...an} which we append to a vector v
    
    """
    arr=[]
    vect=[]
    all=[]
    
    for i in range(1,n+1): 
        var="a"
        i=str(i)
        var=var+i
        arr.append(var)

    for i in range(n):
        vect.append(list(itertools.product(arr, repeat=3)))

    for i in range(n):
        for j in range(i, n):
            m=[[]]
            m=vect[i]
            m.append(vect[j])
            all.append(m)

    return all
    

def menu():

    h = open('input1.txt', 'r')
    # Reading from the file
    content = h.readlines()
# Iterating through the content
# Of the file
    for line in content:
        for i in line:
         # Checking for the digit in
         # # the string
         if i.isdigit() == True:
            n=int(i)


    file1 = open("input1.txt", "a") 
    file1.write(" 1. The number of associative operations on a set A={ ",)
    for i in range(1, n+1):
        list=["a",i, ","]
        string=' '.join(map(str, list))
        file1.write(string)

    res=ex1(n)
    list=["} is", res]
    string=' '.join(map(str, list))
    file1.write(string)

    file1.write("\n")
    list=["2. identifying an operation table by the matrix",matrix(n), "∈ M", n,"(A), the operation tables of the associative operations on A = {" ]
    string=' '.join(map(str, list))
    file1.write(string)

    for i in range(1, n+1):
        list=["a",i, ","]
        string=' '.join(map(str, list))
        file1.write(string)

    file1.write("} are given by the matrices:" )
    file1.write("\n")
    mat=ex2(n)
    for v in mat:
        file1.write(v)
        file1.write("\n")

menu()