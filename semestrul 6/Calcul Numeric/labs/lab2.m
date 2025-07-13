pkg load symbolic;
syms x;

% EX 1
f = exp(x);
T1 = taylor(f, x, 'Order', 2);
T2 = taylor(f, x, 'Order', 3);
T3 = taylor(f, x, 'Order', 4);
T4 = taylor(f, x, 'Order', 5);
x_vals = linspace(-3, 3, 100);
f_vals = exp(x_vals);

T1_vals = double(vpa(subs(T1, x, x_vals)));
T2_vals = double(vpa(subs(T2, x, x_vals)));
T3_vals = double(vpa(subs(T3, x, x_vals)));
T4_vals = double(vpa(subs(T4, x, x_vals)));

 figure;
 hold on;
 plot(x_vals, f_vals, 'k');
 plot(x_vals, T1_vals, 'r');
 plot(x_vals, T2_vals, 'g');
 plot(x_vals, T3_vals, 'b');
 plot(x_vals, T4_vals, 'm');
 xlabel('x');
 ylabel('y');
 grid on;
 hold off;

% B
n = 10;
e_approx = sum(1 ./ factorial(0:n));
fprintf('e= %.6f\n', e_approx);

% EX 2
f2 = sin(x);
T3 = taylor(f2, x, 'Order', 4);
T5 = taylor(f2, x, 'Order', 6);
x_vals2 = linspace(-pi, pi, 100);
f2_vals = sin(x_vals2);

T3_vals = double(vpa(subs(T3, x, x_vals2)));
T5_vals = double(vpa(subs(T5, x, x_vals2)));

 figure;
 hold on;
 plot(x_vals2, f2_vals, 'k');
 plot(x_vals2, T3_vals, 'r');
 plot(x_vals2, T5_vals, 'b');
 xlabel('x');
 ylabel('y');
 grid on;
 hold off;

% B
approx_sin = vpa(subs(T5, x, sym(pi/5)), 5);
fprintf('Aprox sin(π/5): %.5f\n', approx_sin);

% C
x_large = 10 * pi / 3;
approx_large = vpa(subs(T5, x, x_large), 5);
actual_large = sin(x_large);
fprintf('Aprox sin(10π/3): %.5f\n', approx_large);
fprintf('Actual sin(10π/3): %.5f\n', actual_large);

% EX 3
f3 = log(1 + x);

% A
T32 = x - (x^2 / 2);
T35 = x - (x^2 / 2) + (x^3 / 3) - (x^4 / 4) + (x^5 / 5);
x_vals3 = linspace(-0.9, 1, 100);
f3_vals = log(1 + x_vals3);

T32_vals = double(vpa(subs(T32, x, x_vals3)));
T35_vals = double(vpa(subs(T35, x, x_vals3)));

 figure;
 hold on;
 plot(x_vals3, f3_vals, 'k');
 plot(x_vals3, T32_vals, 'r');
 plot(x_vals3, T35_vals, 'b');
 xlabel('x');
 ylabel('y');
 grid on;
 hold off;

% B
true_ln2 = vpa(log(2), 7);
fprintf('ln(2) %.7f\n', true_ln2);
for i = 1:100
    approx_ln2 = vpa(subs(taylor(log(x+1), x, 'Order', i+1), x, sym(1)), 7);
    if abs(approx_ln2 - true_ln2) < 1e-5
        fprintf('%d terms, ln(2) ≈ %.7f\n', i, approx_ln2);
        break;
    end
end

% C
T3c = - (x + x^2 / 2 + x^3 / 3 + x^4 / 4 + x^5 / 5);

% D
T3d = T35 - T3c;

% E
x_val = 1/3;
approx_ln2_d = vpa(subs(T3d, x, x_val), 7);
fprintf('ln(2) = %.7f\n', approx_ln2_d);

for i = 1:100
    T3d_i = subs(taylor(log((1 + x) / (1 - x)), x, 'Order', i+1), x, 1/3);
    approx_ln2_d = vpa(T3d_i, 7);
    if abs(approx_ln2_d - true_ln2) < 1e-5
        fprintf('%d terms, ln(2) = %.7f\n', i, approx_ln2_d);
        break;
    end
end

