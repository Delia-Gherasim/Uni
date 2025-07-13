
def opt1():
    n=float(input("read n>0:  "))
    print("let f:R->R, f(x)=x^2+x")
    print("f'(x)=2x+1")
    print("global min of f: (-0.5, -0.25)")
    x=[]
    el=float(input("first element of iteration:  "))
    x.append(el)
    for i in range (1, 101):
        a=x[i-1]-n*(2*x[i-1]+1)
        x.append(a)
    print(x)

def opt2():
    print("let f:R->R, f(x)=-x^2")
    print("f'(x)=-2x")
    print("global max of f: (0, 0)")
    x=[]
    n=float(input("read n>0:  "))
    el=float(input("first element of iteration:  "))
    x.append(el)
    for i in range (1, 101):
        a=x[i-1]-n*(2*x[i-1]+1)
        x.append(a)
    print(x)

def menu():
    print("1) Take f to be a convex function and show numerically that for small η the iteration converges to the global minimum of f.  ")
    print("2) Show that by increasingηthe algorithm can converge faster. ")
    print("3) However,taking η too large might lead to divergence.  ")
    print("4) Take f to be nonconvex and show that thealgorithm can get stuck in a local minimum.")
    print("5) end")
    x=int(input("option"))
    while (x!=5):
        if x==1:
            print("for a small n: ")
            opt1()
        if x==2:
            print("for a bigger n: ")
            opt1()
        if x==3:
            print("n too large: ")
            opt1()
        if x==4:
            opt2()
        x=int(input("option"))

menu()

