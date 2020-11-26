# led-on or led-off
import serial
from time import sleep
s=serial.Serial("COM3",9600)
sleep(1.5)
if s.is_open:
 s.write(str('on').encode())
 s.close()
else:print('serial problem')
s.close()
 
