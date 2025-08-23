#!/usr/bin/env python3
# An EV3 Python (library v2) solution to Exercise 3
# of the official Lego Robot Educator lessons that
# are part of the EV3 education software

import time
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, SpeedPercent, MoveTank, MotorSet
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import UltrasonicSensor, GyroSensor, ColorSensor

tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
ultrasonic = UltrasonicSensor(INPUT_2)
gyro = GyroSensor(INPUT_3)
csIZQ = ColorSensor(INPUT_1)
csDER = ColorSensor(INPUT_4)
mot1 = LargeMotor(OUTPUT_A)
mot2 = LargeMotor(OUTPUT_D)

def sinCalibrate(lightLine, distanciaRecolocar, pWRecolocar):
    if csIZQ.reflected_light_intensity<=lightLine:
        while (gyro.angle<180 and ultrasonic.distance_centimeters>distanciaRecolocar):
            tank_drive.on(SpeedPercent(pWRecolocar*(-1)),SpeedPercent(pWRecolocar))
            
    else:
        while (gyro.angle>-180 and ultrasonic.distance_centimeters>distanciaRecolocar):
            tank_drive.on(SpeedPercent(pWRecolocar),SpeedPercent(pWRecolocar*(-1)))
    
    tank_drive.off()
    time.sleep(0.3)

    if (ultrasonic.distance_centimeters<distanciaRecolocar):
        return 1
    else:
        return 0

def conCalibrate(distanciaRecolocar, pWRecolocar):
    gyro.reset()
    exit=0
    while (gyro.angle<150):
        if (gyro.angle>50 and ultrasonic.distance_centimeters<distanciaRecolocar):
            tank_drive.off()
            time.sleep(0.3)
            exit=1
            break
        else:
            tank_drive.on(SpeedPercent(pWRecolocar*(-1)),SpeedPercent(pWRecolocar))

    tank_drive.off()
    time.sleep(0.1)
    return exit