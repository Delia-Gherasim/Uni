function x=gauss_point(A, b)
  [r,n]=size(A);
  x=zeros(n,1);
  A=[A, b];
  for j=1:n-1
    [v,p]=max(abs(A(j:n, j)));
    p=p+j-1;
    A([p,j], :)=A([j,p],:);
    for i=j+1:n
      c=A(i,j)/A(j,j);
      A(i,:)=A(i,:)-c*A(j, :);
    endfor
  endfor
  x=bckw(A(:,1:n),A(:,n+1));

