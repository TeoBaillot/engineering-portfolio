// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/05/2024
// Date de dernière modification: 06/06/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "data.h"

// Rôle: Initialise les données partagées
// Antécédent: d est un pointeur sur une donnée partagée
void initDonneePartagee(DonneePartagee *d){
    // Allocation de la mémoire pour stocker le mot à trouver
    d->MotATrouver=malloc(sizeof(char)*(tailleMotMax+1));

    // Initialisation du mot à trouver
    MotATrouver(d);

    // Initialisation de la taille du mot à trouver
    d->tailleMotATrouver=strlen(d->MotATrouver);

    // Allocation de la mémoire pour stocker le mot de l'utilisateur
    d->MotUtilisateur=malloc(sizeof(char)*(d->tailleMotATrouver));

    // Initialisation du mot de l'utilisateur
    strcpy(d->MotUtilisateur, "");

    // Initialisation du numéro de l'essai
    d->numeroEssai=1;

    // Initialisation du booléen qui indique que l'utilisateur n'a pas encore rentré de mots valides
    d->premiersMotsInvalides=1;

    // Allocation de la mémoire pour stocker le dernier mot valide
    d->dernierMotValide=malloc(sizeof(char)*(d->tailleMotATrouver));

    // Initialisation du dernier mot valide
    strcpy(d->dernierMotValide, "");

    // Allocation de la mémoire pour stocker les indications sur le mot à trouver
    d->indications=malloc(sizeof(char)*(d->tailleMotATrouver));

    // Initialisation des indications
    strcpy(d->indications, "");
}

// Rôle: Renvoit un pointeur sur le premier caractère de la chaîne de caractères qui donne les indications
// Antécédent: d est un pointeur sur une donnée partagée
char *getIndications(DonneePartagee *d){
    return d->indications;
}

// Rôle: Actualise le dernier mot valide entré par l'utilisateur
// Antécédent: d est un pointeur sur une donnée partagée initialisée et s pointe sur le premier caractère d'une chaîne de caractères
void setDernierMotValide(DonneePartagee *d, char *s){
    strcpy(d->dernierMotValide, s);
}

// Rôle: Renvoit un pointeur sur le premier caractère du dernier mot valide
// Antécédent: d est un pointeur sur une donnée partagée initialisée
char *getDernierMotValide(DonneePartagee *d){
    return d->dernierMotValide;
}

// Rôle: Actualise le mot entré par l'utilisateur au dernier mot entré par l'utilisateur
// Antécédent: d est un pointeur sur une donnée partagée initialisée et s pointe sur le premier caractère d'une chaîne de caractères
void setMotUtilisateur(DonneePartagee *d, char *s){
  strcpy(d->MotUtilisateur, s);
}

// Rôle: Renvoit le mot de l'utilisateur
// Antécédent: d est un pointeur sur une donnée partagée initialisée
char* getMotUtilisateur(DonneePartagee *d){
  return d->MotUtilisateur;
}

// Rôle: Change la valeur du booléen indiquant si le ou les premiers mots entrés par l'utilisateurs sont invalides pour le passer à 0
// Antécédent: d est un pointeur sur une donnée partagée initialisée
void setPremierMotsInvalides(DonneePartagee *d){
  d->premiersMotsInvalides=0;
}

// Rôle: Renvoit le booléen qui indique si l'utilisateur a déjà rentré un mot valide depuis le début de la partie
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int getPremierMotsInvalides(DonneePartagee *d){
  return d->premiersMotsInvalides;
}

// Rôle: Décrémente le nombre d'essais restants
// Antécédent: d est un pointeur sur une donnée partagée initialisée
void decrementeNombreEssaisRestants(DonneePartagee *d){
  d->numeroEssai=d->numeroEssai+1;
}

// Rôle: Renvoit un pointeur sur le premier caractère du mot à trouver
// Antécédent: d est un pointeur sur une donnée partagée initialisée
char* getMotATrouver(DonneePartagee *d){
  return d->MotATrouver;
}

// Rôle: Renvoie le nombre d'essais restants
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int getNombreEssaisRestants(DonneePartagee *d){
  return 7-d->numeroEssai;
}

