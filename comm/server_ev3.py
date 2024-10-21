#!/usr/bin/env python3
# An EV3 Python (library v2) solution to Exercise 3
# of the official Lego Robot Educator lessons that
# are part of the EV3 education software


import socket
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, SpeedPercent, MoveTank, MotorSet
#from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
#from ev3dev2.sensor.lego import TouchSensor, UltrasonicSensor, GyroSensor, ColorSensor
#from ev3dev2.led import Leds

tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
#ultrasonic = UltrasonicSensor(INPUT_2)
#gyro = GyroSensor(INPUT_3)
#csIZQ = ColorSensor(INPUT_1)
#csDER = ColorSensor(INPUT_4)
mot1 = LargeMotor(OUTPUT_A)
#mot2 = LargeMotor(OUTPUT_D)

"""def sinCalibrate(lightLine, pwEmbestir): 
    while csIZQ.reflected_light_intensity>lightLine and csDER.reflected_light_intensity>lightLine:
        tank_drive.on(SpeedPercent(pwEmbestir*(-1)),SpeedPercent(pwEmbestir*(-1)))
    
    tank_drive.off()
    #time.sleep(0.3)
    tank_drive.on_for_degrees(SpeedPercent(35),SpeedPercent(35),135)
    gyro.reset()

def conCalibrate(lightLine, pwEmbestir): 
    while csIZQ.reflected_light_intensity>lightLine and csDER.reflected_light_intensity>lightLine:
        tank_drive.on(SpeedPercent(pwEmbestir*(-1)),SpeedPercent(pwEmbestir*(-1)))
    
    tank_drive.off()
    time.sleep(0.3)

    if csIZQ.reflected_light_intensity<=lightLine:
        tank_drive.on_for_degrees(SpeedPercent(35),SpeedPercent(35),45)
        #arrancar derecho hasta línea
        while csDER.reflected_light_intensity>lightLine:
            mot1.off()
            mot2.on(-25)
        mot2.off()
    else:
        tank_drive.on_for_degrees(SpeedPercent(35),SpeedPercent(35),45)
        #arrancar izquierdo hasta línea
        while csIZQ.reflected_light_intensity>lightLine:
            mot2.off()
            mot1.on(-25)
        mot1.off()

    tank_drive.on_for_degrees(SpeedPercent(35),SpeedPercent(35),45)
    gyro.reset()"""

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
                #exec(mot1.on(-25))
            except Exception as e:
                print("Error ejecutando comando: {}".format(e))
            #respuesta = input("Introduce respuesta para enviar: ")
            #client_socket.send(respuesta.encode())
            #client_socket.send("Finished".encode())

        client_socket.close()
        print("Conexión con {} cerrada".format(addr))

if __name__ == "__main__":
    start_server()
