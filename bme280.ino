//install BME280 by Tyler Glenn using Manage Libraries
#include <BME280I2C.h>
#include <Wire.h> 
BME280I2C bme;
bool metric=true;
char data[20];

void setup(void) {
for (int j=0;j<20;j++){data[j]=' ';}
Wire.begin();
Serial.begin(9600);
while(!Serial) {} // Wait
  while(!bme.begin()){
    Serial.println("Could not find BME280 sensor!");
    delay(1000);     }
 }

void loop(void) {

float temp(NAN), hum(NAN), pres(NAN);
BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
BME280::PresUnit presUnit(BME280::PresUnit_Pa);

bme.read(pres, temp, hum, tempUnit, presUnit);
sprintf(data,"%ld %d",round(pres),round(temp));
float HI=0.81*temp+0.01*hum*(0.99*temp-14.3)+46.3;
sprintf(data,"%s  %d",data,round(hum));
sprintf(data,"%s  %d",data,round(HI));
Serial.println(data);
delay(1000);
}
