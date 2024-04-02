# Compilation modulaire et séparée
## Fondements du langage C

La compilation modulaire et séparée représente un aspect essentiel du langage C. Elle est couramment mise en œuvre lorsque le logiciel à produire atteint une certaine taille ou complexité et qu'il est judicieux de segmenter le code source qui est ainsi réparti sur plusieurs modules constitués de fichiers source (.c). La compilation est alors effectuée en plusieurs étapes. Les exemples présentés sont compilés à l'aide du compilateur GCC.

## Exposé des différentes étapes de compilation
Dès lors que l'ensemble du programme source est distribué sur plusieurs fichiers source, il est d'abord nécessaire de traiter chacun de ces fichiers indépendamment. Cette opération de compilation séparée consiste à générer un fichier objet (.o) à partir de chacun des fichiers source (.c). Elle s'effectue de la façon suivante en utilisant l'option -c de la commande gcc:
```
gcc [-Wall] -c <fichier>.c
```
À l'issue de la compilation séparée, il doit donc exister un fichier objet pour chacun des fichiers source. Un fichier objet est le résultat d'une étape intermédiaire dans le processus de compilation. Il est au format binaire mais il n'est pas directement exécutable et constitue uniquement une portion de code intégrable dans le fichier binaire exécutable à produire.

La seconde étape permet de générer le fichier binaire exécutable à partir de l'ensemble des fichiers objet préalablement produits. La commande générique est présentée ci-dessous:
```
gcc <fichier1>.o ... <fichiern>.o -o <binaire>
```
Le nombre de fichiers objet passés en paramètres de la commande gcc peut être important si la segmentation du code source l'impose.

## Interfaçage par des fichiers d'entête
En langage C, les fichiers d'entête portent l'extension .h. De manière générale, un fichier d'entête contient les prototypes des fonctions implémentées dans le fichier .c correspondant. Dans le contexte de la compilation modulaire et séparée, ils assurent une fonction d'interface entre les fichiers source. Un fichier d'entête doit alors être inclus dans un fichier source si un appel à une fonction définie dans un autre fichier source est effectué. Dans ce cas, l'inclusion se fait de la façon suivante:
```
#include "<fichier>.h"
```
Le placement entre parenthèses signifie que le fichier d'entête est accessible par un chemin relatif par rapport à la position du fichier source appelant dans l'arborescence du système de fichiers. Ainsi, si le fichier d'entête est placé dans un sous-répertoire, la déclaration d'inclusion est la suivante:
```
#include "<répertoire>/<fichier>.h"
```

Un fichier d'entête peut également contenir la déclaration de variables, de structures, de types de données, de constantes ou encore de macro-instructions. De façon rigoureuse, il intègre des directives pré-processeur destinées à limiter les inclusions multiples en cas de déclaration dans plusieurs fichiers source .c. Ces directives sont #ifndef, #define situées au début du fichier et #endif placée à la fin du fichier.

## Programme de démonstration
Le code source présenté ci-dessous montre un exemple d'exploitation de programme réparti sur deux fichiers source .c. Un fichier d'entête permettant l'interfaçage entre ces deux fichiers est également utilisé.

Le premier fichier source est nommé main.c et contient la fonction main(). Son code source est présenté ci-dessous:
```c
/* ============== */
/* Fichier main.c */
/* ============== */
#include <stdio.h>
#include <stdlib.h>
#include "calcul.h"
int main(int argc, char *argv[])
{
    double resultat;
    if (argc < 3)
        printf("Nombre d'arguments insuffisant!\n");
    else
    {
        resultat = aire(atol(argv[1]), atol(argv[2]));
        printf("Aire: %lf\n", resultat);
    }
    return 0;
}
```
L'inclusion du fichier d'entête calcul.h, situé dans le même répertoire que le fichier main.c, est effectuée par l'instruction suivante:
```c
#include "calcul.h"
```

