//install U8glib using Manage Libraries
//install BME280 by Tyler Glenn using Manage Libraries
#include <BME280I2C.h>
#include <Wire.h> 
#include <U8glib.h>
#include "ADXL345.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
BME280I2C bme;
bool metric=true;
int yPos = 0;
char data[20];
char data1[20];
int i=0;

double Xg, Yg, Zg,cX,cY,cZ;
ADXL345 acc;

void setup(void) {
acc.begin();
u8g.setColorIndex(1);
u8g.setFont(u8g_font_7x14);
for (int j=0;j<20;j++){data[j]=' ';}
Serial.begin(9600);
while(!Serial) {} // Wait
  while(!bme.begin()){
    Serial.println("Could not find BME280 sensor!");
    delay(1000);     }
    
 cX=cY=cZ=0;
 for(int i=0;i<20;i++){
 acc.read(&Xg, &Yg, &Zg);
  cX =cX+ abs(Xg);
  cY =cY+ abs(Yg);
  cZ =cZ+ abs(Zg);
  delay(200);
 }
cX=cX/20;
cY=cY/20;
cZ=cZ/20;
Serial.print(cX);
Serial.print(" ");
Serial.print(cY);
Serial.print(" ");
Serial.println(cZ);
Serial.println("Start");
}

void serialEvent(){
  for(i-0;i<20;i++){data1[i]=' ';}
char c;
i=0;
while(Serial.available()>0){
c=Serial.read();
if (c!='\n') {data1[i]=c;i++;}
else {i=0;break;}
}
}

void loop(void) {
  double Xg, Yg, Zg,g,si;
  acc.read(&Xg, &Yg, &Zg);
Xg=abs(abs(Xg)-cX);
Yg=abs(abs(Yg)-cY);
Zg=abs(abs(Zg)-cZ);
g=sqrt(pow(Xg,2.0)+pow(Yg,2.0)+pow(Zg,2.0));


float temp(NAN), hum(NAN), pres(NAN);
uint8_t pressureUnit(0);           // unit: B000 = Pa, B001 = hPa, B010 = Hg, B011 = atm, B100 = bar, B101 = torr, B110 = N/m^2, B111 = psi
bme.read(pres, temp, hum, metric, pressureUnit);
sprintf(data,"%ld %d",round(pres),round(temp));
float HI=0.81*temp+0.01*hum*(0.99*temp-14.3)+46.3;
sprintf(data,"%s  %d",data,round(hum));
sprintf(data,"%s  %d",data,round(HI));
dtostrf(g,1,2,data1);
Serial.println(data);
Serial.println(g);
if(g<0.11 ){sprintf(data1,"%s %s",data1,"4<");}
else if(g>0.11 && g<0.24){sprintf(data1,"%s %s",data1,"5-");}
else if(g>=0.24 && g<0.52){sprintf(data1,"%s %s",data1,"5+");}
else if(g>=0.52 && g<0.83){sprintf(data1,"%s %s",data1,"6-");}
else if(g>=0.83 && g<1.5){sprintf(data1,"%s %s",data1,"6+");}
else if(g>=1.5){sprintf(data1,"%s %s",data1,"7>");}
delay(1000);
yPos=52;
u8g.firstPage();  
  do {
  u8g.drawStr(0,yPos,data);
  u8g.drawStr(5,10,data1);
  u8g.drawStr(5,32,"air  temp hum HI");
  } while(u8g.nextPage());   
}
