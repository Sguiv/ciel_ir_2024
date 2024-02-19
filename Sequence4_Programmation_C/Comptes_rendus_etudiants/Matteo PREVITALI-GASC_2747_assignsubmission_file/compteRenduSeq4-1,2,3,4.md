# Séquence 4 - Compte rendu des exercices concernant les structures conditionnelles et les boucles 

## Séquence 4 - 1 : Premiers pas

```c
#include <stdio.h>

/* Fonction principale */
int main(void)
{
	int nb = 4;

	printf("Valeur : %d\n", nb);
	nb++; /* Incrémentation */
	printf("Valeur : %d\n", nb);
 
	return 0;
}
```

J'initialise ma variable *nb* de type **int** à 4.

Puis je l'affiche, l'incrémente et affiche la valeur de la variable après incrémentation.

## Séquence 4 - 2 : Saisie clavier

```c
#include <stdio.h>
#include <string.h>
/* Fonction principale */
int main(void)
{
	char prenom[50];
	char nom[50];
	unsigned int annee = 0;

	printf("Entrez votre prenom : ");
	fgets(prenom,50,stdin);
	if (prenom[strlen(prenom)-1] =='\n'){
		prenom[strlen(prenom)-1] = 0;
	}
	printf("Entrez votre nom : ");
	fgets(nom,50,stdin);
	if (nom[strlen(nom)-1] =='\n'){
		nom[strlen(nom)-1] = 0;
	}
	printf("Entrez votre annee de naissance au format yyyy : ");
	scanf("%u",&annee);

	printf("Vous vous appelez %s %s et vous avez %u ans\n", prenom, nom, 2024-annee);


}
```

J'initialise les variables *prenom*, *nom* et *annee*, respectivement de type **char[50]**, **char[50]** et **unsigned int**

Je demande ensuite à l'utilisateur de saisir leurs valeurs grâce à un **fgets** 

Enfin j'affiche un message de bienvenue contenant le *nom*, le *prenom* et l'*annee* grâce à un **printf**

## Séquence 4 - 3 : Structures conditionnelles

### s43ex1 :

```c
#include <stdio.h>

int main(void){
	int nb = 0;
	printf("Saisissez un nombre : ");
	scanf("%d",&nb);

	if (nb < 0){
		nb = nb*-1;
	}
	printf("Voici la valeur absolue de votre nombre : %d\n", nb);
}
```

On utilise la fonction scanf pour récupérer le nombre (de type int) que l'utilisateur saisi.

Grâce à une condition je le multiplie par -1 s'il est négatif.

Finalement j'affiche ce nombre sur la console.

### s43ex2 :

```c
 #include <stdio.h>

int main(void){
	int nb[] = {0,0,0};
	int max  = -1;
	printf("Saisissez la valeur du premier nombre : ");
	scanf("%d %d %d",&nb[0], &nb[1], &nb[2]);

	if (nb[0] > nb[1] && nb[0] > nb[2]){
		max = nb[0];
	}else if (nb[1] > nb[0] && nb[1] > nb[2]){
		max = nb[1];
	}else{
		max = nb[2];
	}
	printf("Le plus grand nombre de ces trois est %d\n", max);

}
```

On initialise un tableau de 3 nombres (**int**) à 0 et un nombre (**int**) *max* à 0.

Grâce à un scanf je demande à l'utilisateur de saisir trois nombres.

À l'aide d'une structure if...else if...else... je mets la plus grande des trois valeurs dans la variable *max* puis je l'affiche à l'utilisateur.

### s43ex3 :
<a name="s43ex3"></a>

```c
#include <stdio.h>

int main (void){
	unsigned short age_saisi = 0;
	unsigned short prenom_saisi = 0;
	unsigned short nom_saisi = 0;
	char nom[20];
	char prenom[20];
	unsigned short age = 0;
	char saisie = 'X';
	while (age_saisi == 0 || prenom_saisi == 0 || nom_saisi == 0){
		fflush(stdin);
		saisie=0;
		printf("Operation a effectuer : ");
		scanf ("%c", &saisie);
		printf("Debug saisie:%c\n",saisie);
		switch(saisie){
			case 'A':
				printf("Votre age : ");
				scanf("%hd", &age);
				age_saisi = 1;
				break;

			case 'N':
				printf("Votre nom : ");
				scanf("%s", nom);
				nom_saisi = 1;
				break;

			case 'P':
				printf("Votre prenom : ");
                                scanf("%s", prenom);
                                prenom_saisi = 1;
                                break;
			default :
				printf("Lettre non autorisée !\n");
				break;

		}

	}
	printf("Bonjour %s %s\n", nom, prenom);
	if (age<18){
		printf("Vous etes mineur aux USA et en France\n");
	}
	else if (age < 21){
		printf("Vous etes mineur aux USA\n");
	}
	else{
		printf("Vous etes majeur partout !\n");
	}
}
```

