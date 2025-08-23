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
distanciaBuscar = 40
distanciaRecolocar = 40

motorUltrasonic = Motor(OUTPUT_C)
ultrasonic = UltrasonicSensor(INPUT_4)
tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
gyro = GyroSensor(INPUT_2)
csIZQ = ColorSensor(INPUT_1)
#csDER = ColorSensor(INPUT_3)

motorUltrasonic.position = 0 

while True:
    #print(motorUltrasonic.position)

    #motorUltrasonic.on_for_degrees(15, 180)
    #motorUltrasonic.on_for_degrees(15, -180)

    gyro.reset()

    if ultrasonic.distance_centimeters>distanciaBuscar:
        motorUltrasonic.on(15)
        while ultrasonic.distance_centimeters>distanciaBuscar:
            if motorUltrasonic.position<=0:
                motorUltrasonic.on(15)
            if motorUltrasonic.position>=180:
                motorUltrasonic.on(-15)
            #print('ULT:'+str(ultrasonic.distance_centimeters))
            #print('MOT:'+str(motorUltrasonic.position))
        motorUltrasonic.off()

    posMotUlt = motorUltrasonic.position
    if motorUltrasonic.position > 90:
        while gyro.angle<posMotUlt-90:
            tank_drive.on(SpeedPercent(pwGirar*(-1)), SpeedPercent(pwGirar))
            motorUltrasonic.on_for_degrees(15, 90-motorUltrasonic.position)
    elif motorUltrasonic.position < 90:
        while gyro.angle>motorUltrasonic.position-90:
            tank_drive.on(SpeedPercent(pwGirar), SpeedPercent(pwGirar*(-1)))
            motorUltrasonic.on_for_degrees(15, 90-motorUltrasonic.position)
    
    tank_drive.off()
    time.sleep(0.3)

    while csIZQ.reflected_light_intensity>lightLineEmbestir: #and csDER.reflected_light_intensity>lightLineEmbestir:
        tank_drive.on(SpeedPercent(pwEmbestir*(-1)),SpeedPercent(pwEmbestir*(-1)))
    
    tank_drive.off()
    time.sleep(0.3)
    tank_drive.on_for_degrees(SpeedPercent(35),SpeedPercent(35),400)

    gyro.reset()
    while (gyro.angle<160 and ultrasonic.distance_centimeters>distanciaRecolocar):
        tank_drive.on(SpeedPercent(pWRecolocar*(-1)),SpeedPercent(pWRecolocar))
    tank_drive.off()
            
    motorUltrasonic.on_for_degrees(15, -90)