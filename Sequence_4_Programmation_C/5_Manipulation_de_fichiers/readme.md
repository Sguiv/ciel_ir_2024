# Gestion des fichiers

**L'utilisation des fichiers permet de lire, de traîter et de sauvegarder sur la mémoire de masse (disque dur, carte mémoire, etc.)des données qui doivent être conservées même après l'arrêt de la machine, ce qui n'est pas possible par l'utilisation des variables. Les opérations de gestion de fichiers concernent les traitements courants de lecture et d'écriture mais également de création, de renommage et de suppression. La plupart des fonctions liées à la gestion des fichiers sont définies dans le fichier d'entête `stdio.h` de la bibliothèque standard.**

## Fonctions fopen() et fclose() pour l’ouverture et la fermeture et différents modes d’acces

L'ouverture d'un fichier s'effectue au moyen de la fonction `fopen()`.Son prototype est le suivant :

`FILE *fopen(const char *fichier, const char *mode);`

Cette fonction renvoie un pointeur sur un type spécifique complexe nommé `FILE`. Il s'agit en fait d'une structure de données définie dans le fichier d'entête.
Le paramètre `fichier` est une chaîne de caractères correspondant au nom du fichier à ouvrir et éventuellement au chemin d'accès complet jusqu'au fichier à ouvrir s'il ne se situe pas dans le répertoire courant.Le paramètre `mode` permet de préciser le mode d'ouverture spécifiant le type d'accès au contenu du fichier. Les principales valeurs sont listées dans le tableau suivant. Elles s'appliquent à un accès en mode texte. C'est-à-dire que le contenu des fichiers est traîté sous forme de caractères et non pas comme une succession d'éléments binaires (0 ou 1). 

|