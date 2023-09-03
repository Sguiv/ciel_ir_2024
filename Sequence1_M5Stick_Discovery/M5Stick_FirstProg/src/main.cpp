#include <Arduino.h>
#include <M5StickCPlus.h>

void setup()
{
  // put your setup code here, to run once:
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Premier Programme !");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
