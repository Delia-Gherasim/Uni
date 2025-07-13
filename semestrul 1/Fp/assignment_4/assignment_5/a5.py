import random

def generate_list(n):
    x=random.randint(0, 100)
    l=[x]
    for i in range(n-1):
        x=random.randint(0, 100)
        l.append(x)
    return l

dp = [[]]

def printsubset(arr, i, sum, p):
	if (i == 0 and sum != 0 and dp[0][sum]):
		p.append(arr[i])
		print(p)
		p = []
		return
	if (i == 0 and sum == 0):
		print(p)
		p = []
		return
	if (dp[i-1][sum]):
		b = []
		b.extend(p)
		printsubset(arr, i-1, sum, b)
	if (sum >= arr[i] and dp[i-1][sum-arr[i]]):
		p.append(arr[i])
		printsubset(arr, i-1, sum-arr[i], p)

def dynamic(l, n, k):
	if (n == 0 or k < 0):
		return

	global dp
	dp = [[False for i in range(k+1)] for j in range(n)]

	for i in range(n):
		dp[i][0] = True
	if (l[0] <= k):
		dp[0][l[0]] = True
	for i in range(1, n):
		for j in range(0, k + 1):
			if (l[i] <= j):
				dp[i][j] = (dp[i-1][j] or dp[i-1][j-l[i]])
			else:
				dp[i][j] = dp[i - 1][j]

	if (dp[n-1][k] == False):
		print("There are no subsets with sum ", k)
		return
	p = []
	printsubset(l, n-1, k, p)

def consistent(x, l, k):
    s=0
    for i in range (0, len(x)):
        s=s+l[x[i]]
    if s>k:
        return False
    return True

def is_solution(x, l, k):
    s=0
    for i in range (0, len(x)):
        s=s+l[x[i]]
    if s==k:
        for i in range(0, len(x)-1):
            for j in range (i+1, len(x)):
                if l[x[i]]==l[x[j]]:
                    return False
    else:
        return False
    return True
    
def output_sol(x, n, l):
    array=[]
    for i in range(n):
        array.append((l[x[i]]))
    print(array)
        
def next_elem(x, n):
    if x[len(x) - 1] == n - 1:
        return None
    return x[len(x) - 1] + 1

def back_rec(x, n, l, k):
    el=0
    x.append(el)
    found=0
    while el is not None and found==0:
        if consistent(x, l, k):
            if is_solution(x, l, k)==1:
                output_sol(x, len(x), l)
                found=1
            else:
                back_rec(x[:], n, l, k)
        el=next_elem(x, n)
        x[-1]=el

def menu():
    print("1. Input list")
    print("2. Generate random")
    x=int(input("Please enter the coresponding number: "))
    if x==1:
        n=int(input("How many numbers should the list have? "))
        l=[]
        for i in range(n):
            x=int(input("Number: "))
            l.append(x)
    if x==2:
        n=int(input("How many numbers should the list have? "))
        l=generate_list(n)
        print(l)
    print("3. normal")
    print("4. dynamic")
    print("5. End")
    x=int(input("Please enter the coresponding number: "))
    while(x!=5):
        if x==3:
            k=int(input("Sum of subset "))
            back_rec([], len(l), l, k)
        if x==4:
            k=int(input("Sum of subset "))
            dynamic(l, len(l), k)
        x=int(input("Please enter the coresponding number: "))

menu()