/**
 * @file Programme de l'evaluation seq1 et seq2 à completer en fonction des consignes de la grille d'évaluation et des commentaires.
 */
#include <Arduino.h>
#include <M5StickCPlus.h>

#define distance_trajet_travail 2.3 // Constante correspondant au nombre de Km d'un trajet Domicile/Travail (Utilisée pour le calcul de distance parcourue)

unsigned int heures = 0;
unsigned int minutes = 0;
unsigned int secondes = 0;

unsigned int trajet_minutes = 0;
unsigned int trajet_secondes = 0;

unsigned long dernier_millis = millis();
unsigned long millis_depart_trajet = 0;
// Page courante = 0 -> Page principale
// Page courante = 1 -> Page stats
unsigned int page_courante = 0;
bool trajet_en_cours = false;

unsigned int dernier_trajet_minutes = 0;  // Permet de stocker pour affichage le dernier temps de trajet
unsigned int dernier_trajet_secondes = 0; // Idem
unsigned int moyenne_temps_trajet = 0;    // Permet de stocker la moyenne des temps de trajet en secondes
// A FAIRE : Déclarer et initialiser ici une variable permettant de stocker le nombre de trajets à vélo effectués

// A FAIRE : Déclarer et initialiser ici une variable permettant de stocker le nombre de Km parcourus avec une précision de 100m

static uint8_t conv2d(const char *p);

void miseAJourTemps();
void pagePrincipale();
void pageStats();


uint8_t hh = conv2d(__TIME__);
uint8_t mm = conv2d(__TIME__ + 3);
uint8_t ss = conv2d(__TIME__ + 6); // Récuperation de hh,mm et ss depuis l'heure de compilation
RTC_TimeTypeDef time_struct;
RTC_DateTypeDef date_struct;

void setup()
{

  M5.begin();             // Initialisation du M5
  Serial.begin(115200);
  time_struct.Hours = hh; // Recupération de l'heure/minute/seconde de compilation pour mettre le M5 à l'heure
  time_struct.Minutes = mm;
  time_struct.Seconds = ss;

  M5.Rtc.SetTime(&time_struct); // Initialisation de l'horloge temps réeel

  M5.Lcd.fillScreen(BLACK); // Ecran noir
  M5.Lcd.setRotation(3);    // Rotation de l'écran en mode paysage
  M5.Lcd.setTextFont(2);
}

