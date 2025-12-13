% Código MATLAB para graficar una única señal desde CSV
close all; clear all; clc;

% Leer el CSV
data = readmatrix('registro1.csv'); 

% Extraer la columna (ejemplo: columna 3)
raw_signal = data(:,3);

% Calcular el error real restando offset=1
offset = 1;
signal = raw_signal - offset;

% Índices incrementales
n = (1:numel(signal))';

% Graficar
figure;
plot(n, signal, 'r', 'LineWidth', 1.5); hold on;
yline(0, '--k', 'LineWidth', 1.2);

% Ajustar límites verticales simétricos
maxAbs = max(abs(signal));
ylim([-maxAbs maxAbs]);

% Ajustar límites horizontales: recortar 20 muestras por cada lado
xlim([20 numel(signal)-20]);

hold off;

xlabel('Tiempo');
ylabel('Error real (yaw - offset)');
title('Sin controlador (offset = 1)');
grid on;
