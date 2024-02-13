from random import randint
import matplotlib.pyplot as plt

def compute_p(p, n, x):
    s = 0
    for i in range(n):
        s = s + pow(x[i], p)
    return pow(s, 1/p)

def unit_ball():
    values = [1.25, 1.5, 3, 8]
    x = []
    n = randint(1,2000)
    for i in range(n):
        x.append(randint(1,2000))

    p_norms = []
    for i in range(len(values)):
        p_norms.append(compute_p(values[i], n, x))

    l = int(len(p_norms) / 2)


    p_norms_1= p_norms[:l]
    p_norms_2 = p_norms[l:]

    plt.scatter(p_norms_1, p_norms_2 , c = "blue")
    plt.show()

unit_ball()