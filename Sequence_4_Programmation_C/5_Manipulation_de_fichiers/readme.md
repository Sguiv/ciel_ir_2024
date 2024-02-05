Gestion des fichiers
Fondements du langage C
L'utilisation des chiers permet de lire,
de tra^ter et de sauvegarder sur la
memoire de masse (disque dur, carte
memoire, etc.) des donnees qui doivent ^etre
conservees m^eme apres l'arr^et de la machine,
ce qui n'est pas possible par l'utilisation des
variables. Les operations de gestion de chiers
concernent les traitements courants de lecture
et d'ecriture mais egalement de creation, de
renommage et de suppression. La plupart des
fonctions liees a la gestion des chiers sont
denies dans le chier d'ent^ete stdio.h de la
bibliotheque standard.
Fonctions fopen() et fclose()
pour l’ouverture et la fermeture et
diff ´erents modes d’acc`es
L'ouverture d'un chier s'eectue au moyen de la
fonction fopen(). Son prototype est le suivant :
FILE * fopen ( const char * f i c h i e r ,
const char *mode ) ;
Cette fonction renvoie un pointeur sur un type
specique complexe nomme FILE. Il s'agit en fait
d'une structure de donnees denie dans le chier
d'ent^ete stdio.h.
Le parametre fichier est une cha^ne de caract
eres correspondant au nom du chier a ouvrir
et eventuellement au chemin d'acces complet jusqu'au
chier a ouvrir s'il ne se situe pas dans le
repertoire courant. Le parametre mode permet de
preciser le mode d'ouverture speciant le type d'acces
au contenu du chier. Les principales valeurs sont
listees dans le tableau 1. Elles s'appliquent a un acces
en mode texte. C'est-a-dire que le contenu des chiers
est tra^te sous forme de caracteres et non pas comme
une succession d'elements binaires (0 ou 1).
Specicateurs Signication
"r" Lecture seule
"w" Ecriture seule
"a" Ajout a la n du chier
"r+" Lecture et ecriture
"w+" Lecture et ecriture avec
suppression prealable du
contenu
"a+" Lecture et ajout a la n du
chier
Tab. 1 { Liste des specicateurs de mode d'acces
Il existe aussi les specicateurs "rb", "wb", "ab",
"rb+", "wb+" et "ab+". Ils sont destines a acceder
aux chiers non plus en mode texte mais en mode
binaire.
En cas d'echec d'ouverture du chier, la fonction
fopen() renvoie la valeur NULL. Il convient alors
de tester la valeur renvoyee an de s'assurer que
l'ouverture du chier s'est correctement eectuee.
La fermeture d'un chier prealablement ouvert par
la fonction fopen() s'eectue en utilisant la fonction
fclose() qui ne prend en parametre que le nom du
pointeur renvoye lors de l'ouverture du chier. Le
prototype est indique ci-dessous :
int f c l o s e (FILE * f i c h i e r ) ;
La fonction fclose() renvoie la valeur entiere 0
lorsque la fermeture du chier s'est correctement
deroulee. Elle libere alors de la memoire vive la variable
de type FILE associee au prealablement chier
ouvert par la fonction fopen(). En cas d'echec, la
fonction fclose() renvoie la valeur EOF.
Loc Plassart Page 1/4
Le code source presente ci-dessous montre
un exemple simplie d'exploitation des fonctions
fopen() et fclose() qui consiste a ouvrir un chier
en mode texte avec un acces en lecture et ecriture
puis de le refermer :
FILE * f i c ;
f i c = fopen ( " f i c h i e r . txt " , " r+" ) ;
i f ( f i c != NULL)
f
p r i n t f ( "Le f i c h i e r e s t ouve r t ! n n" ) ;
f c l o s e ( f i c ) ;
g
el se
p r i n t f ( "L ' ouve r tur e du f i c h i e r a
e choue ! n n" ) ;
La valeur renvoyee par la fonction fclose() n'est
ici pas evaluee. Il est en eet rare qu'une desallocation
memoire ne s'eectue pas correctement. Aussi et
excepte dans le cas ou le niveau de abilite et de
robustesse du programme est critique, il n'est pas
toujours necessaire de considerer le cas d'erreur lors
d'une fermeture de chier.
Fonctions fputc(), fputs() et
fprintf() pour l’ ´ecriture
Lorsqu'il s'agit d'inserer un simple caractere
dans un chier prealablement ouvert en ecriture,
il convient d'utiliser la fonction fputc() dont le prototype
est indique ce-dessous :
int fput c ( int c a r a c t e r e ,
FILE * f i c h i e r ) ;
Cette fonction ne prend en compte que deux param
etres que sont le caractere a inserer et le chier
concerne par l'ecriture. Un caractere est code sur un
octet, c'est-a-dire un entier sur huit bits. L'utilisation
du type int permet ainsi de passer le caractere en
parametre.
La fonction fputc() retourne une valeur de type
int. Celle-ci vaut EOF si l'ecriture a echoue et une
autre valeur entiere correspondant au code du caract
ere en cas de reussite.
Le prototype et l'utilisation de la fonction fputs()
sont tres similaires a ceux de la fonction fputc(). La
dierence provient du fait que la fonction fputs()
permet d'ecrire dans un chier une cha^ne de caract
eres et non pas un seul caractere. Le prototype
est le suivant :
int fput s ( const char * chaine ,
FILE * f i c h i e r ) ;
Le terme const dans le prototype indique que la
cha^ne passee en parametre sera consideree comme
une constante car il s'agit uniquement de lire la
variable associee et en aucun cas de la modier.
La fonction fputs() renvoie une valeur entiere
superieure a zero en cas d'execution correcte et EOF
en cas d'echec.
Le code source presente ci-dessous montre
un exemple simplie d'exploitation des fonctions
fputc() et fputs() :
FILE * f i c ;
f i c = fopen ( " f i c h i e r . txt " , "w" ) ;
i f ( f i c != NULL)
f
fput c ( 'B' , f i c ) ;
fput s ( " onjou " , f i c ) ;
fput c ( ' r ' , f i c ) ;
f c l o s e ( f i c ) ;
g
Lorsqu'il est necessaire d'ecrire une cha^ne format
ee dans un chier, il convient d'utiliser la fonction
variadique fprintf() qui permet donc de prendre
en compte des variables et d'en specicier le format.
Son prototype est indique ci-dessous :
int f p r i n t f (FILE * f i c h i e r ,
const char * chaine , . . . ) ;
La fonction fprintf() retourne le nombre de caract
eres ecrits si l'operation s'est bien deroulee ou
une valeur negative en cas d'echec.
L'exemple de code ci-dessous presente une utilisation
simpliee de la fonction fprintf() pour
l'ecriture dans un chier :
int nb = 1024;
FILE * f i c ;
f i c = fopen ( " f i c h i e r . txt " , "w" ) ;
i f ( f i c != NULL)
f
f p r i n t f ( f i c , "Nombre : %dnn" , nb ) ;
f c l o s e ( f i c ) ;
g
Loc Plassart Page 2/4
Fonctions fgetc(), fgets() et
fscanf() pour la lecture
La fonction fgetc() permet de lire un caractere
unique dans un chier. Son prototype est le suivant :
int * f g e t c (FILE * f i c h i e r ) ;
En cas de reussite, la fonction fgetc() renvoie
une valeur entiere correspondant au caractere lu.
Elle retourne la valeur EOF dans le cas contraire.
La fonction fgetc() lit le caractere courant du -
chier sur lequel elle pointe. Au moment de la premiere
execution, elle lit donc le premier caractere et successivement
les autres caracteres lors des executions
suivantes.
Le code simplie ci-dessous montre un exemple
d'utilisation de la fonction fgetc() :
FILE * f i c ;
int car ;
f i c = fopen ( " f i c h i e r . txt " , " r " ) ;
i f ( f i c != NULL)
f
/* Le c tur e s s u c c e s s i v e s */
/* des c a r a c t e r e s du f i c h i e r */
do
f
/* Lecture e t a f f i c h a g e */
/* du c a r a c t e re courant */
car = f g e t c ( f i c ) ;
p r i n t f ( "%c " , car ) ;
g while ( car != EOF) ;
f c l o s e ( f i c ) ;
g
Pour realiser une lecture ligne par ligne plut^ot que
caractere par caractere, il est possible d'utiliser la
fonction fgets() dont le prototype est le suivant :
char * f g e t s ( char * chaine ,
int nombre ,
FILE * f i c h i e r ) ;
La fonction fgets() lit une ligne dans un chier
ouvert en lecture qu'elle stocke dans une cha^ne
pointee par le premier parametre note chaine. La
lecture s'interrompt lorsque le nombre nombre de
caracteres a lire est atteint, lorsqu'un retour a la
ligne ('nn') est lu ou que la n de chier EOF est
atteinte. Par ailleurs et an de marquer la n de
cha^ne, le caractere NULL ('n0') est ajoute apres le
dernier caractere lu. La fonction fgets() lit donc au
plus nb - 1 caracteres a partir du chier.
La fonction fgets() retourne le m^eme pointeur
que celui pointe par l'argument chaine si la fonction
s'est executee sans erreur. Elle retourne la valeur
NULL si une erreur s'est produite ou lorsque la n
de chier est atteinte. L'evaluation de la valeur retourn
ee permet donc de savoir si l'execution s'est
correctement deroulee ou non mais aussi de detecter
la n de chier.
Un exemple simplie d'utilisation de la fonction
fgets() pour la lecture d'un chier texte est presente
ci-dessous :
FILE * f i c ;
char l i g [ 5 1 ] ;
f i c = fopen ( " f i c h i e r . txt " , " r " ) ;
i f ( f i c != NULL)
f
/* Le c tur e s s u c c e s s i v e s */
/* des l i g n e s du f i c h i e r */
while ( f g e t s ( l i g , 50 , f i c ) != NULL)
p r i n t f ( "%s " , l i g ) ;
f c l o s e ( f i c ) ;
g
La fonction fscanf() est de type variadique. Elle
est utilisee pour lire dans un chier contenant une
organisation specique et connue du texte. Son prototype
est precise ci-dessous :
int f s c a n f (FILE * f i c h i e r ,
const char * format , . . . ) ;
Le code ci-dessous presente un exemple simplie
d'utilisation de la fonction fscanf() :
FILE * f i c ;
char nom[ 2 0 ] ;
int age ;
f i c = fopen ( " f i c h i e r . txt " , " r " ) ;
i f ( f i c != NULL)
f
f s c a n f ( f i c , "%s %d" , nom, &age ) ;
p r i n t f ( "Ligne : %s , %d" , nom, age ) ;
f c l o s e ( f i c ) ;
g
Loc Plassart Page 3/4
Dans cet exemple, il s'agit de lire une ligne compos
ee de deux champs separes par un espace et d'af-
cher le resultat de la lecture. Le premier champ est
une cha^ne de caracteres et le second est un entier.
Fonctions ftell(), fseek() et
rewind() pour le positionnement
A
l'ouverture d'un chier, un curseur est initialise
pour consigner la position dans le chier qui est
donnee en nombre d'octets. Il s'agit donc du nombre
de caracteres par rapport au debut du chier.
La fonction ftell() permet de conna^tre la position
courante dans le chier. Elle renvoie la position
du curseur dans le chier sous la forme d'une variable
de type long ou la valeur -1 en cas d'erreur. Son
prototype est le suivant :
long f t e l l (FILE * f i c h i e r ) ;
La fonction fseek() permet de deplacer le curseur
d'un certain nombre de caracteres a partir d'une
position d'origine. Elle retourne la valeur 0 en cas
de reussite et une autre valeur en cas d'echec. Son
prototype est indique ci-dessous :
int f s e e k (FILE * f i c h i e r ,
long deplacement ,
int o r i g i n e ) ;
La valeur du deplacement peut ^etre donnee par un
nombre positif ou negatif selon que le deplacement
doit ^etre opere en avant ou en arriere. Elle peut
egalement ^etre nulle s'il s'agit de deplacer le curseur
a l'origine pasee en parametre. L'origine est indiquee
par l'une des trois constantes suivantes :
| SEEK SET
| SEEK CUR
| SEEK END
Ces trois constantes correspondent respectivement
au debut du chier, a la position courante du curseur
et a la n du chier. A titre d'exemple, le code cidessous
place le curseur a la n du chier :
FILE* f i c ;
f i c = fopen ( " f i c h i e r . txt " , " r " ) ;
i f ( f i c != NULL)
f
f s e e k ( f i c , 0 , SEEK END) ;
f c l o s e ( f i c ) ;
g
La fonction rewind() force le renvoi du curseur
au debut du chier. Elle ne retourne rien et son
prototype est le suivant :
void rewind (FILE * f i c h i e r ) ;
Fonction rename() pour le
renommage
Le renommage d'un chier s'eectue au moyen de
la fonction rename() dont le prototype est indique
ci-dessous :
int rename ( const char *anciennom ,
const char *nouveaunom ) ;
La fonction rename() renvoie la valeur 0 si le
renommage du chier s'est correctement deroule ou
une valeur dierente en cas d'erreur.
Fonction remove() pour la
suppression
La suppression d'un chier est realisee par la fonction
remove(). Son prototype est le suivant :
int remove ( const char * f i c h i e r ) ;
La fonction remove() renvoie la valeur 0 si la
suppression du chier s'est correctement deroulee ou
-1 en cas d'erreur.
Il convient d'^etre prudent dans l'utilisation de la
fonction remove(). Elle supprime le chier dont le
nom est passe en parametre sans emettre de message
d'avertissement ou de conrmation.
Loc Plassart Page 4/4