// Rôle: Renvoit le numéro de l'essai
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int getNumeroEssais(DonneePartagee *d){
    return d->numeroEssai;
}

// Rôle: Renvoit la taille du mot à trouver
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int getTailleMotATrouver(DonneePartagee *d){
  return d->tailleMotATrouver;
}

// Rôle: Renvoit un pointeur sur le premier caractère du mot caché
// Antécédent: d est un pointeur sur une donnée partagée initialisée
char *MotCache(DonneePartagee *d){
    // Allocation de la mémoire pour stocker le mot caché
    char *motCache=malloc(sizeof(char)*(d->tailleMotATrouver));

    // On stocke le premier caractère du mot à trouver
    motCache[0]=d->MotATrouver[0];

    // On complète le reste avec des tirets
    for(int i=1; i<(d->tailleMotATrouver); i++){
        strcat(motCache, "-");
    }

    // On renvoit le mot caché
    return motCache;
}

// Rôle: renvoit le nombre de mots contenus dans un fichier
int NombreMotsDansFichier(void){
    // On ouvre le fichier "DicoMotus.txt" en lecture
    FILE *fichier = fopen("DicoMotus.txt", "r");

    if((fichier = fopen("DicoMotus.txt", "r")) == NULL){
        perror("DicoMotus.txt");
        exit(errno);
    }
    
    // On définit une chaîne de caractère pour stocker le mot de la ligne courante
    char MotDeLaLigneCourante[tailleMotMax+2]; 
    // On initialise le nombre de mot
    int nombreDeMots = 0;

    // On lit tous les mots du fichier jusqu'à la fin
    while(fgets(MotDeLaLigneCourante, sizeof(MotDeLaLigneCourante), fichier) != NULL){
        nombreDeMots++;
    }

    /// Fermer le fichier
    if(fclose(fichier)){
        perror("DicoMotus.txt");
        exit(errno);
    } 

    // On renvoit le nombre de mots
    return nombreDeMots;
}

// Rôle: écrit un mot sur la sortie standard pour effectuer des tests plus simplement
// Antécédent: s est un pointeur sur le premier caractère d'une chaîne de caractères
void ecrireMot(const char *s){
    printf("%s\n", s);
}

// Rôle: renvoie 1 si le mot de l'utilisateur et le mot a trouver ont la même longueur, 0 sinon
// Antécédent: d est un pointeur sur une donnee partagée initialisée
int memeLongueur(DonneePartagee *d){
    return d->tailleMotATrouver==strlen(d->MotUtilisateur);
}

// Rôle: renvoie 1 si le mot de l'utilisateur est le même que le mot à trouver sont les mêmes, 0 sinon
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int memeMot(DonneePartagee *d){
    return strcmp(d->MotATrouver, d->MotUtilisateur) == 0;
}

// Rôle: renvoie 1 si le mot de l'utilisateur est dans le dictionnaire, 0 sinon
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int motDansLeDictionnaire(DonneePartagee *d){
    // On ouvre le fichier "DicoMotus.txt" en lecture
    FILE *fichier = fopen("DicoMotus.txt", "r");

    if((fichier = fopen("DicoMotus.txt", "r")) == NULL){
        perror("DicoMotus.txt");
        exit(errno);
    }
    
    // On alloue de la mémoire
	char *mot=malloc(sizeof(char)*(tailleMotMax+1)); 

	// Boucle pour parcourir les mots du dictionnaire, s'arrête si le mot est trouvé
    while(fgets(mot, 11, fichier) != NULL){
        // Invariant: le mot de l'utilisateur n'est pas le même que les mots déjà parcourus dans le dictionnaire

        // On remplace le '\n' à la fin de la chaîne de caractère par '\0'
        if(mot[(strlen(mot))-1] == '\n'){
            mot[(strlen(mot))-1] = '\0';
        }

	    // On compare le mot courat du dictionnaire par le mot de l'utilisateur
        if(!strcmp(d->MotUtilisateur, mot)){
            // Le mot est dans le dictionnaire

            // Fermer le fichier
            if(fclose(fichier)){
                perror("DicoMotus.txt");
                exit(errno);
            }  

            // On libère la mémoire
            free(mot); 

            return 1; 
        }
    }

    // Fermer le fichier
    if(fclose(fichier)){
        perror("DicoMotus.txt");
        exit(errno);
    }  

    // On libère la mémoire
    free(mot); 

    return 0;
}


