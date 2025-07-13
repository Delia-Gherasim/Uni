#1A
x=[0,1,2];
f=1./(1+x);
t=divdiff(x,f);

#1B
df=-1./(1+x).^2;
[z,t]=divdiff2(x, f, df);

#C
xC=linspace(1,2,11);
fC=1./(1+xC);
dfC=-1./(1+xC).^2;
tC=divdiff(xC,fC);
[zC,tC]=divdiff2(xC,fC,dfC);

#2A
x=-2:4;
f=[-5,1,1,1,7,25,60];
a=divdiff(x,f);

#2B
b=fordiff(f)

#2C
c=backdiff(f)



