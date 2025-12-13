% Código MATLAB para graficar tres señales de error desde CSV
% Cada CSV debe tener columnas: timestamp, offset, yaw, error_traj
close all; clear all; clc;

% Leer los tres CSV
data1 = readmatrix('registro_nag_factor_1.000000.csv'); 
data2 = readmatrix('registro_npg_factor_0.400000.csv'); 
data3 = readmatrix('registro_nbs_factor_2.500000.csv'); 

% Extraer directamente la columna error_traj (columna 4)
err1 = data1(:,4);
err2 = data2(:,4);
err3 = data3(:,4);

% Índices incrementales (1..N)
n1 = (1:numel(err1))';
n2 = (1:numel(err2))';
n3 = (1:numel(err3))';

% Graficar las tres señales en el mismo eje
figure;
plot(n1, err1, 'r', 'LineWidth', 1.5); hold on;
plot(n2, err2, 'g', 'LineWidth', 1.5);
plot(n3, err3, 'b', 'LineWidth', 1.5);
hold off;

xlabel('Instantes temporales');
ylabel('Error trayectoria');
title('Controlador fuzzy - Comparativa señales de error');
legend('Geom. Velocidad, ganancia = 1.0','Geom. Posición, ganancia = 0.4','Sensor de giro, ganancia = 2.5', 'Location', 'best');
grid on;
