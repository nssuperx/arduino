const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int a = analogRead(1);
  a = map(a,0,1023,30,500);
  digitalWrite(LED_PIN, HIGH);
  delay(a);
  digitalWrite(LED_PIN, LOW);
  delay(a);
}
