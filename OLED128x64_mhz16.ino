//install U8glib using Manage Libraries
#include <Wire.h> 
#include <U8glib.h>
#include <SoftwareSerial.h>
#include "NDIR_SoftwareSerial.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
bool metric=true;
int yPos = 0;
char data[20];
int i=0;
NDIR_SoftwareSerial mySensor(16, 17);

void setup(void) {
u8g.setColorIndex(1);
//u8g.setFont(u8g_font_7x14);
//u8g.setFont(u8g_font_10x20);
u8g.setFont(u8g_font_fub20);
Serial.begin(9600);
if (mySensor.begin()) {
 Serial.println("Wait 3 seconds for sensor initialization...");
 delay(3000); } else {
 Serial.println("ERROR: Failed to connect to the sensor.");
   while(1); }
for (int j=0;j<20;j++){data[j]=' ';}
}

void loop(void) {
if(mySensor.measure()){
sprintf(data,"%d",mySensor.ppm);
Serial.print(mySensor.ppm);
Serial.println(" ppm");
    }

yPos=50;
u8g.firstPage();  
  do {
  u8g.drawStr(25,yPos,data);
  u8g.drawStr(0,20,"CO2:ppm");
  } while(u8g.nextPage());    
delay(1000);
}
