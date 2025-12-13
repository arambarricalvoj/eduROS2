% Código MATLAB para graficar una única señal desde CSV
% El CSV debe tener varias columnas; aquí usamos la columna 8
close all; clear all; clc;

% Leer el CSV
data = readmatrix('registro_nn.csv'); 

% Extraer directamente la columna 8 (por ejemplo error_traj u otra variable)
signal = data(:,8);

% Índices incrementales (1..N)
n = (1:numel(signal))';

% Graficar la señal
figure;
plot(n, signal, 'r', 'LineWidth', 1.5);

xlabel('Tiempo');
ylabel('Error');
title('Controlador neuronal - Señal de error');
grid on;
