#include <stdio.h>
#include <string.h>
char nom[50];
char prenom[50];
int age;
float tailleEnMetres;
unsigned int compteur = 1;
unsigned int nbPersonnes = 0;
unsigned int nbLignes=0;
char ch;
FILE *fichier;
char ligne[51];

void ajouterNoms(){
    

        
        printf("Enregistrement personne %d\n",compteur);
        printf("Taper nom\n");
        scanf(" %s", nom);
        printf("Taper prenom\n");
        scanf(" %s", prenom);
        printf("Taper age\n");
        scanf(" %d", &age);
        printf("Taper taille en metres\n");
        scanf(" %f", &tailleEnMetres);

        fprintf(fichier, "%d;%s;%s;%d;%.2f\n", compteur, nom, prenom, age, tailleEnMetres);
        compteur++;
        
    
 
}

void afficherListe(){
    if(fichier!=NULL)
    {
        rewind(fichier);
        printf("|id|Nom|Prenom|Age|Taille\n");
        printf("________________________\n");
       while(fgets(ligne,50,fichier)!=NULL){
            char* strToken = strtok(ligne,";");
            while ( strToken != NULL )
            {
                printf ( "|%s", strToken );
                // On demande le token suivant.
                strToken = strtok ( NULL, ";" );
            }
            
            printf("________________________\n");
        }

       
    }
}

void afficherListefgetc()
{
    if(fichier!=NULL)
    {
        rewind(fichier);
        char carac = fgetc(fichier);
        while(carac!=EOF)
        {
            if(carac==';')
            {
                putc('|',stdout);
            }
            else if(carac=='\n')
            {
                printf("\n__________________\n");
            }
            else
            {
                putc(carac,stdout);
            }
        carac=fgetc(fichier);
        }
    }
}
int main()
{
    fichier = fopen("BaseDeDonnees.csv", "r+");
    
    if (fichier != NULL)
    {
        printf("Ouverture du fichier ok\n");
    }
    else
    {
        printf("Echec de l'ouverture du fichier BaseDeDonnees.csv");
        return 0;
    }

    while (!feof(fichier))
    {
        ch = fgetc(fichier);
        if (ch == '\n')
        {
            nbLignes++;
        }
    }
    printf("Nb de lignes dans fichier existant :%d\n", nbLignes);
    compteur=nbLignes+1;
    int choix=0;
    while(choix!=3)
    {
    printf("Taper\n-1 pour afficher la liste des personnes\n-2 pour ajouter une personne\n-3 Pour quitter\n" );
    scanf(" %d", &choix);
    
    switch (choix)
    {
        case 1:
            afficherListefgetc();
        break;
        case 2:
            ajouterNoms();
        break;       
        case 3:
            return 1;
        default:
            printf("Choix incorrect\n");
        break;
    }
    }   
}