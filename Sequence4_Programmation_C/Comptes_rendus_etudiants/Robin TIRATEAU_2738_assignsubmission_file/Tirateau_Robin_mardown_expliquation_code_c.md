# Présentation des Programmes en Langage C

## Code n°1 : valeur absolue d'un nombre

### Description
Ce programme donne la valeur absolue d'un nombre, en vérifiant via une fonction "if" si le nombre est négatif, et si c'est le cas on le multiplie par - puis on affiche le résultat suivit d'un retour a la ligne.

### Code :
```c
#include <stdio.h>

int main(){

int nombre;

printf("Entrez un nombre : ");
scanf("%d", &nombre);

if (nombre < 0){

nombre = -nombre; 
}

printf("%d",nombre);
printf("\n");

}
```
## Code n°2 : valeur maximale de 3 nombres

### Description
Ce programme demande à l'utilisateur d'entrer 3 nombres, détermine le maximum parmi eux, et affiche le résultat. Il utilise les fonctions d'entrée/sortie de la bibliothèque standard (printf et scanf) ainsi que des structures conditionnelles (if, else if, else).

### Code :
```c
#include <stdio.h>
int main() {

int nombre1;
int nombre2;
int nombre3;
printf("Entrez un nombre : ");
scanf("%d",&nombre1);

printf("Entrez un nombre : ");
scanf("%d",&nombre2);

printf("Entrez un nombre : ");
scanf("%d",&nombre3);

if ((nombre3 > nombre2) && (nombre3 > nombre1))
{

printf("Resultat maximum est ");
printf("%d \n", nombre3);
}
else if ((nombre2 > nombre3) && (nombre2 > nombre1))
{

printf("Resultat maximum est : ");
printf("%d \n", nombre2);
}

else {
printf("Resultat maximum est : ");
printf("%d \n", nombre1);
}

}
```
## Code n°3 : Test Utilisateur Majorité 

### Description
Ce programme interagit avec l'utilisateur pour recueillir des informations personnelles (âge, nom, prénom) afin de déterminer le statut de majorité de la personne en France et aux États-Unis. Les principales fonctions utilisées sont ___printf___ pour l'affichage et scanf pour la saisie des données.

La boucle ***while*** du début a pour utilité de répéter le message tant que l'utilisateur n'a pas rentré toutes les données.
La fonction ***case*** s'effectue au déclanchement d'une touche 
### Code :
```c
#include <stdio.h>

int main() 
{
  int age;
  int  age_int = 0;
  int  nom_int= 0;
  int prenom_int = 0;
  char nom[20] = "";
  char pre[20] = "";
  char lettre;


  while (age_int == 0 ||  nom_int ==0 || prenom_int==0) {
  printf("Taper A pour saisir votre Age\n Taper N pour sair votre Nom\n Taper P pour saisir votre Prenom");
  scanf("%c",&lettre);
  switch(lettre)
  {
    case 'A' :
    printf("Entrez votre âge : ");
    scanf("%d",&age);
    age_int = 1;
    break;

    case 'N':
    printf("Entrez votre nom : ");
    scanf("%s", nom);
    nom_int=1;
    break;

    case 'P':
    printf("Entrez votre prenom : ");
    scanf("%s", pre);
    prenom_int =1;
    break;

    default:
    printf("lettre non vallable ! ");
  }
}
  printf("Bonjour  %s %s ",pre,nom);

	if (age>18 && age<20){ 
	printf( "vous êtes majeur en France mais pas au état-unis \n");
	}
	else if (age <18){
	printf("Vous êtes mineur en France et aux Etat-Unis \n");
	}
	else{
	printf("vous être majeur en france et au état-unis \n");
	}
}




```
## Code n°4 : le code n°3 mais qui s'arrete lorsqu'on appuis sur la touche "q" ou "Q"

### Description
Le même code que précédemment, mais avec ces modifications permettant que lorsque l'utilisateur appuie sur la lettre 'Q' ou 'q', cela renvoie 1 à chaque variable, ce qui met fin au programme grace a la boucle while.

### Code :
```c

  case 'q':
	prenom_int = 1;
	nom_int =1;
	age_int =1;
	break;

  case 'Q':
	prenom_int = 1;
  nom_int =1;
  age_int =1;
  break;
    
```
## Code n°5 : calcul de puissance

### Description
Ce programme permet à l'utilisateur d'entrer un nombre et une puissance, puis calcule et affiche le résultat de la puissance de ce nombre. La boucle for est utilisée pour calculer la puissance en multipliant le nombre par lui-même le nombre de fois que l'utilisateur a demandé, et le résultat est stocké dans la variable result.

### Code :
```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int nb;
    int exponent;
    int resultat = 1;
    int i;

    printf("Tapez un nombre : ");
    scanf("%d", &nb);

    printf("Tapez une puissance: ");
    scanf("%d", &exponent);

    for (i = 0; i < exponent; i++) {
        resultat = resultat * nb;
    }

    printf("Le résultat de '%d' à la puissance '%d' est %d\n", nb, exponent, resultat);

}
```
###### Tirateau Robin
