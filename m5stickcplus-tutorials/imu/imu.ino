#include <M5StickCPlus.h>

float gyroX, gyroY, gyroZ;

void setup() {
  M5.begin();
  M5.IMU.Init();
  Serial.begin(9600);
}
void loop() {
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  Serial.printf("%6.2f,%6.2f,%6.2f\n", gyroX, gyroY, gyroZ);
  delay(100);
}
