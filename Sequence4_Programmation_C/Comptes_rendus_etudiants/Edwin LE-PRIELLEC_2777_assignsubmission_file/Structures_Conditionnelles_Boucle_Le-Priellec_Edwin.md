# Structures Conditionnelles

## Exercice 1

```c
#include <stdio.h>

int main() {
    int nombre;
    printf("Veuillez saisir un entier X : ");
    scanf("%d", &nombre);

    int valeurAbsolue = (nombre < 0) ? -nombre : nombre;
    printf("La valeur absolue de %d est : %d\n", nombre, valeurAbsolue);

    return 0;
}
```
Ce programme utilise la fonction printf pour afficher un message demandant à l'utilisateur de saisir un entier.

Puis utilise scanf pour lire la valeur saisie par l'utilisateur. 

Ensuite, il calcule la valeur absolue en utilisant l'opérateur ternaire ((nombre < 0) ? -nombre : nombre) et affiche le résultat avec printf.

## Exercice 2

```c
#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Veuillez saisir trois nombres séparés par des espaces : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3) {
        printf("Le maximum est : %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("Le maximum est : %d\n", num2);
    } else {
        printf("Le maximum est : %d\n", num3);
    }

    return 0;
}
```
Ce programme demande à l'utilisateur de saisir trois nombres.

Puis utilise des structures if-else imbriquées pour comparer ces nombres et affiche le maximum. 

Notez que si deux nombres sont égaux et sont les plus grands, le programme ne prend que le premier qu'il a trouvé.

## Exercice 3

```c
#include <stdio.h>

int main() {
    char choix;
    char nom[50], prenom[50];
    int age;
    int ageLimite1 = 18;
    int ageLimite2 = 20;
    int aSaisiNom = 0, aSaisiPrenom = 0, aSaisiAge = 0;
    
    do {
        printf("\n-Taper A pour saisir votre Age\n");
        printf("-Taper N pour saisir votre Nom\n");
        printf("-Taper P pour saisir votre Prenom\n");
        printf("Votre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
            
            case 'A':
                printf("Saisir votre Age : ");
                scanf("%d", &age);
                aSaisiAge = 1;
                break;

            case 'N':
                printf("Saisir votre Nom : ");
                scanf("%s", nom);
                aSaisiNom = 1;
                break;

            case 'P':
                printf("Saisir votre Prenom : ");
                scanf("%s", prenom);
                aSaisiPrenom = 1;
                break;

            default:
                printf("Lettre non autorisée.\n");
        }
    } while (!(aSaisiNom && aSaisiPrenom && aSaisiAge));
    printf("\nBonjour %s, %s.\n", prenom, nom);
    if (age < ageLimite1) {
        printf("Vous êtes mineur en France et aux États-Unis.\n");
    } else if (age >= ageLimite1 && age <= ageLimite2) {
        printf("Vous êtes majeur en France mais pas aux États-Unis.\n");
    } else {
        printf("Vous êtes majeur en France et aux États-Unis.\n");
    }

    return 0;
}
```
Ce programme utilise une boucle do-while pour afficher le menu tant que les trois informations (nom, prénom et âge) n'ont pas été saisies.

Une fois toutes les informations saisies, il affiche le message approprié en fonction de l'âge en France et aux États-Unis.

# Boucle

## Exercice 4

```c
#include <stdio.h>

int main() {
    char choix;
    char nom[50], prenom[50];
    int age;
    int ageLimite1 = 18;
    int ageLimite2 = 20;
    int aSaisiNom = 0, aSaisiPrenom = 0, aSaisiAge = 0;

    while (1) {
        printf("\n-Taper A pour saisir votre Age\n");
        printf("-Taper N pour saisir votre Nom\n");
        printf("-Taper P pour saisir votre Prenom\n");
        printf("-Taper Q pour quitter\n");
        printf("Votre choix : ");
        scanf(" %c", &choix);

        if (choix == 'Q' || choix == 'q') {
            break;
        }

        switch (choix) {

            case 'A':
                printf("Saisir votre Age : ");
                scanf("%d", &age);
                aSaisiAge = 1;
                break;

            case 'N':
                printf("Saisir votre Nom : ");
                scanf("%s", nom);
                aSaisiNom = 1;
                break;

            case 'P':
                printf("Saisir votre Prenom : ");
                scanf("%s", prenom);
                aSaisiPrenom = 1;
                break;

            default:
                printf("Lettre non autorisée.\n");
        }

        if (aSaisiNom && aSaisiPrenom && aSaisiAge) {
            break;
        }
    }

    printf("\nBonjour %s, %s.\n", prenom, nom);

    if (aSaisiAge) {
        if (age < ageLimite1) {
            printf("Vous êtes mineur en France et aux États-Unis.\n");
        } else if (age >= ageLimite1 && age <= ageLimite2) {
            printf("Vous êtes majeur en France mais pas aux États-Unis.\n");
        } else {
            printf("Vous êtes majeur en France et aux États-Unis.\n");
        }
    }

    return 0;
}
```
Cette version du programme continuera de demander à l'utilisateur de saisir des informations jusqu'à ce qu'il tape 'Q' ou 'q' pour quitter. 

La boucle principale vérifie également si toutes les informations ont été saisies avant de quitter.

## Ecercice 5
```c
#include <stdio.h>

int main() {

    int base, puissance;
    long long resultat = 1;

    printf("Taper un nombre : ");
    scanf("%d", &base);

    printf("Taper une puissance : ");
    scanf("%d", &puissance);

    for (int i = 0; i < puissance; i++) {
        resultat *= base;
    }

    printf("Le résultat de %d à la puissance %d est %lld\n", base, puissance, resultat);

    return 0;
}
```
Ce programme demande à l'utilisateur de saisir un nombre (la base) et une puissance.

Ensuite, il utilise une boucle for pour multiplier le nombre par lui-même autant de fois que spécifié par la puissance.

Enfin, il affiche le résultat.

Notez que le résultat est de type long long pour gérer de grandes puissances.