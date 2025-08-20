#!/usr/bin/env python3
import socket
import threading
import time
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_D, MoveTank

tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
mot1 = LargeMotor(OUTPUT_A)
mot2 = LargeMotor(OUTPUT_D)

# ---------- Servidor TCP ----------
def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("0.0.0.0", 12345))
    server_socket.listen(5)
    print("Servidor escuchando en el puerto 12345")

    while True:
        client_socket, addr = server_socket.accept()
        print("Conexión establecida con {}".format(addr))
        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            comando = data.decode()
            print("Recibido: {}".format(comando))
            try:
                exec(comando)
            except Exception as e:
                print("Error ejecutando comando: {}".format(e))

        client_socket.close()
        print("Conexión con {} cerrada".format(addr))

# ---------- Hilo UDP ----------
def udp_sender():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    destino = ("192.168.1.138", 54321)  # Cambia IP y puerto
    while True:
        # Aquí iría la lectura real de encoders:
        # encoder_a = mot1.position
        # encoder_d = mot2.position
        mensaje = "test"  # Sustituye por f"{encoder_a},{encoder_d}" cuando lo implementes
        udp_socket.sendto(mensaje.encode(), destino)
        print("Enviado por UDP: {}".format(mensaje))
        time.sleep(1)

"""# ---------- Hilo TCP (envío) ----------
def tcp_sender():
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    destino = ("192.168.1.138", 54321)  # Cambia IP y puerto
    try:
        tcp_socket.connect(destino)
        print("Conectado a {}:{}".format(destino[0], destino[1]))
        while True:
            # Aquí iría la lectura real de encoders:
            # encoder_a = mot1.position
            # encoder_d = mot2.position
            mensaje = "test"  # Sustituye por f"{encoder_a},{encoder_d}" cuando lo implementes
            tcp_socket.sendall(mensaje.encode())
            print("Enviado por TCP: {}".format(mensaje))
            time.sleep(1)
    except Exception as e:
        print("Error en conexión TCP: {}".format(e))
    finally:
        tcp_socket.close()"""


"""if __name__ == "__main__":
    # Lanzamos hilo UDP
    hilo_udp = threading.Thread(target=udp_sender, daemon=True)
    hilo_udp.start()

    # Lanzamos servidor TCP (bloqueante)
    start_server()"""

if __name__ == "__main__":
    hilo_udp = threading.Thread(target=udp_sender, daemon=True)
    hilo_udp.start()

    hilo_tcp = threading.Thread(target=start_server, daemon=True)
    hilo_tcp.start()

    # Mantener el programa vivo
    hilo_tcp.join()

