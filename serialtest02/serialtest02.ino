int val_0, val_1, val_2, val_3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val_0 = analogRead(0) / 4;
  val_1 = analogRead(1) / 4;
  val_2 = analogRead(2) / 4;
  val_3 = analogRead(3) / 4;

  if (Serial.available() > 0) {
    Serial.write(val_0);
    Serial.write(val_1);
    Serial.write(val_2);
    Serial.write(val_3);
    
    Serial.read();
  }
}
