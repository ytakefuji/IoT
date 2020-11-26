int ledPin=2;
boolean state=false;

void setup() {
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
Serial.println("ready");
}

void loop() {
if(Serial.available()>0){
String s=Serial.readString();

if(s=="on") { state=true;}
if(s=="off") { state=false;}
       }
delay(100);
if(state){ state=true;digitalWrite(ledPin,state);}
else {state=false;digitalWrite(ledPin,state);}
}
