int mic=A7;
unsigned int val=0;

void setup() {
Serial.begin(115200);

}

void loop() {
for(int i=0;i<178;i++){
  val +=analogRead(mic);
}
val=val/178;
Serial.println(val,DEC);
val=0;
}
