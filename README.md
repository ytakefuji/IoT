# IoT
All python codes were tested on Windows 10 when Arduino Nano was used.

microphone--arduino--USB-PC
<pre>
mic.ino
$ python oscillo.py 
or
$ python mic.py
</pre>
--------------------------
adxl345--arduino-USB-PC
<pre>
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
co2 sensor: MH-Z16
<pre>
OLED128x64_mhz16.ino
|__NDIR_SoftwareSerial.h
|__NDIR_SoftwareSerial.cpp
|__U8glib.h
</pre>
--------------------------
earthquake(adxl345)+weather(bme280:air,temp,humid)
<pre>
OLED_adxl345_bme280.ino
|__ADXL345.cpp
|__ADXL345.h
|__BME280I2C.cpp
|__BME280I2C.h
</pre>
--------------------------
PONG
<pre>
PONG.ino
|__Adafruit_GFX.h
|__Adafruit_SSD1306.h
|__ADXL345.h
|__ADXL345.cpp
</pre>
---------------------------
servo+adxl345
<pre>
servo_adxl345.ino
|__ADXL345.h
|__ADXL345.cpp
|__Servo.h
</pre>
---------------------------
---------------------------
Assignment: gmail unread messages
<pre>
gmailcheck.py is to indicate the number of unread messages in gmail.
Modify gmailcheck.py to blink LEDs depending on given number.
Arduino NANO can be used.
HINT: use serial for communications with NANO
HINT: Received int number should be blinked by using for loop in NANO.
</pre>
---------------------------
