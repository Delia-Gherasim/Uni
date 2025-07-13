function I = trapezoidal_rule(f, a, b, n)
    h = (b - a) / n;
    x = a + (1:n-1) * h;
    I = h/2 * (f(a) + 2 * sum(f(x)) + f(b));
end

