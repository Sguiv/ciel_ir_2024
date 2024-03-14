# Présentation de mes programmes en C.

## Premier programme

### Consigne du programme

Écrire un programme qui demande à l’utilisateur de saisir un entier X et qui affiche la valeur absolue de X.

### Code N°1

```c

#include <stdio.h>

int main() {
    int x;

    printf("Veuillez saisir un entier : ");
    scanf("%d", &x);

    int valeurAbsolue = (x < 0) ? -x : x;

    printf("La valeur absolue de %d est : %d\n", x, valeurAbsolue);

    return 0;
}
```

## Second programme

### Consigne du programme

Écrivez un programme pour trouver un maximum entre trois nombres en utilisant une structure if-else ou des if imbriqués.

### Code N°2

```c

#include <stdio.h>

int main() {
    int a, b, c;
    
    printf("Veuillez saisir trois nombres séparés par des espaces : ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a >= b) {
        if (a >= c) {
            printf("Le maximum est : %d\n", a);
        } else {
            printf("Le maximum est : %d\n", c);
        }
    } else {
        if (b >= c) {
            printf("Le maximum est : %d\n", b);
        } else {
            printf("Le maximum est : %d\n", c);
        }
    }
    
    return 0;
}
```

## Troisième programme 

### Description du programme

```
Faire un menu à l'aide des instructions switch case :

Taper A pour saisir votre Age
Taper N pour saisir votre Nom
Taper P pour saisir votre Prenom
Le programme doit indiquer à l'utilisateur si il a tapé une lettre non autorisée. Quand les 3 informations ont été saisies (peu importe l'ordre de saisie), le programme affiche :

Bonjour 'Prenom', 'nom', suivi de :
Vous êtes mineur en France et aux états unis si l'utilisateur a moins de 18ans.
Vous êtes majeur en France mais pas aux états-unis si l'utilisateur a entre 18 et 20 ans.
Vous êtes majeur en France et aux états-unis si l'utilisateur a plus de 20 ans
```
### Code N°3

```c
#include <stdio.h>

int main() {
    char choix;
    char nom[50], prenom[50];
    int age;

    int age_entre = 0, nom_entre = 0, prenom_entre = 0;

    while (!(age_entre && nom_entre && prenom_entre)) {
        printf("\nTaper A pour saisir votre Age\n");
        printf("Taper N pour saisir votre Nom\n");
        printf("Taper P pour saisir votre Prenom\n");
        printf("Votre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
            case 'A':
            case 'a':
                printf("Saisissez votre âge : ");
                scanf("%d", &age);
                age_entre = 1;
                break;
            case 'N':
            case 'n':
                printf("Saisissez votre nom : ");
                scanf("%s", nom);
                nom_entre = 1;
                break;
            case 'P':
            case 'p':
                printf("Saisissez votre prénom : ");
                scanf("%s", prenom);
                prenom_entre = 1;
                break;
            default:
                printf("Lettre non autorisée ! Veuillez réessayer.\n");
        }
    }

    if (age < 18) {
        printf("\nBonjour %s %s.\nVous êtes mineur en France et aux états unis.\n", prenom, nom);
    } else if (age >= 18 && age <= 20) {
        printf("\nBonjour %s %s.\nVous êtes majeur en France mais pas aux états-unis.\n", prenom, nom);
    } else {
        printf("\nBonjour %s %s.\nVous êtes majeur en France et aux états-unis.\n", prenom, nom);
    }

    return 0;
}
```

## Quatrième programme

### Description de la consigne

Reprendre l'exercice 3 (Exercice sur les switch/case) et rajouter :

- Une boucle while qui s'arrête si l'utilisateur tape 'Q' ou 'q'

### Code N°4

**(Je n'ai mis que la partie ajouté a mon code et non remis tout dans l'entiereté)**

```c
            case 'Q':
            case 'q':
                printf("Vous avez choisi de quitter.\n");
                return 0;
```

## Dernier Programme

### Description de la consigne

En utilisant une boucle for, réaliser le programme fonctionnant ainsi :

``` 
Taper un nombre '6'
Taper une puissance '4'
Le résultat de '6' à la puissance '4' est 1296 
```

### Code N°5

```c
#include <stdio.h>

int main() {
    int base, puissance;
    long long resultat = 1;

    printf("Taper un nombre : ");
    scanf("%d", &base);

    printf("Taper une puissance : ");
    scanf("%d", &puissance);

    for (int i = 0; i < puissance; ++i) {
        resultat *= base;
    }

    printf("Le résultat de %d à la puissance %d est %lld\n", base, puissance, resultat);

    return 0;
}
```

###### Le Dluz Hugo