Le fichier d'entête calcul.h contient la déclaration du prototype de la fonction de calcul d'aire nommée aire(). Son code est présenté ci-dessous:
```c
/* ========================= */
/* Fichier d'entête calcul.h */
/* ========================= */
#ifndef CALCUL_H
#define CALCUL_H
double aire(double cote1, double cote2);
#endif /* CALCUL_H */
```
La fonction aire() est définie dans le fichier source calcul.c dont le code est présenté ci-dessous:
```c
/* ================ */
/* Fichier calcul.c */
/* ================ */
double aire(double cote1, double cote2)
{
    return cote1 * cote2;
}
```
Le lien entre la fonction aire() appelée à partir du fichier main.c et sa définition dans le fichier calcul.c est réalisé par l'inclusion du fichier d'entête calcul.h. La correspondance entre les fichiers calcul.c et calcul.h est implicitement effectuée par le compilateur.

## Compilation du programme de démonstration

La compilation débute par la génération des fichiers objet `main.o` et `calcul.o` à partir des fichiers source `main.c` et `calcul.c`. Les commandes sont alors les suivantes:
```
gcc -Wall -c calcul.c
gcc -Wall -c main.c
```
L'édition de liens effectuée dans un second temps est réalisée par la commande ci-dessous:
```
gcc main.o calcul.o -o monprog
```
Le fichier d'entête `calcul.h` n'est jamais passé en paramètre d'une commande de compilation. Il sert uniquement d'interface de déclaration de la fonction `aire()` dont la définition est effectuée dans le fichier `calcul.c`.

## Intégration d'un greffon à un programme

Il arrive que des fichiers objet soient fournis par un tiers afin d'être pris en compte et intégrés à des programmes. C'est le cas lorsque le programme à développer s'appuie sur des fonctions, des traitements, des variables, des structures de données ou des constantes dont l'implémentation est effective au sein d'un greffon (plugin) préalablement compilé.

La commande ci-dessous montre un exemple des étapes de compilation d'un programme uniquement basé sur un fichier source main.c et sur un greffon greffon.o fourni:
```
gcc -Wall -c main.c
gcc main.o greffon.o -o monprog
```
Cette façon de procéder concerne essentiellement le cadre de réutilisation dans différents programmes de composants logiciels, appelés briques logicielles. Il s'agit alors de mutualiser une partie du développement ou de conserver la confidentialité de l'implémentation des fonctions et des traitements assurés par le greffon.

Bien évidemment, si le code source du greffon n'est pas disponible, une documentation doit renseigner quant à la déclaration des fonctions, traitements, variables, structures de données et constantes accessibles et implémentées dans le code source du greffon.

## Projet : Gestionnaire de listes de tâches

### Objectif
Créer un programme de gestion de listes de tâches qui permet d'ajouter, supprimer, afficher et rechercher des tâches.

### Structure du projet
- `main.c` : contient la fonction `main()` qui interagit avec les fonctions de la bibliothèque.
- `liste_taches.h` : en-tête de la bibliothèque contenant les prototypes des fonctions de gestion des listes de tâches.
- `liste_taches.c` : implémentation des fonctions de gestion des listes de tâches.

### Fonctions de gestion des listes de tâches
- `ajouterTache(const char* tache)` : ajoute une nouvelle tâche à la liste.
- `supprimerTache(const char* tache)` : supprime une tâche de la liste.
- `afficherTaches()` : affiche toutes les tâches de la liste.
- `rechercherTache(const char* tache)` : recherche une tâche dans la liste.

### Étapes de réalisation
1. Déclarez les prototypes des fonctions de gestion des listes de tâches dans `liste_taches.h`.
2. Implémentez les fonctions dans `liste_taches.c`.
3. Dans `main.c`, incluez `liste_taches.h` et utilisez les fonctions de la bibliothèque pour interagir avec la liste de tâches.

### Compilation
- Compilez `liste_taches.c` séparément pour créer la bibliothèque.
- Compilez `main.c` en incluant la bibliothèque créée à l'étape précédente.
- Liez les deux fichiers objet pour créer l'exécutable final.

### Utilisation
- L'utilisateur peut exécuter le programme et choisir parmi différentes options pour ajouter, supprimer, afficher ou rechercher des tâches.
- Le programme utilise les fonctions de la bibliothèque pour effectuer les opérations demandées sur la liste de tâches.
