# led-on or led-off
import serial,os
from time import sleep
s=serial.Serial("COM3",9600)
s.write(str("off").encode())
