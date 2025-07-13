function L = barycentrical_Louis(x0, f0, x)
  L = zeros(size(x));
  l = zeros(size(x0));
  w = ones(1, length(x0));
  for j = 1:length(x0)
        w(j) = 1 / prod(x0(j) - x0([1:j-1, j+1:length(x0)]));
   end
  for i = 1 : length(x)
    for j = 1: length(x0)
      #l(j) = prod( w(j)  ./ ( x0(j) - x0([1:j-1, j+1:length(x0)])));
      l(j) = w(j) / prod(x(i) - x0([1:j-1, j+1:end]));
    endfor
    L(i) = sum(l .* f0);
  endfor
end

