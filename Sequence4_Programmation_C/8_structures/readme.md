# Structures de données

Les types de données simples proposés par le langage C ne suffisent pas toujours pour simplifier et organiser le stockage des données à utiliser dans un programme. Les tableaux permettent de stocker des données multidimensionnées, mais seulement selon un type unique et homogène à l'ensemble du tableau. Les structures de données répondent alors à un objectif de construction de données composites à partir d'un ensemble de variables simples de différents types.

## Déclaration d'un type structuré

La déclaration d'une structure de données repose sur le mot-clé `struct` et se termine par le caractère `;`. Le format général à respecter lors de la déclaration d'une structure est le suivant :

```c
struct <nom de la structure>
{
    <type> <nom du membre 1>;
    <type> <nom du membre 2>;
    <type> <nom du membre 3>;
    // ...
};
```

La déclaration de la structure revient à définir un nouveau type complexe de données. Par exemple, voici une déclaration de structure nommée `personne` :

```c
struct personne
{
    char nom[20];
    char prenom[20];
    unsigned short int age;
};
```
En effet, le nom des membres d'une structure répond aux critères des noms de variables applicables en langage C et deux membres d'une même structure ne peuvent pas porter le même nom. De plus, les membres peuvent être de n'importe quel type hormis le type de la structure dans laquelle ils se trouvent.
Le nombre de membres au sein d'une structure n'est pas limité. Chaque membre est défini comme une variable qui peut être de type simple ou complexe. Il est ainsi possible de déclarer une structure comme membre d'une autre structure. Par exemple, voici un exemple de mise en œuvre de structures imbriquées :

```c
struct commande
{
    int reference;
    unsigned int quantite;
    struct
    {
        double montant_ht;
        double montant_tva;
    } prix;
};
```
Dans l'exemple ci-dessus, le type de la donnée interne structurée prix n'est pas nommé. Il est juste précisé que cette donnée est une structure et que son nom est prix. Il est en effet inutile de nommer ce type structuré dès lors qu'il ne concerne qu'une exploitation interne.

Il est par ailleurs important de noter que les membres d'une structure ne peuvent pas être initialisés lors de la déclaration. En effet, lorsqu'un type de données est déclaré, aucun espace mémoire n'est alloué pour celui-ci. La mémoire n'est allouée qu'au moment de la déclaration des variables.

# Déclaration d'une variable structurée 
La déclaration d'une variable structurée peut se faire de deux façons. La première consiste à déclarer les variables de type structuré après la
déclaration de la structure comme le montre l'exemple ci-dessous qui concerne la déclaration de deux variables de type structuré ```employe}.
```c
struct employe
{
    char identite[50];
    unsigned short int age;
    char adresse[50];
    float salaire;
};

struct employe emp1,emp2;
```

L'autre manière de procéder est de déclarer les variables de type structuré lors de la déclaration de la structure. Le code ci-après présente un
exemple de déclaration de variables de type structuré au moment de la déclaration du type structuré :

```c
struct employe
{
    char identite[50];
    unsigned short int age;
    char adresse[50];
    float salaire;
} emp1, emp2;
```

Les deux modes de déclaration présentés ci-dessus sont identiques du point de vue de l'exécution du code compilé.
## Affectation des membres d'une variable structurée

Les membres d'une variable structurée sont accessibles en respectant le format ```<variable structurée>.<membre>``` A titre d'exemple, pour
initialiser ou mettre à jour le membre ```age``` d'une variable nommée ```p1```, il faut procéder de la façon suivante : 

```c
p1.age = 37;
printf("Age:%hu \n", p1.age);
```

## Utilisation de tableaux de structures
Tout comme pour les types simples de variables, il est possible de déclarer des tableaux de structures. Le code ci-dessous présente un exemple
concernant la déclaration d'un répertoire sous forme d'une variable multidimensionnée et nommée ```rep``` permettant de stocker les informations
relatives à une centaine de personnes :

```c
struct personne
{
char nom[50] ;
char adr[50] ;
char tel[20] ;
}
struct personne rep[100];

```

L'accès aux membres de chaque donnée structurée ```personne``` encapsulée dans le tableau de structures ```rep``` se fait alors de la façon
suivante :
```c

strcpy(rep[5].tel, "+33625898144");
printf("Tél. : %s\n", rep[5].tel);  
```

## Définition d'un type structuré

La déclaration d'une variable structurée peut être simplifiée en évitant de préciser systématiquement le mot-clé ```struct``` suivi du nom de la
structure devant le nom de la variable à déclarer. En effet et afin d'éviter cette écriture, le mot-clé ```typedef``` peut être utilisé pour définir
un nouveau type de donnée correspondant à la structure déclarée. Cette façon de procéder est notamment utile lorsque le nombre de déclaration de variables
reposant sur une même structure est important.

Par exemple, pour définir un nouveau type structuré de donnée permettant de consigner les coordonnées cartésiennes d'un point, le code suivant peut être
utilisé :

```c
typedef struct
{
  double x;
  double y;
} point;
```

L'utilisation de ce nouveau type de donnée s'effectue alors de façon simplifiée comme le montre le code ci-après destiné à stocker l'ensemble des points
d'une courbe :
```c
point courbe[200];
```

# Exercices 

## Exercice 1 : 

Créer une structure etudiant qui contient : Nom, Prénom et moyenne d'un étudiant
Dans le main déclarer 2 étudiants et rentrer leurs informations

## Exercice 2 : 

Créer un tableau de 50 étudiants
Dans le main créer une solution pour accéder et manipuler les données à l'aide de l'indexation des tableaux etudiant[0], etudiant[1]...

## Exercice 3 :

En utilisation la compilation en fichiers séparés (vous devrez avoir 3 fichiers etudiants.c, etudiants.h et main.c), créer une fonction "calculerMoyenne()" qui calcule
la moyenne de tous les étudiants

## Exercice 4 : 

Créer une fonction afficherEtudiants() qui affiche l'ensemble des étudiants et leur moyenne

## Exercice 5 : 

Ajoutez un champ booléen à la structure etudiant pour représenter s'il est présent ou absent. 
Ecrire une fonction appel() qui affiche l'un après l'autre les étudiants et permet de les noter present ou absent
Ecrire une fonction afficherAbsents() qui affiche les étudiants absents
Ecrire une fonction afficherPresents() qui affiche les étudiants présents