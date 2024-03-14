#include <stdio.h>

int main()
{
    FILE * monFichier = fopen("test.txt","a");

    if(monFichier==NULL)
    {
        printf("Echec de l'ouverture du fichier \n");
        return -1;
    }
    else{
        
    }
    printf("Ouverture du fichier OK!\n");
    printf("Taper un chiffre entier\n");
    int monEntier=0;
    scanf("%d",&monEntier);
    fprintf(monFichier,"Essai d'ecriture dans un fichier: %d\n",monEntier); 
    return 1;
}


