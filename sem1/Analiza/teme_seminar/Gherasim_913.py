import numpy as np
import math
from scipy.integrate import trapz

a = 0
b = np.math.inf
n = 11
h = (b - a) / (n - 1)
x = np.linspace(a, b, n)
function = pow(math.e, -(x*x))
f = np.function

I_trapz = trapz(f,x)
I_trap = (h/2)*(f[0] + 2 * sum(f[1:n-1]) + f[n-1])

print(I_trapz)
print(I_trap)

