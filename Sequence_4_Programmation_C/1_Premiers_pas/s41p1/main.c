#include <stdio.h>
/* Définition de macro   et de constante     */  
#define MSG() printf("Début...\n")
#define NB 9

/* Fonction principale */
int main(void)
{
  MSG();
  printf("Valeur : %d\n", NB);
  
  return 0;
}
