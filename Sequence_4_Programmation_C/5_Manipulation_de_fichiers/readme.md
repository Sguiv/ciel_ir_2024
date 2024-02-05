# Gestion des fichiers

**L'utilisation des fichiers permet de lire, de traîter et de sauvegarder sur la mémoire de masse (disque dur, carte mémoire, etc.)des données qui doivent être conservées même après l'arrêt de la machine, ce qui n'est pas possible par l'utilisation des variables. Les opérations de gestion de fichiers concernent les traitements courants de lecture et d'écriture mais également de création, de renommage et de suppression. La plupart des fonctions liées à la gestion des fichiers sont définies dans le fichier d'entête `stdio.h` de la bibliothèque standard.**

## Fonctions fopen() et fclose() pour l’ouverture et la fermeture et différents modes d’acces

L'ouverture d'un fichier s'effectue au moyen de la fonction `fopen()`.Son prototype est le suivant :

```c FILE *fopen(const char *fichier, const char *mode);```

Cette fonction renvoie un pointeur sur un type spécifique complexe nommé `FILE`. Il s'agit en fait d'une structure de données définie dans le fichier d'entête.
Le paramètre `fichier` est une chaîne de caractères correspondant au nom du fichier à ouvrir et éventuellement au chemin d'accès complet jusqu'au fichier à ouvrir s'il ne se situe pas dans le répertoire courant.Le paramètre `mode` permet de préciser le mode d'ouverture spécifiant le type d'accès au contenu du fichier. Les principales valeurs sont listées dans le tableau suivant. Elles s'appliquent à un accès en mode texte. C'est-à-dire que le contenu des fichiers est traîté sous forme de caractères et non pas comme une succession d'éléments binaires (0 ou 1). 

| Spécificateur | Signification |
| --------------- | ----------- |
| "R" | Lecture seule |
| "w" | Ecriture seule |
| "a" | Ajout à la fin du fichier (append) |
| "r+" | Lecture et écriture avec suppression préalable du contenu |
| "w+" | Lecture et écriture |
| "a+" | Lecture et ajout à la fin du fichier |

Il existe aussi les spécificateurs "rb", "wb", "ab", "rb+", "wb+" et "ab+". Ils sont destinés à accéder aux fichiers non plus en mode texte mais en mode binaire.

En cas d'échec d'ouverture du fichier, la fonction `fopen()` renvoie la valeur `NULL`. Il convient alors de tester la valeur renvoyée afin de s'assurer que l'ouverture du fichier s'est correctement effectuée.

La fermeture d'un fichier préalablement ouvert par la fonction `fopen()` s'effectue en utilisant la fonction `fclose()` qui ne prend en
paramètre que le nom du pointeur renvoyé lors de l'ouverture du fichier. Le prototype est indiqué ci-dessous :

```c int fclose(FILE *fichier);```

