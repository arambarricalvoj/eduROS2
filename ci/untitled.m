% Funciones de pertenencia triangulares (con hombros correctos) para e_v y Delta_v
clear; clc; close all;

tri = @(x,a,b,c) tri_shoulder(x,a,b,c);

%% Entrada e_v [-100, 100]
x = -100:1:100;

ev_muy_bajo = tri(x, -100, -80, -40);  % (-100,-80,-40)
ev_bajo     = tri(x,  -60, -30,   0);  % (-60,-30,0)
ev_medio    = tri(x,  -20,   0,  20);  % (-20,0,20)
ev_alto     = tri(x,    0,  30,  60);  % (0,30,60)
ev_muy_alto = tri(x,   40,  80, 100);  % (40,80,100)

figure;
plot(x, ev_muy_bajo, 'b', 'LineWidth', 2); hold on;
plot(x, ev_bajo,     'c', 'LineWidth', 2);
plot(x, ev_medio,    'g', 'LineWidth', 2);
plot(x, ev_alto,     'm', 'LineWidth', 2);
plot(x, ev_muy_alto, 'r', 'LineWidth', 2);
xlabel('Error de velocidad e_v'); ylabel('Grado de pertenencia');
title('Funciones de pertenencia - Entrada e_v');
legend('muy\_bajo','bajo','medio','alto','muy\_alto','Location','NorthWest');
grid on;

%% Salida Delta_v [-100, 100]
y = -100:1:100;

dv_neg_fuerte = tri(y, -100, -100,  -50); % hombro izquierdo: pico en -100, decae hasta -50
dv_neg_suave  = tri(y,  -60,  -30,    0);
dv_nulo       = tri(y,  -20,    0,   20);
dv_pos_suave  = tri(y,    0,   30,   60);
dv_pos_fuerte = tri(y,   50,  100,  100); % hombro derecho: pico en 100, decae desde 50

figure;
plot(y, dv_neg_fuerte, 'b', 'LineWidth', 2); hold on;
plot(y, dv_neg_suave,  'c', 'LineWidth', 2);
plot(y, dv_nulo,       'g', 'LineWidth', 2);
plot(y, dv_pos_suave,  'm', 'LineWidth', 2);
plot(y, dv_pos_fuerte, 'r', 'LineWidth', 2);
xlabel('Corrección \Delta v (%)'); ylabel('Grado de pertenencia');
title('Funciones de pertenencia - Salida \Delta v');
legend('negativo\_fuerte','negativo\_suave','nulo','positivo\_suave','positivo\_fuerte','Location','NorthWest');
grid on;

%% Función auxiliar: triángulo con soporte de hombros (a=b, b=c)
function mu = tri_shoulder(x,a,b,c)
    % Vectorizada, maneja correctamente triángulos estándar y hombros
    mu = zeros(size(x));
    % Pico exactamente en b
    mu(abs(x - b) < eps) = 1;

    leftMask  = (x > a) & (x < b) & (b > a);
    rightMask = (x > b) & (x < c) & (c > b);

    mu(leftMask)  = (x(leftMask) - a) ./ (b - a);
    mu(rightMask) = (c - x(rightMask)) ./ (c - b);

    % Hombro izquierdo (a==b): mu = 1 en b y decae linealmente hasta c
    if abs(a - b) < eps && (c > b)
        shoulderMask = (x > b) & (x < c);
        mu(shoulderMask) = (c - x(shoulderMask)) ./ (c - b);
    end

    % Hombro derecho (b==c): mu = 1 en b y crece linealmente desde a hasta b
    if abs(b - c) < eps && (b > a)
        shoulderMask = (x > a) & (x < b);
        mu(shoulderMask) = (x(shoulderMask) - a) ./ (b - a);
    end

    % Clamp numérico
    mu(mu < 0) = 0; mu(mu > 1) = 1;
end
