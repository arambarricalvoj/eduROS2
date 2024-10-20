import socket

def connect_to_server():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("192.168.1.140", 12345))

    while True:
        comando = input("Introduce comando a enviar: ")
        if comando.lower() == "salir":
            break
        client_socket.send(comando.encode())
        respuesta = client_socket.recv(1024)
        print("Respuesta: {}".format(respuesta.decode()))

    client_socket.close()

if __name__ == "__main__":
    connect_to_server()
