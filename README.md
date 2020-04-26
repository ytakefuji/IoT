# IoT

All python codes were tested on Windows 10 using Arduino Nano.
Arduino Nano (ATMEGA328P) is composed of 30 pins DIP with 32 KB ISP flash memory with read-while-write capabilities, 1 KB EEPROM, 2 KB SRAM, 23 general purpose I/O lines, 32 general purpose working registers, three flexible timer/counters with compare modes, internal and external interrupts, serial programmable USART, a byte-oriented 2-wire serial interface (I2C), SPI serial port, 6-channel 10-bit A/D converter.

You should download and install open-source Arduino Software (IDE):
<a href="https://www.arduino.cc/en/main/software"> Arduino Software(IDE)</a>

<img src="https://github.com/ytakefuji/IoT/blob/master/nanopins.jpg" height=200 width=400>

microphone--arduinoNANO--USB-PC
<pre>
oscillo.py and mic.ino using MAX4466 (High Precision Preamplifier Electret Microphone Amplifier) with 3 pins
# captured analog data (10-bit) using microphone will be transmitted from Arduino Nano to PC through USB.
# oscillo.py is more stable than mic.py.
$ python oscillo.py 
or
$ python mic.py

# ASSIGNMENT: use a single LED instead of microphone.
# An LED is a device to generate electric power using light.
# Contrarily, an LED is also a light-emitting diode using electric power.
modify mic.py or oscillo.py using a single LED for sensing the intensity of light.
</pre>
--------------------------
adxl345--arduino-USB-PC
<pre>
ADXL345 (I2C) is a 3-axis accelerometer with high resolution (13-bit) measurement 
at up to ±16 g. pitch_roll.ino using I2C generates pitch and role respectively.

pitch_roll.ino
|__ADXL345.cpp
|__ADXL345.h
$ python pitch_roll.py
</pre>
--------------------------
light sensor 
<pre>
tcs34725--arduino-PC
tcs34725.ino
</pre>
--------------------------
co2 sensor: MH-Z16 co2 sensor based on NDIR
<pre>
Measured data is displayed on OLED128x64.  
U8glib manages displaying data on OLED.

MH-Z16 is a very accurate 
OLED128x64_mhz16.ino
|__NDIR_SoftwareSerial.h
|__NDIR_SoftwareSerial.cpp
|__U8glib.h
</pre>
--------------------------
earthquake(adxl345)+weather(bme280:air,temp,humid)
<pre>
ADXL345 (3D-shaking) and BME280 (aid pressure, temperature, humidity) data are displayed
on OLED128x64 using U8glib.

OLED_adxl345_bme280.ino
|__ADXL345.cpp
|__ADXL345.h
|__BME280I2C.cpp
|__BME280I2C.h
</pre>
--------------------------
PONG game
<pre>
PONG.ino is a game of ping pong where ADXL345 gives input of pitch and role 
for controlling a ball.

PONG.ino
|__Adafruit_GFX.h
|__Adafruit_SSD1306.h
|__ADXL345.h
|__ADXL345.cpp
</pre>
---------------------------
servo+adxl345
<pre>
servo_adxl345.ino manipulates a servo based on pitch and role by ADXL345.

servo_adxl345.ino
|__ADXL345.h
|__ADXL345.cpp
|__Servo.h
</pre>
---------------------------
---------------------------
Assignment: gmail unread messages; LED blinks the number of unread messages
<pre>
gmailcheck.py on PC is to indicate the number of unread messages in gmail.
Create gcheck.py by modifing gmailcheck.py to blink LEDs depending on given number.
Create blink.ino on Arduino where LED blinks the number of unread messages.
HINT: use "serial" for communications between PC and Arduino.
HINT: /dev/ttyS3 in Bash ubuntu on Windows, COM3 in Windows
HINT: the number of blinks can be built by using "for loop" in Arduino.
HINT: use cron for regularily executing command
# run crontab:
$ sudo service cron start
# depict cron content by crontab -e (edit)
$ crontab -e
# set SHELL, PATH, commands(minute, hour, day, month, day of the week, command)
SHELL=/bin/bash
PATH=/home/takefuji/miniconda3/bin:/home/takefuji/miniconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
# every minute gcheck.py will be executed.
* * * * * python gcheck.py >/dev/null
# ┌───────────── minute (0 - 59)
# │ ┌───────────── hour (0 - 23)
# │ │ ┌───────────── day of the month (1 - 31)
# │ │ │ ┌───────────── month (1 - 12)
# │ │ │ │ ┌───────────── day of the week (0 - 6) (Sunday to Saturday;
# │ │ │ │ │                                   7 is also Sunday on some systems)
# │ │ │ │ │
# │ │ │ │ │
# * * * * * command to execute
</pre>
---------------------------
