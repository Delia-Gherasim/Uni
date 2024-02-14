import random

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

def sort1(l, step, s):
    """
    function takes a given list l and sorts it using permutation sort.
    the new sorted list is printed, as well as some intermediery steps

    :param l: list of natural numbers
    :param step: natural number showing after how many sorting steps the list is printed
    :return: new sorted list
    """
    new=l
    while is_sorted(new, len(l))==False:
        shuffle(new)
        s=s+1
        if s==step:
            s=0
            print(new)
    return new

def sort2(nl, step, i, n, s):
    """
    function takes a given list l and sorts in using stooge sort.
    the new sorted list is printed, as well as some intermediery steps

    :param nl: list of natural numbers
    :param step: natural number showing after how many sorting steps the list is printed
    :param i: index of first element
    :param n: number of elements
    :return: new sorted list
    """
    if step==s:
        print(nl)
        s=0
    if i>=n-1:
        return 
    if (nl[i]>nl[n-1]):
        nl[i], nl[n-1]=nl[n-1], nl[i]
    if n-i+1>2:
        x=int((n-i+1)/3)
        sort2(nl, step, i, n-x, s+1)
        sort2(nl, step, i+x, n, s+1)
        sort2(nl, step, i, n-x, s+1)
    return nl

def print_options():
    #function prints the menu 
    
    print("Here are your options for this application: ")
    print("1. Generate a list of n random natural numbers between 0 and 100.")
    print("2. Sort the list using permutation ")
    print("3. Sort the list using stooge")
    print("4. Exit the program")
    print("What option would you like? ")

def menu():
    #function prints and executes the menu and allows the user to choose an option
    
    print_options()
    x=int(input("Please enter the coresponding number: "))
    while(x!=4):
        if x>4 or x<1:
            print("not an option")
        if x==1:
            n=int(input("How many numbers should the list have? "))
            l=generate_list(n)
            print(l)
        if x==2:
            n=int(input("How many numbers should the list have? "))
            l=generate_list(n)
            print(l)
            s=int(input("After how many steps do you want to see the sorting progress? "))
            new=sort1(l, s, 0)
            print("sorted list: ")
            print(new)
        if x==3:
            n=int(input("How many numbers should the list have? "))
            l=generate_list(n)
            print(l)
            s=int(input("After how many steps do you want to see the sorting progress? "))
            new=sort2(l, s, 0, len(l), 0)
            print("sorted list: ")
            print(new)
        print_options()
        x=int(input("Please enter the coresponding number: "))
    if x==4:
        print("goodbye")

menu()




