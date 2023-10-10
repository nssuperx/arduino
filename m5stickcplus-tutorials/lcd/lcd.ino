#include <M5StickCPlus.h>


// スプライトを使う
// https://github.com/m5stack/M5Stack/blob/master/src/utility/Sprite.h
// 普通はM5.Lcdを使うが、遅いのでスプライトを使う
// http://docs.m5stack.com/en/api/core/lcd
TFT_eSprite Disbuff = TFT_eSprite(&M5.Lcd);

void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(3);        // なぜかTFT_eSpriteのsetRotation()が使えなかった
  Disbuff.createSprite(240, 135);
  Disbuff.fillRect(0, 0, 240, 135, Disbuff.color565(10, 10, 10));
  Disbuff.pushSprite(0, 0);
  Disbuff.setTextSize(2);
}

void loop() {
  float accX, accY, accZ;
  M5.IMU.getAccelData(&accX, &accY, &accZ);

  Disbuff.fillRect(0, 0, 240, 135, TFT_BLACK);

  Disbuff.setCursor(10, 10);
  Disbuff.setTextColor(RED);
  Disbuff.printf("X: %.2f g", accX);
  Disbuff.setCursor(10, 40);
  Disbuff.setTextColor(BLUE);
  Disbuff.printf("Y: %.2f g", accY);
  Disbuff.setCursor(10, 70);
  Disbuff.setTextColor(GREEN);
  Disbuff.printf("Z: %.2f g", accZ);
  Disbuff.pushSprite(0, 0);

  delay(100);
}