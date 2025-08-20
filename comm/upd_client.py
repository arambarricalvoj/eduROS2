#!/usr/bin/env python3
import socket

# Configuración
IP_LOCAL = "0.0.0.0"   # Escucha en todas las interfaces
PUERTO = 54321         # Cambia al que quieras

# Crear socket UDP
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((IP_LOCAL, PUERTO))

print(f"Escuchando UDP en {IP_LOCAL}:{PUERTO}... (Ctrl+C para salir)")

try:
    while True:
        data, addr = sock.recvfrom(4096)  # Espera hasta recibir paquete
        mensaje = data.decode(errors='ignore')
        print(f"Recibido desde {addr}: {mensaje.strip()}")
except KeyboardInterrupt:
    print("\nCerrando servidor UDP")
finally:
    sock.close()
