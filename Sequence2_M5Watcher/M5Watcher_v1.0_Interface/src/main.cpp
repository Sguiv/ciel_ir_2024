#include <Arduino.h>
#include <M5StickCPlus.h>
#include <string.h>

/*Déclaration des variables globales
Pour cette version de dev, les valeurs des variables seront simulées
nw_cidr et nw_mac Restent fixes
Les autres variables sont modifiées toutes les 3 secondes de manière aléatoire
*/

String nw_cidr = "192.168.1.12/24";
String nw_mac = "a0:b2:18:c3:12:85";
unsigned long tstamp = 1694450530;
unsigned long uptime = 0;
float cpu_load[3] = {0, 0, 0}; //CPU Load est un tableau de 3 valeurs flottantes cpu_load[0],cpu_load[1],cpu_load[2].
unsigned long used_memory = 0;
unsigned long free_memory = 0;
unsigned int nw_rx = 0;
unsigned int nw_tx = 0;
unsigned long dernierMillis = millis();

/**
 * @brief Fait varier aléatoirement les valeurs des variables pour simuler l'affichage
 */
void demoVariables()
{
  tstamp += 3;
  uptime += 3;
  for (int i = 0; i < 3; i++)
  {
    cpu_load[i] = random(0, 999) / 10.0;
  }
  used_memory = random(1000000, 10000000);
  free_memory = 10000000 - used_memory;
  nw_rx = random(0, 10000);
  nw_tx = random(0, 10000);
}

/**
 * @brief Génère l'affichage de la page principale
 */
void pagePrincipale()
{
  // Rectangles de fond
  M5.Lcd.fillRoundRect(3, 3, 77, 131, 5, TFT_DARKGREEN);
  M5.Lcd.fillRoundRect(82, 3, 77, 87, 5, 0x7d16);
  M5.Lcd.fillRoundRect(161, 3, 77, 87, 5, TFT_DARKGREY);
  M5.Lcd.fillRoundRect(83, 91, 154, 42, 5, TFT_BLUE);

  // CPU 1,2,3
  M5.Lcd.drawRoundRect(4, 5, 75, 42, 5, WHITE);
  M5.Lcd.drawRoundRect(4, 48, 75, 42, 5, WHITE);
  M5.Lcd.drawRoundRect(4, 91, 75, 42, 5, WHITE);
  // Memory
  M5.Lcd.drawRoundRect(83, 5, 75, 42, 5, WHITE);
  M5.Lcd.drawRoundRect(83, 48, 75, 42, 5, WHITE);
  // Network
  M5.Lcd.drawRoundRect(162, 5, 75, 42, 5, WHITE);
  M5.Lcd.drawRoundRect(162, 48, 75, 42, 5, WHITE);

  // Wake Time
  M5.Lcd.drawRoundRect(83, 91, 154, 42, 5, WHITE);

  //Texte CPU
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, TFT_DARKGREEN);
  M5.Lcd.setCursor(26, 0);
  M5.Lcd.print("CPU");

  //Valeur CPU 1
  M5.Lcd.setCursor(16, 18);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", cpu_load[0]); //La fonction printf sera à comprendre et expliquer
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  //Valeur CPU 2
  M5.Lcd.setCursor(16, 60);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", cpu_load[1]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  //Valeur CPU 3
  M5.Lcd.setCursor(16, 104);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", cpu_load[2]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  //Texte Mem
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, 0x7d16);
  M5.Lcd.setCursor(100, 0);
  M5.Lcd.print("Mem");

  //Texte Net
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, TFT_DARKGREY);
  M5.Lcd.setCursor(180, 0);
  M5.Lcd.print("Net");
}

/**
 * @brief Initialisation du M5, de la liaison série et de la rotation écran
*/
void setup()
{

  Serial.begin(115200);
  M5.begin();
  M5.Lcd.setRotation(1);
}


/**
 * @brief Toutes les 3 secondes de nouvelles valeurs sont mises à jour dans les variables et la page
 * principale est rechargée avec les nouvelles valeurs.
 */
void loop()
{
  // Technique utilisée pour compter 3secondes sans faire de delais bloquant
  // La fonction millis() renvoie le nombre de millisecondes écoulées depuis le démarrage du programme
  // dernierMillis n'est mis à jour que toutes les 3000 millisecondes
  if (millis() - dernierMillis > 3000)
  {
    dernierMillis = millis(); //Mise à jour de la valeur du Dernier Millis
    demoVariables();
    pagePrincipale();
  }
}
