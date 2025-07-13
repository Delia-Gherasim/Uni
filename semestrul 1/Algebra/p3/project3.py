""""
Project 3

Input: non-zero natural number n
Output:
1. the number of bases of the vector space Z2^n over Z2
2. the vectors of each such basis (for n ≤ 4)
"""

def ex1(n):
    """"
    This function computes the number of bases of the vector space Z2^n over Z2
    with the formula : (q-1)!

    :param n: natural number
    :return: f, number of bases
    """
    q = pow(2, n)
    f = 1
    for i in range(1, q):
        f = f * i
    return f

def all_vectors(n):
    """"
    This function computes all the possible vectors that are going to form the basis by turning all the
    numbers from 0 to 2^n in base two

    :param n: natural number
    :return: all vectors

    """
    number_of_sets = pow(2,n)
    vectors = []
    for i in range(number_of_sets):
        nr = bin(i).replace('b', '0')
        nr = nr[(len(nr) - n):]
        vectors.append(nr)

    return vectors


def ex2(n):
    """function computes all the matrices with linearlly independent vectors
    for every 0 in one vector, we need to have at least another vector that has a 1 on the same position
    """
   
    all_v = all_vectors(n)
    all_v = all_v[1:]
    matrices = []
    if n == 2:
       for i in all_v:
           for j in all_v:
               ok = 0
               for t in range(n):
                   if i[t] == '0' and j[t] == '0': #if on both positions we have 0 or 1, then the vectors are linearlly dependant
                       ok = 1
               if ok == 0:
                   matrices.append([i, j]) #if the vectors are linearlly independant, we add the basis formed by them to the list of basis

    elif n == 3:
       for i in all_v:
           for j in all_v:
               for z in all_v:
                   ok = 0
                   for t in range(n):
                       if i[t] == '0' and j[t] == '0' and z[t] == '0':
                           ok = 1
                   if ok == 0:
                       matrices.append([i, j, z])

    elif n == 4:
       all_v = all_v[3:]
       for i in all_v:
           for j in all_v:
               for z in all_v:
                   for r in all_v:
                       ok = 0
                       for t in range(n):
                           if i[t] == '0' and j[t] == '0' and z[t] == '0' and r[t] == '0':
                               ok = 1
                       if ok == 0:
                           matrices.append([i, j, z, r])

    for i in range(len(matrices)):
       ok = 0
       for j in range(len(matrices[i]) - 1):
           if matrices[i][j] != matrices[i][j+1]:
               ok =1
       if ok == 0:
           del matrices[i]
    return matrices

def main():
    h = open('input3.txt', 'r')
    # Reading from the file
    content = h.readlines()
    # Iterating through the content of the file
    for line in content:
        for i in line:
         # Checking for the digit in the string
         if i.isdigit() == True:
            n=int(i)
    
    file1 = open("output3.txt", "a") 
    file1.write(" 1. the number of bases of the vector space Z2 ^n over Z2 is")
    file1.write(str(ex1(n)))
    
    file1.write(str(len(ex2(n))))
    file1.write("\n")
    file1.write("2. the vectors of each such basis are:")
    file1.write(str(ex2(n)))


main()