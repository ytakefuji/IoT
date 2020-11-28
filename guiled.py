import serial
import time
import tkinter

def quit():
    global tkTop
    tkTop.destroy()

def set_button1_state():
        global b
        b += 1
        varLabel.set("LED ON ")
        ser.write(bytes('on', 'UTF-8'))
        varLabel2.set(b)
        print(b)

def set_button2_state():
        varLabel.set("LED OFF")
        ser.write(bytes('off', 'UTF-8'))

ser = serial.Serial('com3', 9600)

tkTop = tkinter.Tk()
tkTop.geometry('300x200')
tkTop.title("IoT24hours")
tkTop.counter = 0
b = tkTop.counter

varLabel = tkinter.IntVar()
tkLabel = tkinter.Label(textvariable=varLabel, )

varLabel2 = tkinter.IntVar()
tkLabel2 = tkinter.Label(textvariable=varLabel2, )

button1 = tkinter.IntVar()
button1state = tkinter.Button(tkTop,
    text="ON",
    command=set_button1_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 5,
    activebackground='green'
)
button1state.grid(row=1,column=0)

button2 = tkinter.IntVar()
button2state = tkinter.Button(tkTop,
    text="OFF",
    command=set_button2_state,
    height = 4,
    fg = "black",
    width = 8,
    bd = 6,
    activebackground='green'
)

button2state.grid(row=1,column=2)

tkButtonQuit = tkinter.Button(
    tkTop,
    text="Quit",
    command=quit,
    height = 4,
    fg = "black",
    width = 8,
    bg = 'yellow',
    bd = 7
)
tkButtonQuit.grid(row=1,column=4)
tkinter.mainloop()
