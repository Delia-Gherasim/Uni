function N = newton(x0, f0, x)
    d = divdiff(x0, f0);
    c = d(1, :);
    N = c(1) * ones(1, length(x));
    p = ones(1, length(x));
    for i = 2:length(x0)
        p = p .* (x - x0(i-1));
        N = N + c(i) * p;
    end
end

