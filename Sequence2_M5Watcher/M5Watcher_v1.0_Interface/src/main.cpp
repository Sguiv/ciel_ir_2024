#include <Arduino.h>
#include <M5StickCPlus.h>


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setCursor(0, 10);
}

void loop()
{

  while(Serial.available()){
    M5.Lcd.setCursor(0,10);
    M5.Lcd.setTextSize(1);
    M5.Lcd.print(Serial.readString());
  }
  // put your main code here, to run repeatedly:
}
