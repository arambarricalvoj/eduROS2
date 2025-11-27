#!/usr/bin/env python3
import time
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_D, SpeedPercent

# Inicializar motores
motIzq = LargeMotor(OUTPUT_A)
motDer = LargeMotor(OUTPUT_D)

# Arrancar ambos motores al 30% de velocidad
motIzq.on(SpeedPercent(100))
motDer.on(SpeedPercent(100))

# Abrir fichero para escritura
with open("diferencias_velocidades.txt", "w") as f:
    f.write("timestamp,vel_izq,vel_der,diferencia\n")

    inicio = time.time()
    while time.time() - inicio < 4.0:  # durante 10 segundos
        # Leer velocidades reales (en deg/s)
        v_izq = motIzq.speed
        v_der = motDer.speed

        # Calcular diferencia
        e_v = abs(v_izq) - abs(v_der)

        # Timestamp relativo
        ts = time.time() - inicio

        # Guardar en fichero
        f.write("{:.3f},{},{},{}\n".format(ts, v_izq, v_der, e_v))

        # Pequeña pausa para no saturar
        time.sleep(0.05)

# Detener motores al acabar
motIzq.off()
motDer.off()

print("Medición completada. Datos guardados en diferencias_velocidades.txt")
