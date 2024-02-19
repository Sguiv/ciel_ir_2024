# Presentation de mes programmes en C.

## Premier programme 

### Consigne du programme 

Ecrire un programme qui demande a l'utilisateur de saisir un entier X et qui affiche la valeur absolue de X

### Code

```c

#include <stdio.h>

int main() {
    // Déclarer une variable pour stocker l'entier
    int x;

    // Demander à l'utilisateur de saisir un entier
    printf("Veuillez saisir un entier X : ");
    scanf("%d", &x);

    // Calculer la valeur absolue de X
    int valeurAbsolue = (x < 0) ? -x : x;

    // Afficher le résultat
    printf("La valeur absolue de %d est : %d\n", x, valeurAbsolue);

    return 0;
}
```

## Deuxieme Exercice 

### Consigne du Programme 

Écrivez un programme pour trouver un maximum entre trois nombres en utilisant une structure if-else ou des if imbriqués.

### Codes

```c
#include <stdio.h>

int main() {
    // Déclarer trois variables pour stocker les nombres
    int a, b, c;

    // Demander à l'utilisateur de saisir trois nombres
    printf("Veuillez saisir trois nombres séparés par des espaces : ");
    scanf("%d %d %d", &a, &b, &c);

    // Utiliser des structures if-else imbriquées pour trouver le maximum
    if (a >= b && a >= c) {
        printf("Le maximum est : %d\n", a);
    } else if (b >= a && b >= c) {
        printf("Le maximum est : %d\n", b);
    } else {
        printf("Le maximum est : %d\n", c);
    }

    return 0;
}
```

## Troisiéme exercice 

### Consigne du Programme

Faire un menu à l'aide des instructions switch case :

Taper A pour saisir votre Age
Taper N pour saisir votre Nom
Taper P pour saisir votre Prenom
Le programme doit indiquer à l'utilisateur si il a tapé une lettre non autorisée. Quand les 3 informations ont été saisies (peu importe l'ordre de saisie), le programme affiche :

Bonjour 'Prenom', 'nom', suivi de :
Vous êtes mineur en France et aux états unis si l'utilisateur a moins de 18ans.
Vous êtes majeur en France mais pas aux états-unis si l'utilisateur a entre 18 et 20 ans.
Vous êtes majeur en France et aux états-unis si l'utilisateur a plus de 20 ans.

### Codes 

```c
#include <stdio.h>

int main() {
    char choix;

    printf("Taper A pour saisir votre Age\n");
    printf("Taper N pour saisir votre Nom\n");
    printf("Taper P pour saisir votre Prenom\n");

    printf("Choix : ");
    scanf(" %c", &choix);  // Notez l'espace avant %c pour ignorer les caractères blancs (espaces, retours à la ligne, etc.)

    switch (choix) {
        case 'A':
        case 'a':
            {
                int age;
                printf("Saisir votre Age : ");
                scanf("%d", &age);
                printf("Vous avez saisi l'âge : %d\n", age);
            }
            break;
        case 'N':
        case 'n':
            {
                char nom[50];
                printf("Saisir votre Nom : ");
                scanf("%s", nom);
                printf("Vous avez saisi le nom : %s\n", nom);
            }
            break;
        case 'P':
        case 'p':
            {
                char prenom[50];
                printf("Saisir votre Prenom : ");
                scanf("%s", prenom);
                printf("Vous avez saisi le prenom : %s\n", prenom);
            }
            break;
        default:
            printf("Choix invalide.\n");
    }

    return 0;
}
```

### Quatriéme Exercice

### Consigne du programme 
Reprendre l'exercice 3 (Exercice sur les switch/case) et rajouter :

Une boucle while qui s'arrête si l'utilisateur tape 'Q' ou 'q'

### Codes 

```c
#include <stdio.h>

int main() {
    char choix;

    while (1) {
        printf("Taper A pour saisir votre Age\n");
        printf("Taper N pour saisir votre Nom\n");
        printf("Taper P pour saisir votre Prenom\n");
        printf("Taper Q pour quitter\n");

        printf("Choix : ");
        scanf(" %c", &choix);

        switch (choix) {
            case 'A':
            case 'a':
                {
                    int age;
                    printf("Saisir votre Age : ");
                    scanf("%d", &age);
                    printf("Vous avez saisi l'âge : %d\n", age);
                }
                break;
            case 'N':
            case 'n':
                {
                    char nom[50];
                    printf("Saisir votre Nom : ");
                    scanf("%s", nom);
                    printf("Vous avez saisi le nom : %s\n", nom);
                }
                break;
            case 'P':
            case 'p':
                {
                    char prenom[50];
                    printf("Saisir votre Prenom : ");
                    scanf("%s", prenom);
                    printf("Vous avez saisi le prenom : %s\n", prenom);
                }
                break;
            case 'Q':
            case 'q':
                printf("Programme terminé.\n");
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}
```

## Cinquiéme Exercie 

### Consigne du programme
En utilisant une boucle for, réaliser le programme fonctionnant ainsi :

Taper un nombre '6'
Taper une puissance '4'
Le résultat de '6' à la puissance '4' est 1296

### Codes

```c
#include <stdio.h>

int main() {
    int nombre, puissance;
    long long resultat = 1; // Utilisation de long long pour éviter les dépassements en cas de résultat important

    // Saisir le nombre et la puissance
    printf("Taper un nombre : ");
    scanf("%d", &nombre);

    printf("Taper une puissance : ");
    scanf("%d", &puissance);

    // Calculer la puissance à l'aide d'une boucle for
    for (int i = 1; i <= puissance; ++i) {
        resultat *= nombre;
    }

    // Afficher le résultat
    printf("Le résultat de %d à la puissance %d est %lld\n", nombre, puissance, resultat);

    return 0;
}
```

