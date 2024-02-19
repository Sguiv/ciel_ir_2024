# strucutre conditionnelles
## exercise 1 
```c
#include <stdio.h>
int main(void)
{
    int nombre;
    printf("entrer un nombre :");
    scanf("%d", &nombre);
    
    int valeurAbsolue = (nombre < 0) ? -nombre : nombre;
    printf("la valeurs absolue de %d est %d\n", nombre, valeurAbsolue);

    return 0;
}
```
En premier on ouvre une fonction 
Ensuite on initialise la variable int nombre
Puis le printf demande d'entrer un nombre et le programme repond en affichant le nombre donné 
## exercise 2 
```c
int main(void) 
{
    int nombre1 = 0;
    int nombre2 = 0;
    int nombre3 = 0;
    printf("entrer un nombre:");
    scanf("%d", nombre);
    printf("entrer un nombre:");
    scanf("%d", nombre);
    printf("entrer un nombre:");
    scanf("%d", nombre);
    if (nombre1 > nombre2 && nombre1 > nombre3)
    printf("le nombre maximun est %d \n", nombre1);
    else if (nombre1 < nombre2 && nombre2 > nombre3)
    printf("le nombre maximun est %d \n", nombre2);
    if (nombre3 > nombre2 && nombre3 > nombre2)
    printf("le nombre maximun est %d \n", nombre3);
} 
```
EN premeir on ouvre une fonction 
Ensuite on initialise 3 variable int nombre à 0
Puis ls boucles vont regarder un par un quel nombre est le plus grand par rapport aux autre et le printf dira si le nombre le plus grand  
## exercise 3 
```c
int main(void)
{
    char choix;
    int age;
    char nom[50], prenom[50];

    printf("Taper A pour saisir votre Age\n");
    printf("Taper N pour saisir votre Nom\n");
    printf("Taper P pour saisir votre Prenom\n");

    while (1) {
        printf("Votre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
            case 'A':
                printf("Entrez votre Age : ");
                scanf("%d", &age);
                break;

            case 'N':
                printf("Entrez votre Nom : ");
                scanf("%s", nom);
                break;

            case 'P':
                printf("Entrez votre Prenom : ");
                scanf("%s", prenom);
                break;

            default:
                printf("Lettre non autorisée. Veuillez réessayer.\n");
        }

        if (age != 0 && nom[0] != '\0' && prenom[0] != '\0') {
            break;
        }
    }

    printf("Bonjour %s %s,\n", prenom, nom);

    if (age < 18) {
        printf("Vous êtes mineur en France et aux États-Unis.\n");
    } else if (age >= 18 && age <= 20) {
        printf("Vous êtes majeur en France mais pas aux États-Unis.\n");
    } else {
        printf("Vous êtes majeur en France et aux États-Unis.\n");
    }

    return 0;

}
```
Ce programme utilise une boucle do-while pour afficher le menu tant que les trois information nom, prenom, âge ne sont pas saisi 
Une fois toutes les information saisis, il afiche le message approprié en fonction de l'âge en france et aux Etat-Unis
## exercise 4 
```c
int main() {
    char choix;
    int age = 0;
    char nom[50], prenom[50];

    while (1) {
        printf("Taper A pour saisir votre Age\n");
        printf("Taper N pour saisir votre Nom\n");
        printf("Taper P pour saisir votre Prenom\n");
        printf("Taper Q pour quitter\n");

        printf("Votre choix : ");
        scanf(" %c", &choix);

        if (choix == 'Q' || choix == 'q') {
            break; 
        }

        switch (choix) {
            case 'A':
                printf("Entrez votre Age : ");
                scanf("%d", &age);
                break;

            case 'N':
                printf("Entrez votre Nom : ");
                scanf("%s", nom);
                break;

            case 'P':
                printf("Entrez votre Prenom : ");
                scanf("%s", prenom);
                break;

            default:
                printf("Lettre non autorisée. Veuillez réessayer.\n");
        }

        if (age != 0 && nom[0] != '\0' && prenom[0] != '\0') {
            printf("Bonjour %s %s,\n", prenom, nom);

            if (age < 18) {
                printf("Vous êtes mineur en France et aux États-Unis.\n");
            } else if (age >= 18 && age <= 20) {
                printf("Vous êtes majeur en France mais pas aux États-Unis.\n");
            } else {
                printf("Vous êtes majeur en France et aux États-Unis.\n");
            }

            age = 0;
            nom[0] = '\0';
            prenom[0] = '\0';
        }
    }

    return 0;
}
```
pareil que pour l'exercise 3 cepandant cette fois une boucle if a été rajouté en disant que si la lettre Q ou q est tapé le code sa casse et le programmme s'arrête
## exercise 5
```c
int main() {
    int nombre, puissance;
    int resultat = 1; 

    printf("Entrez un nombre : ");
    scanf("%d", &nombre);

    printf("Entrez une puissance : ");
    scanf("%d", &puissance);

    for (int i = 0; i < puissance; i++) {
        resultat *= nombre; 
    }

    printf("Le résultat de %d à la puissance %d est %d\n", nombre, puissance, resultat);

    return 0;
}
```
Ce programme demande a l'utilisateur de saisir un nombre et une puissance 
Ensuite il utilise une boucle for pour calculer le nombre multiplié par lui-même autant de fois que le nombre puissance est actif
Puis le printf va donner le résultat du nombre multiplié par X puissance 