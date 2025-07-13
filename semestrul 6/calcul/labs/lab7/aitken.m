function A = aitken(x0,f0,x)
    P = zeros(length(x0));
    P(:,1) = f0';
    n = length(x0);
    for i = 2:n
        for j = 2:i
            matrix = [x - x0(i-j+1), P(i-1,j-1) ; x - x0(i), P(i,j-1)];
            P(i,j) = 1/(x0(i) - x0(i-j + 1)) * det(matrix);
        endfor
    endfor
    A = P(length(x0), length(x0));
end
