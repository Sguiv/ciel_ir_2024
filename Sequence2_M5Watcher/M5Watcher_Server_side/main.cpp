/**
 * @file Programme de test de la réception des données en provenance du flow node-red
 * @brief Recoit les données et les affichent à l'état brut sur l'écran.
*/
#include <Arduino.h>
#include <M5StickCPlus.h>


/**
 * @brief Initialise l'écran et la liaison série
*/
void setup() {
  Serial.begin(115200);
  M5.begin();
  M5.lcd.setTextSize(1);
  M5.lcd.setRotation(1);

}


/**
 * @brief Quand un paquet de données JSON est recu il est lu et affiché à l'écran, un nouveau paquet efface le précédent (curseur(0,0))
*/
void loop() {
  
  M5.lcd.setCursor(0,0);
  while(Serial.available())
  {
    M5.Lcd.printf("%c",Serial.read());
  }
  
  
  
}

