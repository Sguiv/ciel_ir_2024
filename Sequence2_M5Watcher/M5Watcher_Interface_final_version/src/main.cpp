#include <Arduino.h>
#include <M5StickCPlus.h>
#include <string.h>
#include <ArduinoJson.h>

#define nbPages 2
// Prototypes des fonctions :
void demoVariables();
void receptionJson();
void pagePrincipale();
void pageReseau();

/*Déclaration des variables globales
Pour cette version de dev, les valeurs des variables seront simulées
nw_cidr et nw_mac Restent fixes
Les autres variables sont modifiées toutes les 3 secondes de manière aléatoire
*/


long long tstamp = 0;
unsigned long uptime = 0;

float cpu_load[3] = {0, 0, 0}; // CPU Load est un tableau de 3 valeurs flottantes cpu_load[0],cpu_load[1],cpu_load[2].
double test;
unsigned long used_memory = 0;
unsigned long free_memory = 0;
unsigned int nw_rx = 0;
unsigned int nw_tx = 0;
unsigned long dernierMillisRecep, dernierMillisRefresh = millis();
float sda = 0;
unsigned int pageActuelle = 0;
bool etatAlarme = false;
 String nw_cidr;
 String nw_mac;
void receptionJson()
{
  // Stream& input;
  StaticJsonDocument<384> doc;

  DeserializationError error = deserializeJson(doc, Serial);

  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    Serial.flush();
    return;
  }
  
  String temp_nw_cidr= doc["nw_cidr"]; // "10.0.2.15/24"
  nw_cidr=temp_nw_cidr;
  JsonObject deviceStats = doc["deviceStats"];
  tstamp = deviceStats["tstamp"]; // 1701637913664
  uptime = deviceStats["uptime"]; // 1554.99

  JsonArray deviceStats_load = deviceStats["load"];
  cpu_load[0] = deviceStats_load[0]; // 3.27
  cpu_load[1] = deviceStats_load[1]; // 1.79
  cpu_load[2] = deviceStats_load[2]; // 1.79

  used_memory = deviceStats["mem"]["used"]; // 3219012
  free_memory = deviceStats["mem"]["free"]; // 3088008

  nw_rx = doc["nw_rx"];     // 256.5
  nw_tx = doc["nw_tx"];     // 523.3
  sda = doc["sda_usage"];   // 0.78
  
  
}
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
  sda = random(0, 999) / 10.0;
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

  // Texte CPU
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, TFT_DARKGREEN);
  M5.Lcd.setCursor(26, 0);
  M5.Lcd.print("CPU");

  // Valeur CPU 1
  M5.Lcd.setCursor(16, 18);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", cpu_load[0]); // La fonction printf sera à comprendre et expliquer
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  // Valeur CPU 2
  M5.Lcd.setCursor(16, 60);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", cpu_load[1]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  // Valeur CPU 3
  M5.Lcd.setCursor(16, 104);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", cpu_load[2]);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");

  // Texte Mem
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, 0x7d16);
  M5.Lcd.setCursor(100, 0);
  M5.Lcd.print("Mem");

  // Valeur HDD
  M5.Lcd.setCursor(93, 18);
  M5.Lcd.printf("%.0f", sda * 100);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");
  M5.Lcd.setCursor(129, 31);
  M5.Lcd.print("HDD");
  // Valeur MEM
  float pourcentMem = (used_memory / (float)(used_memory + free_memory)) * 100.0;

  M5.Lcd.setCursor(93, 60);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%.1f", pourcentMem);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("%");
  M5.Lcd.setCursor(129, 85);
  M5.Lcd.print("RAM");

  // Texte Net
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, TFT_DARKGREY);
  M5.Lcd.setCursor(180, 0);
  M5.Lcd.print("Net");

  // Valeurs NET
  
  M5.Lcd.setCursor(163, 18);
  M5.Lcd.printf("%d", nw_rx);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("Mb/s");
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(220, 31);
  M5.Lcd.print("Rx");
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(163, 60);
  M5.Lcd.printf("%d", nw_tx);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("Mb/s");
  M5.Lcd.setCursor(220, 75);
  M5.Lcd.print("Tx");

  // Texte Server Up
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(BLACK, BLUE);
  M5.Lcd.setCursor(111, 95);
  M5.Lcd.print("Server Up Since:");
  unsigned int days, hours, minutes, secondes;

  unsigned long secondes_dans_1_jour = 3600 * 24;
  unsigned long secondes_dans_1_heure = 3600;
  unsigned long secondes_dans_1_minute = 60;
  unsigned long uptime_temp = uptime;
  days = uptime_temp / secondes_dans_1_jour;
  uptime_temp %= secondes_dans_1_jour;
  hours = uptime_temp / secondes_dans_1_heure;
  uptime_temp %= secondes_dans_1_heure;
  minutes = uptime_temp / secondes_dans_1_minute;
  secondes = uptime_temp % secondes_dans_1_minute;
  M5.Lcd.setCursor(93, 106);

  // M5.Lcd.printf("%ud,%uh,%um,%us",days, hours,minutes,secondes);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%u", days);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("d");

  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%u", hours);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("h");

  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%u", minutes);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("m");

  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%u", secondes);
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("s");
}
/**
 * @brief Affiche l'adresse IP et l'adresse MAC du serveur
 */
void pageReseau()
{
  M5.lcd.fillScreen(BLACK);
  M5.lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.lcd.setCursor(65, 15);
  M5.lcd.println("Network");
  M5.lcd.setTextSize(2);
  M5.lcd.println("IP address:");
  M5.lcd.printf("%s\n", nw_cidr);
  
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

  M5.BtnA.read();
  M5.BtnB.read();
  M5.Beep.update();

  if (M5.BtnA.isPressed())
  {

    pageActuelle++;

    if (pageActuelle >= nbPages)
      pageActuelle = 0;
    // Serial.printf("BtnA pressed : pageActuelle:%d\n", pageActuelle);
    delay(250);
  }
  // Technique utilisée pour compter 3secondes sans faire de delais bloquant
  // La fonction millis() renvoie le nombre de millisecondes écoulées depuis le démarrage du programme
  // dernierMillis n'est mis à jour que toutes les 3000 millisecondes

  if (millis() - dernierMillisRecep > 3000)
  {
    dernierMillisRecep = millis(); // Mise à jour de la valeur du Dernier Millis
    // demoVariables();
    receptionJson();
  }

  if (millis() - dernierMillisRefresh > 500)
  {
    dernierMillisRefresh=millis();
    switch (pageActuelle)
    {
    case 0:
      pagePrincipale();

      break;
    case 1:
      pageReseau();

      break;
    }
  }
}