// Rôle: renvoie 1 si le mot est valide, 0 sinon
// Antécédent: d est un pointeur sur une donnée partagée initialisée
int motValide(DonneePartagee *d){
    // On teste si le mot entré par l'utilisateur et le mot a trouver ont la même longueur
    if(!memeLongueur(d)){
        return 0;
    }
    // On vérifie que le mot entré par l'utilisateur est bien dans le dictionnaire
    if(!motDansLeDictionnaire(d)){
        return 0;
    }
    // Le mot entré par l'utilisateur est valide
    return 1;
}

// Rôle: renvoie 1 si i-ème lettre du mot de l'utilisateur est égale à la i-ème lettre du mot à trouver
// Antécédent: d est un pointeur sur une donnée partagée initialisée et index est un entier
int compareLettre(DonneePartagee *d, const int index){
    return d->MotUtilisateur[index] == d->MotATrouver[index];
}

// Rôle: renvoie 1 si le caractère est à la mauvaise place, 0 s'il n'est pas dans le mot
// Antécédent: d est une donnée partagée initialisée et c est un charactère
int estDansLeMot(DonneePartagee *d, const char caractere){
    for(int i=0; i<(d->tailleMotATrouver); i++){
        // Il reste au moins un caractère dans la chaîne de caractère pointée par s

        // On teste si le caractère pointé par s et le caractère c sont les mêmes
        if(caractere==d->MotATrouver[i]){
            // Le caractère pointé par s est le même que le caractère c
            return 1;
        }
    }

    // Le caractère n'est pas dans le mot
    return 0;
}

// Rôle: renvoie l'indice de la premiere occurence du caractere caractere dans le mot à trouver sans prendre en compte la première lettre du mot entré par l'utilisateur
//       pour gérer l'affichage
// Antécédent: d est un pointeur sur une donnée partagée initialisée, caractère est un caractère présent dans le mot à trouver
int premiereOccurence(DonneePartagee *d, char caractere) {
    // Boucle pour parcourir les caractères du mot entré par l'utilisateur, la boucle s'arrete si le caractère caractere est le même que le caractère du mot de l'utilisateur
    for(int indice=0; indice<(d->tailleMotATrouver); indice++){
        // On teste si le caractère du mot de l'utilisateur est le même que le caractère caractère
        if(caractere==d->MotUtilisateur[indice]){
            // Le caractère du mot de l'utilisateur est le même que le caractère caractère

            // On renvoie l'indice
            return indice;
        }
    }

    // Pour faire plaisir au compilateur mais n'arrive jamais si on respecte l'antécédant
    return -1;
}

// Rôle: renvoie le nombre d'occurences du caractère caractere dans le mot entré par l'utilisateur
// Antécédent: d est un pointeur sur une donnée partagée initialisée et c est un caractère
int nombreOccurences(DonneePartagee *d, char caractere){
    // On initialise le nombre d'occurences
    int nombreOccurences=0;

    // Boucle pour compter le nombre d'occurences
    for(int i=0; i<(d->tailleMotATrouver); i++){
        // On teste si le caractère c est le même que la i-ème lettre du mot à trouver
        if(caractere==d->MotUtilisateur[i]){
            // Le caractère c est le même que la i_ème lettre du mot à trouver

            // On augmente le nombre d'occurences
            nombreOccurences++;
        }
    }
    return nombreOccurences;
}

// Rôle: renvoie l'indice de la deuxième occurence du caractère c dans le mot à trouver
// Antécédant: d est un pointeur sur une donnée partagée initialisée et c est un caractère qui est présent au moins 2 fois dans le mot à trouver
int deuxiemeOccurence(DonneePartagee *d, char c){
    // On initialise le nombre d'occurences
    int nombreOccurences=1;

    // Boucle pour trouver l'indice de la seconde occurence du caractère c dans le mot à trouver
    for(int i=0; i<(d->tailleMotATrouver); i++){
        // On teste si le caractère c est le même que la i-ème lettre du mot à trouver
        if(c==d->MotUtilisateur[i]){
            // Le caractère c est le même que la i_ème lettre du mot à trouver

            // On teste si on est à la deuxième occurence
            if(nombreOccurences==2){
                // On est à la deuxième occurence

                // 
                return i;
            }
            nombreOccurences++;
        }
    }
    return -1;

}

