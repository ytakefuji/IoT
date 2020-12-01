import pyfirmata
from time import sleep
b=pyfirmata.Arduino('COM3')
#i=pyfirmata.util.Iterator(b)
while 1:
 b.digital[2].write(1)
 sleep(1)
 b.digital[2].write(0)
 sleep(1)
# to read analog port[0]
# b.analog[0].read()
