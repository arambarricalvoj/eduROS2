#!/usr/bin/env python3
# An EV3 Python (library v2) solution to Exercise 3
# of the official Lego Robot Educator lessons that
# are part of the EV3 education software

import time
#import Embestir, Recolocar, Busqueda, Menu
from ev3dev2.motor import Motor, LargeMotor, MediumMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, SpeedPercent, MoveTank, MotorSet
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import UltrasonicSensor, GyroSensor, ColorSensor
from ev3dev2.button import Button
from ev3dev2.sound import Sound

pwGirar = 80
pWRecolocar = 80
pwEmbestir = 80
lightLineEmbestir = 25

#motor_specs={OUTPUT_A : LargeMotor, OUTPUT_D : LargeMotor}

motorUltrasonic = Motor(OUTPUT_C)
ultrasonic = UltrasonicSensor(INPUT_4)
tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
gyro = GyroSensor(INPUT_2)
csIZQ = ColorSensor(INPUT_1)
#csDER = ColorSensor(INPUT_3)

motorUltrasonic.position = 0 
while True:
    print(ultrasonic.distance_centimeters)


motorUltrasonic.on_for_degrees(15, 180)