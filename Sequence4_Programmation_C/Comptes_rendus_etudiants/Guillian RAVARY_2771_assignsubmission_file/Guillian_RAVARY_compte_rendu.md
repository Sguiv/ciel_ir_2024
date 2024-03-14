[Lien vers l'exercice du github  ](https://github.com/Sguiv/ciel_ir_2024/tree/main/Sequence_4_Programmation_C)

# Exercices sur les conditions et les boucles

##  EX1 :

```c

#include <stdio.h>

int main(){

int nb;

printf("Entrez un nombre : ");
scanf("%d", &nb);

if (nb < 0){

nb = -nb; 
}


printf("%d",nb);
printf("\n");


}
``` 

Dans cette exercice, j'ai appris à utiliser  la fonction **if**, **scanf()** ainsi que **printf()**. J'ai donc initiasilé la variable *nb* pour pouvoir stockez le contenu de fonction **scanf()** et dans la fonction **if (nb <0)**, si le nombre est inférieur à 0 alors je stocke la variable avec l'opérateur **-** permettant d'afficher la valeur absolue.


------- 

## EX2 :


```c

#include <stdio.h>
int main() {

    int nb1;
    int nb2;
    int nb3;
    printf("Entrez un nombre : ");
    scanf("%d",&nb1);

    printf("Entrez un nombre : ");
    scanf("%d",&nb2);

    printf("Entrez un nombre : ");
    scanf("%d",&nb3);

    if ((nb3 > nb2) && (nb3 > nb1))
    {

        printf("Resultat maximum est");
        printf("%d", nb3);
    }
    else if ((nb2 > nb3) && (nb2 > nb1))
    {

        printf("Resultat maximum est : ");
        printf("%d", nb2);
    }

    else {
        printf("%d", nb1);
    }

}
```
Dans cette exercice nous avons utilisés les opperateurs **&&** et ainsi que les conditions **else if**. j'initialise les variables *nb1*, *nb2*, *nb3*, ensuite avec les fonctions scanf(), je récupére les nbs de l'utilisateur. ainsi avec la fonction **if** je compare les nombres pour savoir qu'elle est le nombres le plus grands. et ensuite je **print** le resultat. 


-----

## EX3 :


```c
#include <stdio.h>

int main() 
{
  int age;
  int  age_count = 0;
  int  nom_count= 0;
  int pre_count = 0;
  char nom[20] = "";
  char pre[20] = "";
  char entre;


  while (age_count == 0 ||  nom_count ==0 || pre_count==0) {
  printf("Taper A pour saisir votre Age\n Taper N pour sair votre Nom\n Taper P pour saisir votre Prenom");
  scanf("%c",&entre);
  switch(entre)
  {
    case 'A' :
    printf("Entrez votre âge : ");
    scanf("%d",&age);
    age_count = 1;
    break;

    case 'N':
    printf("Entrez votre nom : ");
    scanf("%s", nom);
    nom_count=1;
    break;

    case 'P':
    printf("Entrez votre prenom : ");
    scanf("%s", pre);
    pre_count =1;
    break;

    default:
    printf("lettre non vallable ! ");
  }
}
  printf("Bonjour  %s %s ",pre,nom);

	if (age>18 && age<20){ 
	printf( "vous êtes majeur en France mais pas au état-unis");
	}
	else if (age <18){
	printf("Vous êtes mineur en France et aux Etat-Unis ");
	}
	else{
	printf("vous être majeur en france et au état-unis");
	}
}
```

La complexité de cette exercice, à été d'utiliser "**switch() case:**" ainsi que de créer la boucle **while** pour permettre à l'utilisateur de pouvoir remplir le formulaire en entier. Également l'initialisation des variables à étés plutôt complexes pour savoir qu'elles **typages** nous allons choisir. J'initialise les différentes variables au début, ensuite avec la boucle **while**, je déclare, que la boucle se termine que quand les variables : *age_count*, *pre_count*, *nom_count* sont égales à 0. Ensuite avec la fonction **switch case** je crée 4 conditions pour ensuite stocker les différentes entrée de l'utilisateur. Pour finir, je crée une condition **if**  pour comparé les âges pour savoir s'il est mineur ou non au État-Unis et en France.


----

## EX4 :

```c
#include <stdio.h>

int main() 
{
  int age;
  int  age_count = 0;
  int  nom_count= 0;
  int pre_count = 0;
  char nom[20] = "";
  char pre[20] = "";
  char entre;


  while (age_count == 0 ||  nom_count ==0 || pre_count==0) {
  printf("Taper A pour saisir votre Age\n Taper N pour sair votre Nom\n Taper P pour saisir votre Prenom");
  scanf("%c",&entre);
  switch(entre)
  {
    case 'A' :
    printf("Entrez votre âge : ");
    scanf("%d",&age);
    age_count = 1;
    break;

    case 'N':
    printf("Entrez votre nom : ");
    scanf("%s", nom);
    nom_count=1;
    break;

    case 'P':
    printf("Entrez votre prenom : ");
    scanf("%s", pre);
    pre_count =1;
    break;

    case 'q':
	pre_count = 1;
	nom_count =1;
	age_count =1;
	break;

    case 'Q':
	pre_count = 1;
        nom_count =1;
        age_count =1;
    default:
    printf("lettre non vallable ! ");
  }
}
  printf("Bonjour  %s %s ",pre,nom);

	if (age>18 && age<20){ 
	printf( "vous êtes majeur en France mais pas au état-unis");
	}
	else if (age <18){
	printf("Vous êtes mineur en France et aux Etat-Unis ");
	}
	else{
	printf("vous être majeur en france et au état-unis");
	}
}
```
Danc cette exercice, nous avons rajouter un " **case 'q'** " permettant d'arrêté la boucle **while** en incremettant **+1** au variable **pre_count, nom_count, age_count**. 

## EX5 : 

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
int nb;
int exp;
int res = 1;
int i;
printf("Tapez un nombre : ");
scanf("%d", &nb);
printf("Tapez une puissance: ");
scanf("%d", &exp);

for( i=0;i<exp;i++){
	res = res*nb;
}

printf("le resultat de '%d' à la puissance '%d' est %d ", nb,exp,res);
}

```

Dans cette exercice, nous avons remplacer la fonction **pow()**, avec une boucle **for**, ce qui permet à l'utilisateur de pouvoir entrez un nombre ainsi que sa puissance pour pouvoir faire le calcul. 

----

