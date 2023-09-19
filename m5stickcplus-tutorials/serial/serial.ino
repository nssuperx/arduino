#include <M5StickCPlus.h>

// int count = 0;

void setup() {
  M5.begin();
  Serial.begin(9600);
}

float floatmap(float value, float fromLow, float fromHigh, float toLow, float toHigh){
  return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

void loop() {
  delay(50);
  // float rad = float(map(millis(), 0, 5000, 0, 2*PI*1000)) * 0.001;
  float rad = floatmap(millis(), 0.0, 2000.0, 0.0, 2.0*PI);
  Serial.println(sin(rad));
}