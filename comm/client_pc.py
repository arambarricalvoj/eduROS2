import socket
from pynput import keyboard
import time

key_pressed = False

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(("192.168.1.140", 12345))
client_socket.setblocking(False)

def on_press(key):
    global key_pressed
    if key == keyboard.Key.up:
        print('Tecla flecha arriba presionada')
        client_socket.send('mot1.on(-25)'.encode())
        #respuesta = client_socket.recv(1024)
        #print("Respuesta: {}".format(respuesta.decode()))

def on_release(key):
    global key_pressed
    if key == keyboard.Key.up:
        print('Tecla flecha arriba liberada')
        client_socket.send('mot1.off()'.encode())
        #respuesta = client_socket.recv(1024)
        #print("Respuesta: {}".format(respuesta.decode()))

"""def connect_to_server():
    global key_pressed
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("192.168.1.140", 12345))
    while True:
        if key_pressed:
            print('¡Se ha presionado la tecla flecha arriba!')
            client_socket.send('mot1.on(-25)'.encode())
            respuesta = client_socket.recv(1024)
            print("Respuesta: {}".format(respuesta.decode()))
        else:
            print('La tecla flecha arriba no está siendo pulsada')
            client_socket.send('mot1.off()'.encode())
            respuesta = client_socket.recv(1024)
            print("Respuesta: {}".format(respuesta.decode()))
        time.sleep(0.5)
    client_socket.close()"""



# Conectarse al servidor
if __name__ == "__main__":
    # Iniciar el listener del teclado
    listener = keyboard.Listener(on_press=on_press, on_release=on_release)
    listener.start()
    #connect_to_server()
    while True:
        None
