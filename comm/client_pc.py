import socket
from pynput import keyboard
import time

key_pressed = False

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(("192.168.1.140", 12345))
client_socket.setblocking(False) #Mandar paquete sin esperar respuesta

def on_press(key):
    global key_pressed
    if key == keyboard.Key.up:
        print('Tecla flecha arriba presionada')
        client_socket.send('tank_drive.on(SpeedPercent(25*(-1)),SpeedPercent(25*(-1)))'.encode())
        #respuesta = client_socket.recv(1024)
        #print("Respuesta: {}".format(respuesta.decode()))
    
    elif key == keyboard.Key.down:
        print('Tecla flecha abajo presionada')
        client_socket.send('tank_drive.on(SpeedPercent(25*(1)),SpeedPercent(25*(1)))'.encode())

    elif key == keyboard.Key.left:
        print('Tecla flecha izquierda presionada')
        client_socket.send('tank_drive.on(SpeedPercent(25*(1)),SpeedPercent(25*(-1)))'.encode())

    elif key == keyboard.Key.right:
        print('Tecla flecha derecha presionada')
        client_socket.send('tank_drive.on(SpeedPercent(25*(-1)),SpeedPercent(25*(1)))'.encode())

def on_release(key):
    global key_pressed
    if key == keyboard.Key.up or key == keyboard.Key.down or key == keyboard.Key.left or key == keyboard.Key.right:
        print('Tecla flecha liberada')
        client_socket.send('tank_drive.off()'.encode())
        time.sleep(0.01)
        #respuesta = client_socket.recv(1024)
        #print("Respuesta: {}".format(respuesta.decode()))

# Conectarse al servidor
if __name__ == "__main__":
    # Iniciar el listener del teclado
    listener = keyboard.Listener(on_press=on_press, on_release=on_release)
    listener.start()
    
    while True:
        None
