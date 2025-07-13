function f=ex5(n)
  if n==0
    f=1+1;
  else
    f=1+1/ex5(n-1);
  endif
end
