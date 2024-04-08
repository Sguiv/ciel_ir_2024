// liste_taches.c
#include <stdio.h>
#include <string.h>
#include "liste_taches.h"

#define MAX_TACHES 100
char taches[MAX_TACHES][100];
int nombreTaches = 0;

void ajouterTache(const char* tache) {
    if (nombreTaches < MAX_TACHES) {
        strcpy(taches[nombreTaches], tache);
        nombreTaches++;
        printf("Tache ajoutee : %s\n", tache);
    } else {
        printf("La liste des taches est pleine.\n");
    }
}

void supprimerTache(const char* tache) {
    int trouve = 0;
    for (int i = 0; i < nombreTaches; ++i) {
        if (strcmp(taches[i], tache) == 0) {
            trouve = 1;
            printf("Tache supprimee : %s\n", taches[i]);
            for (int j = i; j < nombreTaches - 1; ++j) {
                strcpy(taches[j], taches[j + 1]);
            }
            nombreTaches--;
            break;
        }
    }
    if (!trouve) {
        printf("Tache non trouvee.\n");
    }
}

void afficherTaches() {
    if (nombreTaches == 0) {
        printf("La liste des taches est vide.\n");
    } else {
        printf("Liste des taches :\n");
        for (int i = 0; i < nombreTaches; ++i) {
            printf("%d. %s\n", i + 1, taches[i]);
        }
    }
}

void rechercherTache(const char* tache) {
    int trouve = 0;
    for (int i = 0; i < nombreTaches; ++i) {
        if (strcmp(taches[i], tache) == 0) {
            trouve = 1;
            printf("Tache trouvee a la position %d.\n", i + 1);
            break;
        }
    }
    if (!trouve) {
        printf("Tache non trouvee.\n");
    }
}
