function I = simpsons_rule(f, a, b, n)
    h = (b - a) / n;
    x = a + (1:n-1) * h;
    odd_x = x(1:2:end);
    even_x = x(2:2:end);
    I = h/3 * (f(a) + 4 * sum(f(odd_x)) + 2 * sum(f(even_x)) + f(b));
end

