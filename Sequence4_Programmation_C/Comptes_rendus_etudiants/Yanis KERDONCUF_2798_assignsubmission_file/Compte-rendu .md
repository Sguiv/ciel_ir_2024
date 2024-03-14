# Exercices de la séquence 4

# Exercice 2 de la séquence 4.1

Voici le code que nous utiliserons :
```c
def main():
    nom = input("Votre nom: ")
    prenom = input("Votre prénom: ")
    annee_naissance = int(input("Votre jour de naissance en jj/mm/aaaa: "))
    age = 2024 - annee_naissance

    print("Bonjour très cher {}, {}.".format(prenom, nom))
    print("Vous avez {} ans. Cela est fort exceptionnel !".format(age))
```
Nous définissons nos fonctions, puis à l'aide de print, nous recevrons sur notre écran, la phrase : Bonjour très cher Yanis. Vous avez 19 ans. Cela est fort exceptionnel !

# Exercice 1 de la séquence 4.3
Voici le code que nous utiliserons:
```c
#include <stdio.h>

int main() {
    int x;

    //Ici, il est demandé de renseigner un entier
    printf("Veuillez saisir un entier X : ");
    scanf("%d", &x);
    // scanf permet de lire ce qui a été tapé par l'utilsateur et ainsi la valeur de l'entier sera renvoyée.
}
    //Yanis KERDONCUF
```

Dans cet exemple, int est un entier x. Le meme entier x qui sera réclamé par le programme auprès de l'utilisateur.
Pour cela, la fonction printf s'affichera.
Concernant la fonction scanf, elle lira la valeur tapé par l'utilisateur, valeur qui sera retranscrite dans le terminal.

# Exercice 2 de la séquence 4.3
Voici le code que nous utiliserons :
```c
#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Entrez trois nombres distincts: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2) {
      if (num1 >= num3) {
        printf("Le nombre maximum est: %d\n", num1);
    } else {
        printf("Le nombre maximum est: %d\n", num3);
        }
    } else {
      if (num2 >= num3) {
        printf("Le nombre maximum est: %d\n", num2);
        } else {
        printf("Le nombre maximum est: %d\n", num3);
        }
    }

}
                                //Yanis KERDONCUF
```
Pour expliquer le code, il est demandé comme dans le premier exercice, de renseigner une valeur que scanf lira au programme à la suite.
Ensuite, beaucoup de if..else.
Pour comprendre, si num 1 est supérieur à num 2 et si num 1 est supérieur à num 3, alors le programme renverra la ligne 14:
 ```c
printf("Le nombre maximum est: %d\n", num1);
```
Sinon en suivant la logique que le nombre 1 est plus grand que le nombre 2, et si le nombre 3 est plus grand que le premier, le programme renverra la ligne 16:
 ```c
printf("Le nombre maximum est: %d\n", num3);
```
Meme processus avec le deuxième if...else plus bas dans le programme.

# Exerice 3 et 4 de la séquence 4 - Partie 4
Voici le code que nous utiliserons :
```c
#include <stdio.h>

int main() {
    char choix;
    int age;
    char nom[50];
    char prenom[50];

    int ageLimiteFrance = 18;
    int ageLimiteUSA = 21;

    int saisieAge = 0;
    int saisieNom = 0;
    int saisiePrenom = 0;

    do {
        printf("Taper A pour saisir votre Age\n");
        printf("Taper N pour saisir votre Nom\n");
        printf("Taper P pour saisir votre Prenom\n");
        printf("Taper Q pour quitter\n");

        scanf(" %c", &choix);

        switch (choix) {
            case 'A':
            case 'a':
                printf("Saisir votre Age : ");
                scanf("%d", &age);
                saisieAge = 1;
                break;

            case 'N':
            case 'n':
                printf("Saisir votre Nom : ");
                scanf("%s", nom);
                saisieNom = 1;
                break;

            case 'P':
            case 'p':
                printf("Saisir votre Prenom : ");
                scanf("%s", prenom);
                saisiePrenom = 1;
                break;

            case 'Q':
            case 'q':
                break;

            default:
                printf("Lettre non autorisee. Veuillez entrer A, N, P ou Q.\n");
        }

    } while (choix != 'Q' && (saisieAge + saisieNom + saisiePrenom) < 3);

    if (saisieAge && saisieNom && saisiePrenom) {
        printf("\nBonjour %s %s,\n", prenom, nom);

        if (age < ageLimiteFrance) {
            printf("Vous êtes mineur en France.");
        } else if (age >= ageLimiteFrance && age < ageLimiteUSA) {
            printf("Vous êtes majeur en France mais pas aux États-Unis.");
        } else {
            printf("Vous êtes majeur en France et aux États-Unis.");
        }
    }

    return 0;
}
``````

Pour détailler ce code, nous remarquons la présence de la fonction if else.
Qui permettera d'élaborer les différents scénarios possibles.
On utilisera printf, pour que la machine nous demande de renseigner des valeurs, ou bien des mots.
Comme demandé dans l'exercice 4, nous avons ajouté le scénario, où l'utilisateur appuie sur q et termine l'execution du programme.
```c
case 'Q':
case 'q':
    break;
```
    Nous mettons Q en majuscule ainsi qu'en miniscule pour éviter que si il est en majuscule et que nous avons oublié le Q, le programme ne s'arrete pas.

    # Exerice 5 de la séquence 4 - Partie 4

Voici le code que nous allons utiliser :
```c
#include <stdio.h>

int main() {
int nombre, puissance;
long long resultat = 1;

    printf("Merci de bien vouloir renseigner une nombre: ");
    scanf("%d", &nombre);
    printf("Merci de bien vouloir renseigner une puissance: ");
    scanf("%d", &puissance);

    for (int i = 0; i < puissance; i++) {
        resultat *= nombre;
    }

    printf("En considérant vos valeurs, nous trouvons que le résultat de '%d' à la puissance '%d' est %lld\n", nombre, puissance, resultat);

    return 0;
}
``````
Dans un premier temps, nous déclarons nos variables en int, puis en long long.
Ensuite, nous retrouvons le printf, qui l'on rappelle, permet au programme de nous demander de renseigner une valeur.
Ensuite, à la ligne 16, la valeur i, prend la valeur i++, déclarant cette valeur au carré.
Pour finir, le programme nous renvoie le résultat.

