# Arguments de la ligne de commande

La fonction ```main()``` est la fonction principale de tout programme écrit en langage C. ll est alors courant de devoir lui passer
  des arguments lors de l’appel d’un programme afin de paramétrer son exécution. Dès lors que la fontion ```main()``` est la première exécutée au
  moment du lancement du programme, celle-ci permet de recueillir les arguments passés par la ligne de commande.

Déclaration de la fonction ```main()```
Lorsqu'il n'est pas nécessaire de passer des arguments par la ligne de commande, la forme simplifiée suivante est utilisée pour déclarer la fonction
principale ```main()``` :
```C
int main(void){}
```

Cependant et de manière générale, la forme standard de la fonction ```main()``` est la suivante :
```C
int main(int argc, char *argv[]){}
```

La variable ```argc``` (argument count) est automatiquement affectée en fonction du nombre d’arguments passés par la ligne de commande. La variable ```argv``` (argument vector) est un tableau à une dimension dans lequel est stockée la liste des arguments passés par la ligne de commande. Le premier élément du tableau (indice 0) est toujours le nom du fichier binaire lui-même exécuté. Par conséquent, il existe toujours au moins un argument qui est implicitement transmis à la fonction ```main()``` par la ligne de commande. Le second élément du tableau (indice 1) correspond au premier argument saisi par l'utilisateur et passé par la ligne de commande et ainsi de suite pour la succession des arguments saisis sur la ligne de commande.

La variable ```argc``` est de type entier alors que les arguments contenus dans le tableau de variables ```argv``` sont des chaînes de caractères. 
## Programme de démonstration
Le code source présenté ci-dessous montre un exemple d’exploitation des arguments de la fonction ```main()``` :

```C
#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;

  printf("Nb. arguments : %d\n",argc);

  for (i = 0; i < argc; i++)
    printf("Argument %d : %s\n",i + 1, argv[i]);

  return 0;
}
```

En considérant que le code présenté ci-dessus soit compilé dans un fichier binaire nommé ```mon_prog```, une exemple d'exécution par la ligne de commande peut être celui-ci :
```
./mon_prog abc def ghi jkl
```
Lors de l'exécution du programme, la variable ```argc``` est affectée de la valeur entière ```5``` et le tableau ```argv``` contient le nom
du fichier binaire exécuté suivi des quatre chaînes de caractères successivement transmises par la ligne de commande, soit ```"abc"```,```"def```, ```"ghi"``` et ```"ijk"```.

Le résultat d'exécution est alors le suivant :

```
Nb. arguments : 5
Argument 1 : ./mon_prog
Argument 2 : abc
Argument 3 : def
Argument 4 : ghi
Argument 5 : jkl
```
## Exploitation d'arguments sous forme numérique
Bien que les arguments transmis à la fonction ```main()``` sont systématiquement de type chaîne de caractères, il est possible de les exploiter comme des valeurs numériques. Pour cela, il faut convertir les chaînes passées en arguments sous forme de nombre entiers en utilisant les fonctions ```atoi()``` et ```atol()``` définies dans le fichier d'entête ```stdlib.h``` qu'il est alors impératif d'inclure dans le code source du programme. 

Le prototype des deux fonctions est le suivant :
```C
int atoi(const char *str);
long int atol(const char *str);
```
Un exemple simplifié de mise oeuvre est donné par le code ci-dessous :

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int r;

  if (argc == 3)
  {
    r = atoi(argv[1]) + atoi(argv[2]);
    printf("Addition : %d\n", r);
  }
  
  return 0;
}
```
L'exécution du programme se lance au moyen de la ligne de commande ci-dessous en passant deux arguments arbitrairement choisis :
```
./mon_prog 10 52
```
Le résultat d'exécution obtenu est le suivant :
```
Addition : 62
```

Un autre exemple, consistant à prendre en considération un nombre variable d'arguments, est présenté ci-après :
```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i;
  long somme = 0;

  for (i = 1; i < argc; i++)
    somme += atol(argv[i]);

  printf("Somme : %ld\n", somme);

  return 0;
}
```
Dans cet exemple, la convertion des arguments reçus par la ligne de commande et passés à la fonction ```main()``` repose sur la fonction ```atol()``` afin de permettre la prise en compte de plus grands nombres.

L'exécution du programme s'effectue au moyen de la ligne de commande ci-dessous avec un nombre arbitraire d'arguments :
```
./mon_prog 14 25 36 47
```
Le résultat d'exécution obtenu est le suivant :
```
Somme : 122
```

## Exercices 

Après avoir compilé et testé les 2 programmes de démonstrations réalisez les programmes suivants :

### Exercice 1 : Calculatrice simple :
Élaborez une calculatrice simple prenant trois arguments de la ligne de commande : deux nombres et un opérateur (+, -, *, /). Affichez le résultat du calcul.

### Exercice 2 : Conversion d'unités :
Écrivez un programme qui convertit une valeur donnée en mètres en pieds. L'entrée sera fournie en tant qu'argument de la ligne de commande.

### Exercice 3 : Conversion d'unité avec contrôle
Modifiez le programme précédent pour inclure une vérification d'entrée, en vous assurant que l'argument fourni est un nombre valide.
