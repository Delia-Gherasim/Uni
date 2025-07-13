import random
import timeit

def generate_list(n):
    """
    function generates a list of n random natural numbers

    :param n: natural number
    :return: the newly generated list

    """
    x=random.randint(0, 100)
    l=[x]
    for i in range(n-1):
        x=random.randint(0, 100)
        l.append(x)
    return l

def is_sorted(l, n):
    """
    determines if a given list is sorted or not

    :param l:list
    :param n: natural number
    :return: true if it is sorted, false otherwise
    """
    for i in range(0, n-1):
        if l[i]>=l[i+1]:
            return False
    return True

def shuffle(l):
    for i in range(0, len(l)):
        r=random.randint(0, len(l)-1)
        l[i], l[r]=l[r],l[i]

def reverse_sort(l):
    n=len(l)
    for i in range(0, n):
        for j in range(i, n):
            if l[i]<l[j]:
                l[i], l[j]=l[j], l[i]
    return l

def sort1(l, step, s):
    """
    function takes a given list l and sorts it using permutation sort.
    the new sorted list is printed, as well as some intermediery steps

    :param l: list of natural numbers
    :param step: natural number showing after how many sorting steps the list is printed
    :return: new sorted list
    """
    new=l
    while is_sorted(new, len(new))==False:
        shuffle(new)
        """
        s=s+1
        if s==step:
            s=0
            print(new)
        """
    return new

def sort2(l, step, i, n, s):
    """
    function takes a given list l and sorts in using stooge sort.
    the new sorted list is printed, as well as some intermediery steps

    :param l: list of natural numbers
    :param step: natural number showing after how many sorting steps the list is printed
    :param i: index of first element
    :param n: number of elements
    :return: new sorted list
    """
    #if step==0:
     #   print(l)
    if i>=n-1:
        return 
    if (l[i]>l[n-1]):
        #step=step-1
        l[i], l[n-1]=l[n-1], l[i]
    if n-i+1>2:
        x=int((n-i+1)/3)
        sort2(l, 0, i, n-x, 0)
        sort2(l, 0, i+x, n, 0)
        sort2(l, 0, i, n-x, 0)
    return l

def best_case(o):
    if o==1:
        x=5
        t=0
        print("general times:")
        while x<=10:
            l=generate_list(x)
            nl=sort1(l, 0, 0)
            starttime=timeit.default_timer()
            sort1(nl, 0, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            print("for " , x, "elements:" ,dif)
            t=t+dif
            x=x+1
        return t/6
    else:
        x=50
        t=0
        print("general times:")
        while x<=800:
            l=generate_list(x)
            nl=sort2(l, 0, 0, x, 0)
            starttime=timeit.default_timer()
            sort2(nl, 0, 0, x, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            print("for " , x, "elements:" ,dif)
            t=t+dif
            x=x*2
        return t/6

def worst_case(o):
    if o==1:
        x=5
        t=0
        print("general times:")
        while x<=10:
            l=generate_list(x)
            starttime=timeit.default_timer()
            sort1(l, 0, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            print("for " , x, "elements:" ,dif)
            t=t+dif
            x=x+1
        return t/6
    else:
        x=50
        t=0
        print("general times:")
        while x<=800:
            l=generate_list(x)
            l=reverse_sort(l)
            starttime=timeit.default_timer()
            sort2(l, 0, 0, x, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            print("for " , x, "elements:" ,dif)
            t=t+dif
            x=x*2
        return t/6

def average(o):
    if o==1:
        x=5
        t=0
        while x<=10:
            l=generate_list(x)
            nl=sort1(l, 0, 0)
            starttime=timeit.default_timer()
            sort1(nl, 0, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            t=t+dif
            x=x+1
        m=t/6
        x=5
        t=0
        while x<=10:
            l=generate_list(x)
            starttime=timeit.default_timer()
            sort1(l, 0, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            t=t+dif
            x=x+1
        return(t/6+m)/2
    else:
        x=50
        t=0
        while x<=800:
            l=generate_list(x)
            nl=sort2(l, 0, 0, x, 0)
            starttime=timeit.default_timer()
            sort2(nl, 0, 0, x, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            t=t+dif
            x=x*2
        m=t/6
        x=50
        t=0
        while x<=800:
            l=generate_list(x)
            l=reverse_sort(l)
            starttime=timeit.default_timer()
            sort2(l, 0, 0, x, 0)
            endtime=timeit.default_timer()
            dif=endtime-starttime
            t=t+dif
            x=x*2
        return(t/6+m)/2

def print_options():
    #function prints the menu 
    
    print("Here are your options for this application: ")
    print("1. Generate a list of n random natural numbers between 0 and 100.")
    print("2. Sort the list using permutation ")
    print("3. Sort the list using stooge")
    print("4. Best case complexity")
    print("5. Worst case complexity")
    print("6. Average case complexity")
    print("0. Exit the program")
    print("What option would you like? ")

def menu():
    #function prints and executes the menu and allows the user to choose an option
    
    print_options()
    x=int(input("Please enter the coresponding number: "))
    while(x):
        if x>6:
            print("not an option")
        if x==1:
            n=int(input("How many numbers should the list have? "))
            l=generate_list(n)
            print(l)
        if x==2:
            s=int(input("After how many steps do you want to see the sorting progress? "))
            new=sort1(l, s, 0)
            print("sorted list: ")
            print(new)
        if x==3:
             s=int(input("After how many steps do you want to see the sorting progress? "))
             new=sort2(l, s, 0, len(l), 0)
             print("sorted list: ")
             print(new)
        if x==4:
            print("1. Permutation sort")
            print("2. Stooge sort")
            o=int(input("For which sorting?"))
            print(best_case(o))
        if x==5:
            print("1. Permutation sort")
            print("2. Stooge sort")
            o=int(input("For which sorting?"))
            print(worst_case(o))
        if x==6:
            print("1. Permutation sort")
            print("2. Stooge sort")
            o=int(input("For which sorting?"))
            print(average(o)/2)
        print_options()
        x=int(input("Please enter the coresponding number: "))
    if x==0:
        print("goodbye")

menu()




