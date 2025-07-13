function r = romberg(f, a, b, error, n_max)


# nk=2^k-1
# hk=(b-a)/nk=(b-a)/2^k-1
# r11 = (b-a)/2*(f(a)+f(b))
# rk1= 1/2[rk-1,1 +h k-1 sum(f(a+(i-0.5)*hk-1)]
