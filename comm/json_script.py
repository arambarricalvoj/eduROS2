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
            sensor_map[port_name].reset()
        # Kolore sentsorea hasiarazi
        elif motor_sensor_type == "CS":
            sensor_map[port_name].mode = 'COL-REFLECT' # edo ColorSensor.MODE_COL_REFLECT
        # Ukipen sentsorea hasiarazi
        elif motor_sensor_type == "TS":
            sensor_map[port_name].mode = TouchSensor.MODE_TOUCH # edo 'TOUCH'

    if port_name.startswith("MOVE_TANK") and motor_sensor_type in motor_sensor_type:
        move_tank.append(motor_port_map[motor_sensor_type])

tank_drive = MoveTank(move_tank[0], move_tank[1])

# Inicializar motores tanque si están definidos
#left_motor = motor_map.get(config.get("MOVE_TANK_LEFT"))
#right_motor = motor_map.get(config.get("MOVE_TANK_RIGHT"))
#tank_drive = MoveTank(motor_port_map[config.get("MOVE_TANK_LEFT")], motor_port_map[config.get("MOVE_TANK_RIGHT")])

print("Hasiarazitako motorrak:")
for name, motor in motor_map.items():
    print("  {}: {}".format(name, motor.port))

print("Hasiarazitako sentsoreak:")
for name, sensor in sensor_map.items():
    print("  {}: {}".format(name, sensor.port))

print("Hasiarazitako tanketa:")
print("  Tanque izquierdo: {}".format(move_tank[0]))
print("  Tanque derecho: {}".format(move_tank[1]))
