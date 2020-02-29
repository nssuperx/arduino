int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(1);
  //val = map(val,0,1023,0,255);
  //Serial.write(val);
  Serial.println("hello");
}
