import socket
import time
import threading
import json
from ev3dev2.motor import LargeMotor, MediumMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, MoveTank, SpeedPercent
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import UltrasonicSensor, GyroSensor, ColorSensor, TouchSensor

# Cargar configuración
with open("config_ev3.json", "r") as f:
    config = json.load(f)

# Mapas de puertos
motor_port_map = {
    "OUTPUT_A": OUTPUT_A,
    "OUTPUT_B": OUTPUT_B,
    "OUTPUT_C": OUTPUT_C,
    "OUTPUT_D": OUTPUT_D
}

sensor_port_map = {
    "INPUT_1": INPUT_1,
    "INPUT_2": INPUT_2,
    "INPUT_3": INPUT_3,
    "INPUT_4": INPUT_4
}

# Mapas de tipos usando lambda
motor_type_map = {
    "LM": lambda port: LargeMotor(port),
    "SM": lambda port: MediumMotor(port)
}

sensor_type_map = {
    "US": lambda port: UltrasonicSensor(port),
    "GS": lambda port: GyroSensor(port),
    "CS": lambda port: ColorSensor(port),
    "TS": lambda port: TouchSensor(port)
}

# Inicializar motores
motor_map = {}
sensor_map = {}
ultrasonic_sensor_map = {}
gyro_sensor_map = {}
color_sensor_map = {}
move_tank = []

for port_name, motor_sensor_type in config.items():
    
    if port_name.startswith("OUTPUT") and motor_sensor_type in motor_type_map:
        port = motor_port_map[port_name]
        motor_map[port_name] = motor_type_map[motor_sensor_type](port)

        # Kodetzaileak hasiarazi
        motor_map[port_name].position = 0 

    if port_name.startswith("INPUT") and motor_sensor_type in sensor_type_map:
        port = sensor_port_map[port_name]
        sensor_map[port_name] = sensor_type_map[motor_sensor_type](port)

        # Biraketa sentsorea hasiarazi
        if motor_sensor_type == "GS":
            gyro_sensor_map[port_name] = sensor_map[port_name]
            sensor_map[port_name].reset()
        
        # Kolore sentsorea hasiarazi
        elif motor_sensor_type == "CS":
            color_sensor_map[port_name] = sensor_map[port_name]
            sensor_map[port_name].mode = 'COL-REFLECT' # edo ColorSensor.MODE_COL_REFLECT
        
        # Ukipen sentsorea hasiarazi
        elif motor_sensor_type == "TS":
            ultrasonic_sensor_map[port_name] = sensor_map[port_name]
            sensor_map[port_name].mode = TouchSensor.MODE_TOUCH # edo 'TOUCH'

    if port_name.startswith("MOVE_TANK") and motor_sensor_type in motor_sensor_type:
        move_tank.append(motor_port_map[motor_sensor_type])

tank_drive = MoveTank(move_tank[0], move_tank[1])

# Inicializar motores tanque si están definidos
#left_motor = motor_map.get(config.get("MOVE_TANK_LEFT"))
#right_motor = motor_map.get(config.get("MOVE_TANK_RIGHT"))
#tank_drive = MoveTank(motor_port_map[config.get("MOVE_TANK_LEFT")], motor_port_map[config.get("MOVE_TANK_RIGHT")])

def printPorts():
    print("Hasiarazitako motorrak:")
    for name, motor in motor_map.items():
        print("  {}: {}".format(name, motor.port))

    print("Hasiarazitako sentsoreak:")
    for name, sensor in sensor_map.items():
        print("  {}: {}".format(name, sensor.port))

    print("Hasiarazitako tanketa:")
    print("  Tanque izquierdo: {}".format(move_tank[0]))
    print("  Tanque derecho: {}".format(move_tank[1]))


def multiplex_emisor_udp():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    destino = ("192.168.1.138", 5000)  # Puerto único para todos los datos

    print("Multiplexor UDP en el puerto 5000")

    def leer_encoders():
        while True:
            global encoder_data
            encoder_items = []
            for key, motor in motor_map.items():
                port_id = key.split('_')[1]
                position = motor.position
                encoder_items.append(f"{port_id}:{position}")

            encoder_data = f"ENC:[{','.join(encoder_items)}]"
            time.sleep(0.02)


    def leer_ultrasonidos():
        while True:
            global ultrasonic_data
            ultrasonic_data = f"ULT:{ultrasonic.distance_centimeters}"
            time.sleep(0.1)

    def leer_giro():
        while True:
            global gyro_data
            gyro_data = f"GIR:{gyro.angle}"
            time.sleep(0.05)

    # Inicializar variables compartidas
    encoder_data = "ENC:[]"
    ultrasonic_data = "ULT:0"
    gyro_data = "GIR:0"

    # Lanzar hilos de lectura
    threading.Thread(target=leer_encoders, daemon=True).start()
    threading.Thread(target=leer_ultrasonidos, daemon=True).start()
    threading.Thread(target=leer_giro, daemon=True).start()

    # Bucle principal de envío
    while True:
        mensaje = f"{encoder_data};{ultrasonic_data};{gyro_data}"
        udp_socket.sendto(mensaje.encode(), destino)
        print("Enviado:", mensaje)
        time.sleep(0.05)

# Llamada a la función principal
multiplex_emisor_udp()



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