// Rôle: compare le mot de l'utilisateur avec le mot a trouver et actualise les indications à donner à l'utilisateur
// Antécédent: d est un pointeur sur une donnée partagée initialisée
void compareMot(DonneePartagee *d){
    // On initialise un entier pour qui nous permettra de déterminer les cases à mettre en jaune dans les cas particuliers
    int indiceJaune=-1;

    // Boucle pour parcourir tous les caractères du mot
    for (int i = 0; i < d->tailleMotATrouver; i++){
        // Invariant: il reste encore au moins un caractère du mot entré par l'utilisateur que l'on a pas parcouru

        // On teste si i est différent de 0
        if(i>0){
            // i est différent de 0 donc on ne teste pas le premier caractère du mot entré par l'utilisateur

            // On teste si le caractère du mot de l'utilisateur est dans le mot à trouver
            if(estDansLeMot(d, d->MotUtilisateur[i])){
                // Le caractère du mot de l'utilisateur est dans le mot à trouver
                if(!compareLettre(d, i)){
                    // La i-ème lettre du mot de l'utilisateur n'est pas la même que la i-ème lettre du mot à trouver

                    // On teste si ce n'est la première occurence de cette lettre dans le mot de l'utilisateur
                    if(premiereOccurence(d, d->MotUtilisateur[i]) != i){
                        // Ce n'est la première occurence de cette lettre dans le mot de l'utilisateur

                        // Pour le moment on indique que la lettre n'est pas dans le mot
                        d->indications[i] = '-';
                    } 
                    else{
                        // C'est la première occurence de la lettre dans le mot de l'utilisateur

                        // Pour le moment on indique que le mot n'est pas à la bonne place
                        d->indications[i] = 'o';
                    }
                }
                
                // On teste si la i-ème lettre du mot de l'utilisateur est la même que la i-ème lettre du mot à trouver et si le nombre d'occurence de cette lettre est au moins 2
                if(compareLettre(d, i) && nombreOccurences(d, d->MotATrouver[i])>=2){
                    // La i-ème lettre du mot de l'utilisateur est la même que la i-ème lettre du mot à trouver et si le nombre d'occurence de cette lettre est au moins 2
                    
                    // On récupère donc l'indice de la seconde occurence pour ensuite la mettre en jaune pour gérer le cas particulier où la première occurence est à la bonne 
                    // position et il y a une autre occurence de la lettre qui n'est pas à la bonne position
                    indiceJaune=deuxiemeOccurence(d, d->MotATrouver[i]);

                    // On indique que la lettre est à la bonne place
                    d->indications[i] = 'x';
                }

                // On teste si on doit mettre la lettre en jaune ( si elle n'est pas à la bonne place)
                if(i==indiceJaune){
                    // On doit indiquer que la lettre n'est pas à la bonne place donc pour le moment on la met en jaune et si elle est à la bonne place ceci sera changé dans le if suivant
                    d->indications[i] = 'o';
                }

                // On teste si la i-ème lettre du mot de l'utilisateur est la même que la i-ème lettre du mot à trouver
                if(compareLettre(d, i)){
                    // La i-ème lettre du mot de l'utilisateur est la même que la i-ème lettre du mot à trouver

                    // On indique que la lettre est à la bonne place
                    d->indications[i] = 'x';
                }
            } 

            else{
                // La lettre du mot de l'utilisateur n'est pas dans le mot à trouver
                d->indications[i] = '-';
            }
        }
        else{
            // On teste la première lettre du mot entré par l'utilisateur

            // On teste la première lettre du mot entré par l'utilisateur pour gérer le cas particulier où la première lettre de l'utilisateur est à la bonne place et il y a une seconde
            // occurence de cette lettre à la mauvaise place dans le reste du mot
            if(compareLettre(d, i) && nombreOccurences(d, d->MotATrouver[i])>=2){
                // La première lettre du mot entré par l'utilisateur est à la bonne place et a au moins 2 occurences dans le mot de l'utilisateur

                // On stocke l'index de la lettre que l'on devra mettre en jaune
                indiceJaune=deuxiemeOccurence(d, d->MotATrouver[i]);

                // On indique que la lettre est à la bonne place
                d->indications[i] = 'x';
            }
            else{
                // La première lettre du mot entré par l'utilisateur n'est pas à la bonne place ou n'a pas au moins 2 occurences dans le mot de l'utilisateur

                // On teste si la première lettre du mot entré par l'utilisateur est dans le mot
                if(estDansLeMot(d, d->MotUtilisateur[i])){
                    // La première lettre du mot entré par l'utilisateur est dans le mot

                    // On teste si la première lettre du mot entré par l'utilisateur est la même que la première lettre du mot à trouver
                    if(compareLettre(d, i)){
                        // La première lettre du mot entré par l'utilisateur est la même que la première lettre du mot à trouver

                        // On indique que la lettre est à la bonne place
                        d->indications[i] = 'x';
                    } 
                    else {
                        // La première lettre du mot entré par l'utilisateur n'est pas la même que la première lettre du mot à trouver donc on indique que la lettre est à la 
                        // mauvaise place
                        d->indications[i] = 'o';             
                    }
                } 
                else{
                    // La première lettre du mot de l'utilisateur n'est pas dans le mot donc on l'indique
                    d->indications[i] = '-';
                }
            }
        }
    }
    // On ajoute '\0' à la fin de la chaîne de caractères qui donne les indications pour marquer la fin de la chaîne de caractères
    d->indications[d->tailleMotATrouver] = '\0';
}

