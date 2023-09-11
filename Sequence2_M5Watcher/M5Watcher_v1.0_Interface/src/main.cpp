#include <Arduino.h>
#include <M5StickCPlus.h>
#include <string.h>
/*Déclaration des variables globales*/
String nw_cidr = "192.168.1.12/24";
String nw_mac = "a0:b2:18:c3:12:85";
unsigned long tstamp = 1694450530;
unsigned long uptime = 0;
float cpu_load[3] = {0, 0, 0};
unsigned long used_memory = 0;
unsigned long free_memory = 0;
unsigned int nw_rx = 0;
unsigned int nw_tx = 0;
unsigned long dernierMillis=millis();

void demoVariables()
{
  tstamp += 3;
  uptime += 3;
  for (int i = 0; i < 3; i++)
  {
    cpu_load[i]=random(0,999)/10.0;
  }
  used_memory = random(1000000,10000000);
  free_memory = 10000000-used_memory;
  nw_rx = random(0,10000);
  nw_tx = random(0,10000);

}
void pagePrincipale()
{
//Rectangles de fond
  M5.Lcd.fillRoundRect(3,3,77,131,5,TFT_DARKGREEN);
  M5.Lcd.fillRoundRect(82,3,77,87,5,0x7d16);
  M5.Lcd.fillRoundRect(161,3,77,87,5,TFT_DARKGREY);
  M5.Lcd.fillRoundRect(83,91,154,42,5,TFT_BLUE);

  //CPU 1,2,3
  M5.Lcd.drawRoundRect(4,5,75,42,5,WHITE);
  M5.Lcd.drawRoundRect(4,48,75,42,5,WHITE);
  M5.Lcd.drawRoundRect(4,91,75,42,5,WHITE);
  //Memory
  M5.Lcd.drawRoundRect(83,5,75,42,5,WHITE);
  M5.Lcd.drawRoundRect(83,48,75,42,5,WHITE);
  //Network
  M5.Lcd.drawRoundRect(162,5,75,42,5,WHITE);
  M5.Lcd.drawRoundRect(162,48,75,42,5,WHITE);

  //Wake Time
  M5.Lcd.drawRoundRect(83,91,154,42,5,WHITE);

  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK,TFT_DARKGREEN);
  M5.Lcd.setCursor(26,0);
  M5.Lcd.print("CPU");


  M5.Lcd.setCursor(16,18);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f",cpu_load[0]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  M5.Lcd.setCursor(16,60);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f",cpu_load[1]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  M5.Lcd.setCursor(16,104);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f",cpu_load[2]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK,0x7d16);
  M5.Lcd.setCursor(100,0);
  M5.Lcd.print("Mem");
  
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK,TFT_DARKGREY);
  M5.Lcd.setCursor(180,0);
  M5.Lcd.print("Net");
  
  
}
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  M5.begin();
  M5.Lcd.setRotation(1);
  
}

void loop()
{
  if(millis()-dernierMillis>3000)
  {
  dernierMillis=millis();
  demoVariables();
  pagePrincipale();
  

  }
    

 
}
