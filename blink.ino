// this is for gcheck.py
// LED blinks received number times

int ledPin=2;

void setup() {
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
digitalWrite(ledPin,0);
Serial.println("ready");
}

void loop() {
if(Serial.available()>0){
int c=Serial.read();
int i;
delay(1000);
for(byte i = 0; i <= c; i++) {
 digitalWrite(ledPin,1);
 delay(200);
 digitalWrite(ledPin,0);
 delay(100); 
    }
}
}
