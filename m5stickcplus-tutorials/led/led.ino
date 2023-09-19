#include <M5StickCPlus.h>

void setup() {
  M5.begin();
  pinMode(M5_LED, OUTPUT);
  digitalWrite(M5_LED, LOW);
}
void loop() {
  digitalWrite(M5_LED, !digitalRead(M5_LED));
  delay(1000);
}