# 1a
syms x
f=exp(x);
p1=taylor(f,x,0,'order',2)
p2=taylor(f,x,0,'order',3)
p3=taylor(f,x,0,'order',4)
p4=taylor(f,x,0,'order',5)
ezplot(f,[-3,3])
hold on
ezplot(p1,[-3,3])
ezplot(p2,[-3,3])
ezplot(p3,[-3,3])
ezplot(p4,[-3,3])
# 1b
vpa(exp(1), 7)
vpa(subs(p4,x,1),7)
clf

# 2a
f=sin(x)
p2=taylor(f,x,0,'order',3)
p4=taylor(f,x,0,'order',5)
ezplot(f,[-pi,pi])
ezplot(p2,[-pi,pi])
ezplot(p4,[-pi,pi])
# 2b
vpa(sin(pi/5), 6)

# 3a
f3 = log(1 + x);
p1=taylor(f3,x,0,'order',2)
p4=taylor(f3,x,0,'order',5)
ezplot(f3,[-0.9,1])
hold on
ezplot(p1,[-0.9,1])
ezplot(p4,[-0.9,1])
# 3b
vpa(log(2),6)
p7=taylor(f3,x,0,'order',7)
vpa(subs(p7,x,1),6)
# 3c
T3c = - (x + x^2 / 2 + x^3 / 3 + x^4 / 4 + x^5 / 5);
T3c
# 3d
T35 = x - (x^2 / 2) + (x^3 / 3) - (x^4 / 4) + (x^5 / 5);
T3d = T35 - T3c;
T3d
