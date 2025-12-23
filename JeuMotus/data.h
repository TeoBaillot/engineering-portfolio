// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/06/2024
// Date de dernière modification: 06/06/2024


#pragma once

#define nombreEssaiMax 6
#define tailleMotMax 10

// Définition des données partagées qui contiennent: un pointeur sur le premier caractère du mot à trouver, un pointeur sur le premier caractère du mot de l'utilisateur
//, un entier qui représente la taille du mot à trouver, un entier qui représente le numéro de l'essai de l'utilisateur, un entier bouléen qui indique si le ou les premiers 
// mots entré par l'utilisateur sont valide, un pointeur sur le première caractère du dernier mot valide entré par l'utilisateur, un pointeur sur le premier caractère de la
// chaîne de caractères qui permettra de donner des indications à l'utilisateur
typedef struct {
  char *MotATrouver;
  char *MotUtilisateur;
  int tailleMotATrouver;
  int numeroEssai;
  int premiersMotsInvalides;
  char *dernierMotValide;
  char *indications;
} DonneePartagee;

// Rôle: Initialise les données partagées
extern void initDonneePartagee(DonneePartagee *);

// Rôle: Actualise le mot entré par l'utilisateur au dernier mot entré par l'utilisateur
extern void setMotUtilisateur(DonneePartagee *, char* );

// Rôle: Décrémente le nombre d'essais restants
extern void decrementeNombreEssaisRestants(DonneePartagee *);

// Rôle: Renvoit un pointeur sur le premier caractère du mot à trouver
extern char* getMotATrouver(DonneePartagee *);

// Rôle: Renvoit le mot de l'utilisateur
extern char* getMotUtilisateur(DonneePartagee *);

// Rôle: Renvoit le nombre d'essais restants
extern int getNombreEssaisRestants(DonneePartagee *);

// Rôle: Renvoit la taille du mot à trouver
extern int getTailleMotATrouver(DonneePartagee *);

// Rôle: renvoit le nombre de mots contenus dans un fichier
extern int NombreMotsDansFichier(void);

// Rôle: écrit un mot sur la sortie standard pour effectuer des tests plus simplement
extern void ecrireMot(const char *);

// Rôle: renvoie 1 si le mot de l'utilisateur est le même que le mot à trouver sont les mêmes, 0 sinon
extern int memeMot(DonneePartagee *);

// Rôle: renvoie 1 si le mot de l'utilisateur et le mot a trouver ont la même longueur, 0 sinon
extern int memeLongueur(DonneePartagee *);

// Rôle: renvoie 1 si le mot de l'utilisateur est dans le dictionnaire, 0 sinon
extern int motDansLeDictionnaire(DonneePartagee *);

// Rôle: renvoie 1 si le mot est valide, 0 sinon
extern int motValide(DonneePartagee *);

// Rôle: renvoie 1 si le caractère est à la mauvaise place, 0 s'il n'est pas dans le mot
extern int estDansLeMot(DonneePartagee *, const char);

// Rôle: renvoie 1 si i-ème lettre du mot de l'utilisateur est égale à la i-ème lettre du mot à trouver
extern int compareLettre(DonneePartagee *, const int);

// Rôle: compare le mot de l'utilisateur avec le mot a trouver et actualise les indications à donner à l'utilisateur
extern void compareMot(DonneePartagee *);

// Rôle: Initialise le mot a trouver comme étant un mot aléatoire du dictionnaire
extern void MotATrouver(DonneePartagee *);

// Rôle: Renvoie le nombre d'essais restants
extern int getNombreEssaisRestants(DonneePartagee *);

// Rôle: Renvoit le numéro de l'essai
extern int getNumeroEssais(DonneePartagee *);

// Rôle: Renvoit un pointeur sur le premier caractère du mot caché
extern char *MotCache(DonneePartagee *d);

// Rôle: Renvoit le booléen qui indique si l'utilisateur a déjà rentré un mot valide depuis le début de la partie
extern int getPremierMotsInvalides(DonneePartagee *d);

// Rôle: Change la valeur du booléen indiquant si le ou les premiers mots entrés par l'utilisateurs sont invalides pour le passer à 0
extern void setPremierMotsInvalides(DonneePartagee *d);

// Rôle: Actualise le dernier mot valide entré par l'utilisateur
extern void setDernierMotValide(DonneePartagee *, char *);

// Rôle: Renvoit un pointeur sur le premier caractère du dernier mot valide
extern char *getDernierMotValide(DonneePartagee *);

// Rôle: Renvoit un pointeur sur le premier caractère de la chaîne de caractères qui donne les indications
extern char *getIndications(DonneePartagee *);

// Rôle: renvoie l'indice de la premiere occurence du caractere caractere dans le mot à trouver sans prendre en compte la première lettre du mot entré
// par l'utilisateur pour gérer l'affichage
extern int premiereOccurence(DonneePartagee *d, char);

// Rôle: renvoie le nombre d'occurences du caractère caractere dans le mot entré par l'utilisateur
extern int nombreOccurences(DonneePartagee *, char);

// Rôle: renvoie l'indice de la deuxième occurence du caractère c dans le mot à trouver
extern int deuxiemeOccurence(DonneePartagee *, char);