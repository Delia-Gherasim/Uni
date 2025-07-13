f = @(x) 1./x;
a=1;
b=2;
n=100;
res = rectangle_rule(f, a, b,n )

#ex 3


#ex 4
function I = adaptive_simpson(f, a, b, tol)
    % Simpson's rule approximation
    function S = simpson(f, a, b)
        c = (a + b) / 2;
        S = (b - a) / 6 * (f(a) + 4*f(c) + f(b));
    end
    function S = recursive_asr(f, a, b, eps, whole)
        c = (a + b)/2;
        left = simpson(f, a, c);
        right = simpson(f, c, b);
        if abs(left + right - whole) < 15 * eps
            S = left + right + (left + right - whole)/15;
        else
            S = recursive_asr(f, a, c, eps/2, left) + ...
                recursive_asr(f, c, b, eps/2, right);
        end
    end

    whole = simpson(f, a, b);
    I = recursive_asr(f, a, b, tol, whole);
end

