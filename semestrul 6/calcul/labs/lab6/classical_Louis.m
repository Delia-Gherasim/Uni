function L = classical_Louis(x0, f0, x)
  L = zeros(size(x));
  l = zeros(size(x0));
  #size returns 2 nr, lenght just 1
  #prod(1-[2:4, 6:10])
  for i = 1 : length(x)
    for j = 1: length(x0)
      l(j) = prod( x(i)-x0([1:j-1, j+1:length(x0)])  ./ ( x0(j) - x0([1:j-1, j+1:length(x0)])));
    endfor
     L(i) = sum(l .* f0);
  endfor
end

