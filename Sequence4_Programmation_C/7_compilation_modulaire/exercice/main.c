// main.c
#include <stdio.h>
#include "liste_taches.h"
char choix;
int main()
{
    while (choix != 'q')
    {
        printf("Taper\n1-Pour ajouter une tache\n2-Pour afficher les taches\n3-Pour rechercher une tache\n4-Pour supprimer une tache\nq-Pour quitter\n");

        fscanf(stdin, " %c", &choix);
        char tache[100];
        switch (choix)
        {
        case '1':
            printf("Entrer la tache a ajouter\n");
            fflush(stdin);
            fgets(tache, 100, stdin);
            ajouterTache(tache);
            break;
        case '2':
            afficherTaches();
            break;
        case '3':
            printf("Entrer la tache a rechercher\n");
            fflush(stdin);
            fgets(tache, 100, stdin);
            rechercherTache(tache);
            break;
        case '4':
            printf("Entrer la tache a supprimer\n");
            fflush(stdin);
            fgets(tache, 100, stdin);
            supprimerTache(tache);
            break;
        case 'q':
            printf("Au revoir!\n");
            break;
        }
    }
    return 0;
}
