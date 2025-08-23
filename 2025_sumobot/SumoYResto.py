#!/usr/bin/env python3
# An EV3 Python (library v2) solution to Exercise 3
# of the official Lego Robot Educator lessons that
# are part of the EV3 education software

import time
import Embestir, Recolocar, Busqueda, Menu
from ev3dev2.motor import LargeMotor, OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D, SpeedPercent, MoveTank, MotorSet
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import UltrasonicSensor, GyroSensor, ColorSensor
from ev3dev2.button import Button
from ev3dev2.sound import Sound

#motor_specs={OUTPUT_A : LargeMotor, OUTPUT_D : LargeMotor}

tank_drive = MoveTank(OUTPUT_A, OUTPUT_D)
#tank = MotorSet(motor_specs)
ultrasonic = UltrasonicSensor(INPUT_2)
gyro = GyroSensor(INPUT_3)
csIZQ = ColorSensor(INPUT_1)
csDER = ColorSensor(INPUT_4)
mot1 = LargeMotor(OUTPUT_A)
mot2 = LargeMotor(OUTPUT_D)
btn = Button()
musiquita = Sound()

pwBuscar = 25
pWRecolocar = 45
pwEmbestir = 85

distanciaBuscar = 40
distanciaRecolocar = 40
lightLineEmbestir = 7

def alpha2023():
    gyro.reset()
    accion=0
    while True:
        Busqueda.izquierda(distanciaBuscar, pwBuscar)
        if ultrasonic.distance_centimeters<=distanciaBuscar:
            #tank_drive.on_for_degrees(SpeedPercent(25), SpeedPercent(-25), 30)
            while True:
                Embestir.conCalibrate(lightLineEmbestir, pwEmbestir)
                accion=Recolocar.conCalibrate(distanciaRecolocar, pWRecolocar)

                if accion==0:
                    alpha2023()
    
        Busqueda.derecha(distanciaBuscar, pwBuscar)
        if ultrasonic.distance_centimeters<=distanciaBuscar:
            #tank_drive.on_for_degrees(SpeedPercent(-25), SpeedPercent(25), 30)
            while True:
                Embestir.conCalibrate(lightLineEmbestir, pwEmbestir)
                accion=Recolocar.conCalibrate(distanciaRecolocar, pWRecolocar)

                if accion==0:
                    alpha2023()

def main():
    Menu.main()

    while True:

        #musiquita.play_file('MusicaClubPenguin.wav', volume = 100, play_type=1)

        if btn.right:
            time.sleep(2.9)
            Embestir.conCalibrate(lightLineEmbestir, pwEmbestir)
            Recolocar.conCalibrate(distanciaRecolocar, pWRecolocar)
            alpha2023()

        elif btn.left:
            time.sleep(2.9)
            alpha2023()

        elif btn.up:
            time.sleep(4.4)
            Embestir.conCalibrate(lightLineEmbestir, pwEmbestir)
            Recolocar.conCalibrate(distanciaRecolocar, pWRecolocar)
            alpha2023()

        elif btn.enter:
            time.sleep(5.4)
            Embestir.conCalibrate(lightLineEmbestir, pwEmbestir)
            Recolocar.conCalibrate(distanciaRecolocar, pWRecolocar)
            alpha2023()

        elif btn.down:
            time.sleep(7.9)
            Embestir.conCalibrate(lightLineEmbestir, pwEmbestir)
            Recolocar.conCalibrate(distanciaRecolocar, pWRecolocar)
            alpha2023()

        
main()