Tout d'abord j'initialise trois variables *age_saisi*, *prenom_saisi* et *nom_saisi* de type **unsigned short** à 0. Elles serviront à mon programme à savoir si les valeurs de *age*, *nom* et *prenom* ont déjà été saisies ou pas. Ensuite j'initialise les variables *prenom* et *nom* qui sont des tableau de 20 caractères (**char[20]**) et une variable *age* de type **int**. Enfin j'initialise une variable *saisie* de type **char**.

Je rentre dans une boucle **while** qui s'exécutera tant que les valeurs de *nom*, *prenom* et *age* n'auront pas été saisies (grâce aux variables initialisées précédemment).
On demande d'abord quelle opération nous souhaitons effectuer : Saisir le prénom (P), saisir le nom (N) et saisir l'âge (A).
Un **switch case** permet d'effectuer la saisie demandée et de mettre à 1 la variable attestant la saisie des variable (*nom_saisi*, *prenom_saisi*...)

Une fois la boucle **while** terminée on dira bonjour à l'utilisateur et lui dirai s'il est majeur au Etats-Unis (+ de 21ans), en France (+ de 18 ans) ou aucun des deux (- 18 ans).

## Séquence 4 - 4 : Boucles

### s44ex4 :

```c
#include <stdio.h>

int main (void){
	unsigned short age_saisi = 0;
	unsigned short prenom_saisi = 0;
	unsigned short nom_saisi = 0;
	unsigned short fin = 0;
	char nom[20] = "X";
	char prenom[20] = "X";
	unsigned short age = -1;
	char saisie = 'X';

	while ((age_saisi == 0 || prenom_saisi == 0 || nom_saisi == 0) && fin == 0){
		fflush(stdin);
		saisie=0;
		printf("Operation a effectuer : ");
		scanf ("%c", &saisie);
		printf("Debug saisie:%c\n",saisie);
		switch(saisie){
			case 'A':
				printf("Votre age : ");
				scanf("%hd", &age);
				age_saisi = 1;
				break;

			case 'N':
				printf("Votre nom : ");
				scanf("%s", nom);
				nom_saisi = 1;
				break;

			case 'P':
				printf("Votre prenom : ");
                                scanf("%s", prenom);
                                prenom_saisi = 1;
                                break;
			case 'Q':
			case 'q':
				fin = 1;
				break;
			default :
				printf("Lettre non autorisée !\n");
				break;

		}

	}
	if (age_saisi == 1 && nom_saisi == 1 && prenom_saisi == 1){
		printf("Bonjour %s %s\n", nom, prenom);
		if (age<18){
			printf("Vous etes mineur aux USA et en France\n");
		}
		else if (age < 21){
			printf("Vous etes mineur aux USA\n");
		}
		else{
			printf("Vous etes majeur partout !\n");
		}
	}
}
```

On retrouve les mêmes éléments que dans le [***s43ex3***](#s43ex3).

On a ajouté une variable *fin* de type **unsigned short** initialisée à 0 qui permettra d'arrêter la boucle **while** en la passant à 1.
Dans le **switch case**, désormais, si la lettre saisie est un *q* ou un *Q* la variable *fin* passe à 1 et l'exécution s'arrête.

L'affichage du message de fin est désormais conditionné à la saisie du nom, du prénom et de l'âge. Avant, il suffisait de sortie de la boucle **while**.

### s44ex5 :

```c
#include <stdio.h>

int main(){
	int nb = 0;
	int puissance = 0;
	int res = 1;

	printf("Tapez un nombre : ");
	scanf("%d",&nb);

	printf("Tapez un exposant : ");
	scanf("%d", &puissance);

	for (int i = 0; i<puissance; i++){
		res *= nb;
	}
	printf("%d exposant %d donne le résultat %d\n", nb, puissance, res);
}

```

Premièrement j'initialise mes variable *nb*, *puissance* et *res* de type **int** qui stockeront respectivement le nombre, son exposant et le resultat du calcule.

On demande ensuite à l'utilisateur de taper le nombre et son exposant au clavier.

Puis on calcule le résultat à l'aide d'une **boucle for** et à la fin on l'affiche.

