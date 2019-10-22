import collections
import serial
import threading
import time    

import matplotlib.pyplot as plt
import matplotlib.animation as animation    
t=time.time()
x = collections.deque(maxlen=400)
y = collections.deque(maxlen=400)    
def in_background():
    serialport = serial.Serial("COM3",115200, timeout=0.5)    

    while True:    
        command = serialport.readline()
        console_output = str(command).strip('\r\n')
        if console_output != "":
            x.append(time.time()-t)
            y.append(console_output)
    serialport.close()    

thread = threading.Thread(target = in_background)
thread.start()    
fig = plt.figure('analogIN')
ax = plt.axes(ylim=(0,200))
def animate(i):
 plt.cla()
 ax.relim()
 ax.autoscale_view(True,True,True)
 ax.set_ylim(0,200)
 plt.yticks([])
 ax.plot(x,y)
ani = animation.FuncAnimation(fig, animate, interval=20,blit=False, save_count=100)
plt.show()
