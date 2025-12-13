% Código MATLAB para graficar tres señales de error desde CSV
% Cada CSV debe tener columnas: timestamp, offset, yaw, error (aunque ignoramos la columna error)

% Leer los tres CSV 
data1 = readmatrix('registro_kp_5.31_gen.csv'); 
data2 = readmatrix('registro_nbs_factor_2.5.csv'); 

% Extraer columnas relevantes
offset1 = data1(:,2); yaw1 = data1(:,3);
offset2 = data2(2,6); yaw2 = data2(:,6);

% Calcular error como yaw - offset
err1 = yaw1 - offset1;
err2 = yaw2 - offset2;

% Crear vectores de índice (1,2,3,...)
n1 = 1:length(err1);
n2 = 1:length(err2);

% Graficar las tres señales en el mismo eje
figure;
plot(n1, err1, 'g', 'LineWidth', 1.5); hold on;
plot(n2, err2, 'b', 'LineWidth', 1.5);
hold off;

xlabel('Índice temporal');
ylabel('Error (yaw - offset)');
title('Comparativa error: proporcional tradicional VS borroso');
legend('Kp = 5.31','Borroso con ganancia = 2.5');
grid on;
