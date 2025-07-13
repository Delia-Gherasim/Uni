%nu uita sa scrii pkg load statistics
%help [comanda]
%clc ii clear si clear sterge numa variabile

                          %lab1 ex1
A=[1 0 -2; 2 1 3; 0 1 0]; % ; separa liniile
                         % also ; la final de linie supress output
B=[2 1 1; 1 0 -1; 1 1 0];
printf('C=A-B \n');
C=A-B;
printf('D=A*B \n');
D=A*B;    %matrix multiplication
printf('E=[eij], where eij = aij · bij \n')
E=A.*B;   %element wise multiplication,
           %works onlyy if the 2 matrices have the same dimensions

A(1:2, 2:3); %1:2 -> rows  2:3-> comlumns
             %deci o sa fie [0 -2; 1 3]
A(1,1); %scoate elementul de pe poz 1,1
x=1:2:10;  %ii gen ca un fel de mini for de la 1 la 10 cu step 2,
          % x=1 3 5 7 9
x+2;    % aduna 2 la fiecare elem al vectorului => 3 5 7 9 11
3*x;     %inmultuste fiecare elem cu 3
x.^2;   %. pointwise operation



                                %lab1 ex2
%For x ∈ [0, 3], graph on the same set of axes the functions x^5/10, x sin x and cos x,
%in different colors and linestyles. Display a title and a legend on your graph.

x_values = linspace(0, 3, 100); % Define the range of x values
                                % y = linspace(start, stop, n)
                                % n=number of points you want to generate between start and stop
% Calculate the corresponding y values for each function
y1 = (x_values.^5) / 10;
y2 = x_values .* sin(x_values);
y3 = cos(x_values);
% Plot all functions on the same set of axes
figure;
hold on;

plot(x_values, y1, 'r-', 'LineWidth', 2, 'DisplayName', 'x^5/10'); % r- red solid line
plot(x_values, y2, 'g--', 'LineWidth', 2, 'DisplayName', 'x*sin(x)'); %g-- green dashed line
plot(x_values, y3, 'b-.', 'LineWidth', 2, 'DisplayName', 'cos(x)'); %b-. blue dash-dot line
              %'DisplayName' used when creating a legend for the plot.
title('Graphs of Functions');
legend('show');
hold off;

% Plot each function on a separate figure in the same window
figure;
subplot(3, 1, 1);   %subplot(m, n, p)
                    % m: Number of rows in the subplot grid.
                    % n: Number of columns in the subplot grid.
                    % p: Position of the subplot in the grid (starts from the top-left and goes column-wise).
plot(x_values, y1, 'r-', 'LineWidth', 2);
title('Graph of x^5/10');

subplot(3, 1, 2);
plot(x_values, y2, 'g--', 'LineWidth', 2);
title('Graph of x*sin(x)');
subplot(3, 1, 3);
plot(x_values, y3, 'b-.', 'LineWidth', 2);
title('Graph of cos(x)');

                        %alte matrici:
zeros(3, 4); % matrix of size n-by-m filled with zeros
ones(n, m);  % matrix of size n-by-m filled with ones.
eye(n);      %identity matrix of size n-by-n