void loop()
{

  M5.update(); // Cette fonction lit l'état des boutons BtnA et BtnB à chaque tour de boucle (obligatoire pour M5.BtnA.isPressed() fonctionne)

  // Si un trajet est en cours on appelle la fonction miseAJourTemps pour actualiser le temps de trajet
  if (trajet_en_cours == true)
  {
    miseAJourTemps();
  }

  // Si la page courante est la page principale, on actualise toutes les secondes l'affichage.
  if (page_courante == 0)
  {
    if (millis() > dernier_millis + 1000)
    {
      dernier_millis = millis();
      pagePrincipale();
    }
  }

  // Si le Bouton A (Bouton M5) est appuyé, l'action a effectuer dépend de la page courante (Principale ou Stats)
  if (M5.BtnA.isPressed())
  {
    delay(500); // Permet d'éviter que le programme voit un appui comme plusieurs appuis

    // Si la page courante est la page principale
    if (page_courante == 0)
    {
      // Et qu'il n'y a pas de trajet en cours, on démarre un trajet
      if (trajet_en_cours == false)
      {
        trajet_en_cours = true;
        // A FAIRE : Incrémenter ici votre variable nb_trajets_velo
        millis_depart_trajet = millis(); // On enregistre le millis() de départ du trajet afin de pouvoir mesurer le temps de trajet
      }
      // Sinon si il y avait un trajet en cours
      else
      {
        trajet_en_cours = false; // On place trajet en cours à 0 pour indiquer la fin d'un trajet
        // A FAIRE : Enregister ici le temps du dernier trajet
        // A FAIRE : Mettre à jour la moyenne des trajets
      }
    }
    // Si le Bouton A est appuyé et que la page courante est la page stats alors cela signifie que l'utilisateur à appuyé sur Reset
    else if (page_courante == 1)
    {
      // Un reset n'est possible que si il n'y a pas de trajet en cours (Sinon, il y a division par 0 à la fin du trajet lors du calcul de la moyenne)
      // A Faire : Completer le if pour qu'on ne rentre dans le test que si un trajet est en cours.
      //(Retirer le commentaire ligne suivante )
      /*if ()
      {
        // A FAIRE Remettre à 0 toutes les données (Moyenne, nombre de trajet, dernier trajet,km)
        // A FAIRE Une fois toutes les données remises à 0 Rappeler la fonction pageStats pour actualiser l'affichage
      }
      else // Si un trajet est en cours, on indique un message d'erreur
      {
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setTextColor(RED);

        M5.Lcd.setCursor(40, 57);
        M5.Lcd.print("Impossible trajet en cours");
        delay(1500);
        pageStats();
      }
      //Retirer le commentaire ligne suivante
      */
    }
  } // Fin si BtnA est pressé

  // Si Btn B est pressé
  else if (M5.BtnB.isPressed())
  {
    delay(500);
    // Et que la page courante est la page principale alors on ouvre la page stats
    if (page_courante == 0)
    {
      // A Faire : Appeler la fonction permettant d'afficher la page Stats
      // Indiquer que la page courante est maintenant la page 1
    }
    // Sinon cela signifie que l'on était sur la page Stats, on revient à la page principale
    else if (page_courante == 1)
    {
      // A Faire : Indiquer que la page courante est la page 0
    }
  } // Fin si BtnB est pressé
}
/**
 * @brief Mets à jour trajet_minutes et trajet_secondes en fonction de millis et millis_depart_trajet
 * (Rien a modifier dans cette fonction)
*/
void miseAJourTemps()
{
  trajet_secondes = ((millis() - millis_depart_trajet) / 1000) - (trajet_minutes * 60);
  if (trajet_secondes == 60)
  {
    trajet_minutes++;
    trajet_secondes = 0;
  }
}

void pageStats()
{

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.fillTriangle(3, 63, 10, 59, 10, 68, ORANGE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setCursor(14, 55);
  M5.Lcd.setTextColor(ORANGE);
  M5.Lcd.printf("Reset");

  M5.Lcd.setCursor(110, 108);
  M5.Lcd.printf("Retour");
  M5.Lcd.fillTriangle(119, 124, 125, 131, 130, 124, ORANGE);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(52, 15);
  M5.Lcd.setTextSize(1);
  // A FAIRE : Calculer et Afficher les informations comme indiquées sur le Figma
  //  Nb de trajets
  //  Km parcourus : Nb de trajet x distance_trajet_travail
  //  Nb Jour vélo : Nb trajet divisé par 2 (1 jour = 1 Aller et 1 Retour)
  //  Dernier trajet : Temps du dernier trajet au format mm:ss
  //  Moyenne tps trajet : Moyenne calculée de tous les temps de trajet
}

void pagePrincipale()
{

  M5.Rtc.GetTime(&time_struct);
  M5.Lcd.fillScreen(BLACK);
  //  A Faire : Réaliser l'interface comme sur Figma (Texte et petits triangles)

  // En fonction de trajet_en_cours (oui ou non) l'affichage est différent
  // Si il n'y a pas de trajet en cours, on indique juste "Nvx trajet travail"
  M5.Lcd.setTextColor(ORANGE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(110, 108);
  M5.Lcd.printf("Stats");
  M5.Lcd.fillTriangle(119, 124, 125, 131, 130, 124, ORANGE);
  if (trajet_en_cours == false)
  {

    // A Faire Afficher le texte "Nvx Trajet Travail"
  }
  else // Sinon si il y a un trajet en cours on affiche "Fin trajet" et le temps de trajet
  {
    // A faire Afficher le texte "Fin trajet"
    // Afficher trajet_minutes et trajet_secondes comme sur le figma
  }
}

/**
 * @brief Converti l'heure de compilation pour pouvoir configurer l'heure système (ne pas toucher!)
 **/
static uint8_t conv2d(const char *p)
{
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}
