int ledPin=2;

void setup() {
 pinMode(ledPin,OUTPUT);
}

void loop() {
 digitalWrite(ledPin,1);
 delay(500);
 digitalWrite(ledPin,0);
 delay(500);                   
}
