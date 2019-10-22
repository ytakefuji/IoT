#include <Wire.h>
#include "ADXL345.h"
#include <Servo.h> 
Servo myservo;
const float alpha = 0.5;

double fXg = 0;
double fYg = 0;
double fZg = 0;

ADXL345 acc;

void setup()
{
  acc.begin();
  Serial.begin(9600);
   myservo.attach(2);
  delay(10);
}


void loop()
{
  double pitch, roll, Xg, Yg, Zg;
  acc.read(&Xg, &Yg, &Zg);

  //Low Pass Filter
  fXg = Xg * alpha + (fXg * (1.0 - alpha));
  fYg = Yg * alpha + (fYg * (1.0 - alpha));
  fZg = Zg * alpha + (fZg * (1.0 - alpha));

  //Roll & Pitch Equations
  roll  = (atan2(-fYg, fZg)*180.0)/M_PI;
  pitch = (atan2(fXg, sqrt(fYg*fYg + fZg*fZg))*180.0)/M_PI;
myservo.write(roll);
//Serial.print(pitch);
  //Serial.println(roll);

  delay(1);
}
