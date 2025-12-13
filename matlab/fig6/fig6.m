% Código MATLAB para graficar tres señales de error desde CSV
% Cada CSV debe tener columnas: timestamp, offset, yaw, error (aunque ignoramos la columna error)

% Leer los tres CSV
data1 = readmatrix('registro_kp_2_gen.csv'); 
data2 = readmatrix('registro_kp_5.31_gen.csv'); 
data3 = readmatrix('registro_kp_9.0_gen.csv'); 

% Extraer columnas relevantes
offset1 = data1(:,2); yaw1 = data1(:,3);
offset2 = data2(:,2); yaw2 = data2(:,3);
offset3 = data3(:,2); yaw3 = data3(:,3);

% Calcular error como yaw - offset
err1 = yaw1 - offset1;
err2 = yaw2 - offset2;
err3 = yaw3 - offset3;

% Crear vectores de índice (1,2,3,...)
n1 = 1:length(err1);
n2 = 1:length(err2);
n3 = 1:length(err3);

% Graficar las tres señales en el mismo eje
figure;
plot(n1, err1, 'r', 'LineWidth', 1.5); hold on;
plot(n2, err2, 'g', 'LineWidth', 1.5);
plot(n3, err3, 'b', 'LineWidth', 1.5);
hold off;

xlabel('Muestra');
ylabel('Error (yaw - offset)');
title('Optimización por GA - Comparativa señales error');
legend('Kp = 2.0','Kp = 5.31','Kp = 9.0');
grid on;
