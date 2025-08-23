#!/usr/bin/env python3
# An EV3 Python (library v2) solution to Exercise 3
# of the official Lego Robot Educator lessons that
# are part of the EV3 education software

#from time import sleep
import time
from ev3dev2.sensor import INPUT_1, INPUT_2, INPUT_3, INPUT_4
from ev3dev2.sensor.lego import TouchSensor, UltrasonicSensor, GyroSensor, ColorSensor
from ev3dev2.led import Leds
from ev3dev2.button import Button

from ev3dev2.display import Display
from PIL import Image

import ev3dev2.fonts as fonts

ultrasonic = UltrasonicSensor(INPUT_2)
gyro = GyroSensor(INPUT_3)
csIZQ = ColorSensor(INPUT_1)
csDER = ColorSensor(INPUT_4)

btn=Button()
dsp=Display()


def clear():
    dsp.clear()


def printText(pText, pX=45, pY=89, pFont='courB18', pColor='black', pClear=True):
    #pText must be a string.
        
    #Load the text into memory.
    dsp.text_pixels(pText, clear_screen=pClear, x=pX, y=pY, text_color=pColor, font=fonts.load(pFont))
        
    #Print the data stored in memory.
    dsp.update()



def printImage(self, pImagePath):
    #Load the image as PIL (PIL/Image library).
    img = Image.open(pImagePath)

    #Load the image into memory.
    dsp.image.paste(img, (0, 0))

    #Print the data stored in memory.
    dsp.update()

def main():
        #print("EMPIEZO")
    clear()
    
    while True:
        printText(pText='GIROSENSOR', pX=50, pY=35, pFont='courB18', pColor='black', pClear=False)
        printText(pText=str(gyro.angle), pX=0, pY=95, pFont='luBS24', pColor='black', pClear=True)
        
        if btn.enter:
            gyro.reset()
        
        if  btn.up:
            clear()
            break


    while True:
        printText(pText='UlTRASONICO', pX=50, pY=35, pFont='courB18', pColor='black', pClear=False)
        printText(pText=str(ultrasonic.distance_centimeters), pX=0, pY=95, pFont='luBS24', pColor='black', pClear=True)
        if  btn.down:
            clear()
            break

    printText(pText='EMB', pX=135, pY=38, pFont='courB18', pColor='black', pClear=False)
    printText(pText='LOOK', pX=0, pY=38, pFont='courB18', pColor='black', pClear=False)
    printText(pText='>>>', pX=130, pY=58, pFont='luBS24', pColor='black', pClear=False)
    printText(pText='<<<', pX=0, pY=58, pFont='luBS24', pColor='black', pClear=False)
    printText(pText='1.5s', pX=66, pY=12, pFont='courB18', pColor='black', pClear=False)
    printText(pText='2.5s', pX=66, pY=52, pFont='courB18', pColor='black', pClear=False)
    printText(pText='5.0s', pX=66, pY=92, pFont='courB18', pColor='black', pClear=False)

    # Píxeles: 178 x 128