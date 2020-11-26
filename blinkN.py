import serial,os
from time import sleep
s=serial.Serial("COM3",9600)
#print(s.readline().decode())
while 1:
 i=input('enter: ')
 if i=='q':
  s.close()
  os._exit(0)
 s.write(int(i))
