import serial,os
s=serial.Serial('com3',9600)
while 1:
 i=input('enter: ')
 if i=='q':
  s.close()
  os._exit(0)
 s.write(int(i))

