#!/usr/bin/env python3
import json
import os
import socket
import threading
import time
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, MoveTank, SpeedPercent
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import UltrasonicSensor, GyroSensor, ColorSensor

# ---------- JSON kargatu --------------------------------
with open("config_ev3.json", "r") as f:
    config = json.load(f)

# ---------- HARDWARE hasiarazi --------------------------------
motor_map = {
    "OUTPUT_A": OUTPUT_A,
    "OUTPUT_B": OUTPUT_B,
    "OUTPUT_C": OUTPUT_C,
    "OUTPUT_D": OUTPUT_D
}

sensor_map = {
    "INPUT_1": INPUT_1,
    "INPUT_2": INPUT_2,
    "INPUT_3": INPUT_3,
    "INPUT_4": INPUT_4
}

# Inicializar motores si están definidos
if config.get("OUTPUT_A"):
    motIzq = LargeMotor(motor_map["OUTPUT_A"])
if config.get("OUTPUT_D"):
    motDer = LargeMotor(motor_map["OUTPUT_D"])

# Inicializar sensores si están definidos
if config.get("INPUT_2") == "US":
    ultrasonic = UltrasonicSensor(sensor_map["INPUT_2"])
if config.get("INPUT_3") == "GS":
    gyro = GyroSensor(sensor_map["INPUT_3"])
    gyro.reset()



# ---------- Puertos EV3 --------------------------------
tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
motIzq = LargeMotor(OUTPUT_A)
motDer = LargeMotor(OUTPUT_D)

ultrasonic = UltrasonicSensor(INPUT_2)
gyro = GyroSensor(INPUT_3)
gyro.reset()

# ---------- Dirección IP --------------------------------
ip = os.popen("hostname -I").read().strip()
ip = ip.split()[0] if ip else None

# ---------- Control movimientos: servidor TCP ----------
def motores_movimiento_servidor_tcp():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("0.0.0.0", 12345))
    server_socket.listen(5)
    print("Control movimientos: servidor TCP escuchando en el puerto 12345")

    while True:
        client_socket, addr = server_socket.accept()
        print("Conexión TCP establecida con {}".format(addr))
        buffer = ""
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            buffer += data.decode()

            # Procesar todas las líneas completas que haya en el buffer
            while "\n" in buffer:
                comando, buffer = buffer.split("\n", 1)
                comando = comando.strip()
                if comando:
                    print("Recibido:", comando)
                    try:
                        exec(comando)
                    except Exception as e:
                        print("Error ejecutando comando:", e)

        client_socket.close()
        print("Conexión con {} cerrada".format(addr))


# ---------- Control movimientos: receptor UDP ----------
def motores_movimiento_receptor_udp():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.bind(("0.0.0.0", 5003))
    print("Receptor UDP activo en puerto 5003")

    udp_socket.setblocking(False)  # No bloquear si no hay datos

    while True:
        try:
            # Leer todos los datagramas disponibles en el buffer del OS, pero solo ejecutar el último
            ultimo_comando = None
            while True:
                try:
                    data, addr = udp_socket.recvfrom(1024) # El socket UDP actúa como una FIFO (First-In, First-Out): cada llamada a recvfrom() te da el siguiente datagrama en cola.
                    ultimo_comando = data.decode(errors='ignore').strip()
                except BlockingIOError:
                    break  # No hay más datos en cola

            if ultimo_comando:
                try:
                    exec(ultimo_comando)
                except Exception as e:
                    print("Error ejecutando comando:", e)

        except Exception as e:
            print("Error al recibir datos UDP:", e)


# ---------- Publicación encoders: emisor UDP ----------
def encoders_emisor_udp():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    destino = ("192.168.1.138", 5000)  # Cambia IP y puerto
    print("Encoders: emisor UDP en el puerto 5000")
    while True:
        # Aquí iría la lectura real de encoders:
        encoder_a = motIzq.position
        encoder_d = motDer.position
        mensaje = "{},{}".format(encoder_a, encoder_d) #"test"  # Sustituye por f"{encoder_a},{encoder_d}" cuando lo implementes
        udp_socket.sendto(mensaje.encode(), destino)
        #print("Enviado por UDP: {}".format(mensaje))
        time.sleep(0.02)

# ---------- Publicación ultrasonidos: emisor UDP ----------
def ultrasonidos_emisor_udp():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    destino = ("192.168.1.138", 5001)  # Cambia IP y puerto
    print("Sensor de ultrasonidos: emisor UDP en el puerto 5001")
    while True:
        mensaje = str(ultrasonic.distance_centimeters)
        udp_socket.sendto(mensaje.encode(), destino)
        time.sleep(0.1)

# ---------- Publicación sensor de giro: emisor UDP ----------
def giro_emisor_udp():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    destino = ("192.168.1.138", 5002)  # Cambia IP y puerto
    print("Sensor de giro: emisor UDP en el puerto 5002")
    while True:
        mensaje = str(gyro.angle)
        udp_socket.sendto(mensaje.encode(), destino)
        time.sleep(0.05)

if __name__ == "__main__":
    print("Lego Mindstorms EV3 - IP direction: {}".format(ip))
    print("Connect to IP: 192.168.1.138\n")
    
    hilo_ultrasonicos_udp = threading.Thread(target=ultrasonidos_emisor_udp, daemon=True)
    hilo_ultrasonicos_udp.start()

    hilo_giro_udp = threading.Thread(target=giro_emisor_udp, daemon=True)
    hilo_giro_udp.start()
    
    hilo_encoders_udp = threading.Thread(target=encoders_emisor_udp, daemon=True)
    hilo_encoders_udp.start()

    hilo_motores_movimientos_tcp = threading.Thread(target=motores_movimiento_servidor_tcp, daemon=True)
    hilo_motores_movimientos_tcp.start()

    hilo_motores_movimientos_udp = threading.Thread(target=motores_movimiento_receptor_udp, daemon=True)
    hilo_motores_movimientos_udp.start()

    # Mantener el programa vivo
    hilo_motores_movimientos_tcp.join()
