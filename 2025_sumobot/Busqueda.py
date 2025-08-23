#!/usr/bin/env python3
# An EV3 Python (library v2) solution to Exercise 3
# of the official Lego Robot Educator lessons that
# are part of the EV3 education software

#from time import sleep
import time
import Embestir, Recolocar
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, SpeedPercent, MoveTank
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import UltrasonicSensor, GyroSensor, ColorSensor


tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
ultrasonic = UltrasonicSensor(INPUT_2)
gyro = GyroSensor(INPUT_3)
csIZQ = ColorSensor(INPUT_1)
csDER = ColorSensor(INPUT_4)
mot1 = LargeMotor(OUTPUT_A)
mot2 = LargeMotor(OUTPUT_D)

def izquierda(distanciaBuscar, pwBuscar):
    while ultrasonic.distance_centimeters>distanciaBuscar and gyro.angle>-50:
        tank_drive.on(SpeedPercent(pwBuscar), SpeedPercent(pwBuscar*(-1)))
    
    tank_drive.off()
    time.sleep(0.1)


def derecha(distanciaBuscar, pwBuscar):
    while ultrasonic.distance_centimeters>distanciaBuscar and gyro.angle<50:
        tank_drive.on(SpeedPercent(pwBuscar*(-1)), SpeedPercent(pwBuscar))
    
    tank_drive.off()
    time.sleep(0.1)