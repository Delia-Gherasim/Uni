import random

def generate_list(n):
    x=random.randint(0, 100)
    l=[x]
    for i in range(n-1):
        x=random.randint(0, 100)
        l.append(x)
    return l

def consistent(x, n, l):
    peak=0          
    for i in range(1, len(x)-1):
        if peak==0:
            if l[x[i-1]]<l[x[i]] and l[x[i]]>l[x[i+1]]:
                peak=1
            if l[x[i-1]]>=l[x[i]] :#or l[x[i]]<=l[x[i+1]]:
                return False
        else:
           if l[x[i-1]]<=l[x[i]] or l[x[i]]<=l[x[i+1]]:
                return False
    return True

def is_solution(x, l):
    if len(x)==len(l):
        for i in range (0, len(x)):
            for j in range (i+1, len(x)):
                 if l[x[i]]==l[x[j]] :
                    return False
        return True
    else:
        return False
    
def output_sol(x, n, l):
    array=[]
    for i in range(n):
        array.append((l[x[i]]))
    print(array)
        
def next_elem(x, n):
    if x[len(x) - 1] == n - 1:
        return None
    return x[len(x) - 1] + 1

def back_rec(x, n, l):
    el=0
    x.append(el)
    while el is not None:
        if consistent(x, len(x), l):
            if is_solution(x, l)==1:
                output_sol(x, n, l)
            else:
                back_rec(x[:], n, l)
        el=next_elem(x, n)
        x[-1]=el

def back_it(n, l):
    x = [-1]
    while len(x) > 0:
        el = next_elem(x, n)
        while el is not None:
            x[-1] = el
            if consistent(x, len(x), l):
                if is_solution(x, l)==1:
                    output_sol(x, n, l)
                else:
                    x.append(-1)
                    break
            el = next_elem(x, n)
        if el is None: x = x[:-1]

def menu():
    print("1. Input list")
    print("2. Generate random")
    x=int(input("Please enter the coresponding number: "))
    if x==1:
        n=int(input("How many numbers should the list have? "))
        l=[]
        for i in range(n):
            n=int(input("Number: "))
            l.append(x)
    if x==2:
        n=int(input("How many numbers should the list have? "))
        l=generate_list(n)
        print(l)
    print("3. Recursive")
    print("4. Iterative")
    print("5. End")
    x=int(input("Please enter the coresponding number: "))
    while(x!=5):
        if x==3:
            back_rec([], len(l), l)
        if x==4:
            back_it(len(l), l)
        x=int(input("Please enter the coresponding number: "))

menu()