// Rôle: Initialise le mot a trouver comme étant un mot aléatoire du dictionnaire
// Antécédant: ligne est un entier inférieur ou égal au nombre de ligne du fichier "DicoMotus.txt", s est un pointeur sur un caractère
void MotATrouver(DonneePartagee *d){
    // On ouvre le fichier "DicoMotus.txt" en lecture
    FILE *fichier = fopen("DicoMotus.txt", "r");

    if((fichier = fopen("DicoMotus.txt", "r")) == NULL){
        perror("DicoMotus.txt");
        exit(errno);
    }

    // Création d'un entier aléatoire pour déterminer le mot que l'utilisateur devra trouver
    srand(time(NULL));
    const int nbrAleatoire=rand()%NombreMotsDansFichier();

    // On initialise une chaîne de caractères qui contiendra le mot de la ligne courante
    char MotDeLaLigneCourante[tailleMotMax+2];
    
    // On initialise le numéro de laligne
    int numeroDeLigne = 1;

    // Boucle pour parcourir tous les mots du dictionnaire jusqu'à arriver au mot de la ligne souhaitée
    while(fgets(MotDeLaLigneCourante, sizeof(MotDeLaLigneCourante), fichier) != NULL){
        // Invariant: on a pas parcouru tous les mots du fichier

        // On teste si le numéro de la ligne correspond au numéro de la ligne qui contient le mot qu'on souhaite récupérer
        if(numeroDeLigne == nbrAleatoire){
            // On teste si le numéro de la ligne correspond au numéro de la ligne qui contient le mot qu'on souhaite récupérer

            // On remplace le '\n' par un '\0' à la fin de la chaîne de caractère s'il y a un '\n' pour marquer la fin de la chaîne de caractère
            char *nouvelleLigne = strchr(MotDeLaLigneCourante, '\n');
            if (nouvelleLigne != NULL) {
                *nouvelleLigne = '\0';
            }
            
            // On récupère le mot à trouver
            strcpy(d->MotATrouver, MotDeLaLigneCourante);

            // On arrête la boucle
            break;
        }
        // On passe à la ligne suivante
        numeroDeLigne++;
    }

    // Fermer le fichier
    if(fclose(fichier)){
        perror("DicoMotus.txt");
        exit(errno);
    }  
}


