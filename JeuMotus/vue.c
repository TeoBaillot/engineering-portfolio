// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/05/2024
// Date de dernière modification: 09/06/2024


#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"

#define TAILLEZONEAFFICHAGE 250 //globale pr y avoir acces dans getstring par exemple

// Définition de Widget globaux pour les utiliser dans les callbacks
Widget ZoneSaisieUtilisateur;  // Zone de saisie pour récupérer le mot entré par l'utilisateur
Widget ZoneSaisieValideInvalide; // Zone de saisie pour afficher si le mot de l'utilisateur est valide ou non
Widget ZoneSaisieNombreEssaisRestants; // Zone de saisie pour afficher le nombre d'essais restants
Widget DrawArea;
Widget BJouer;        // Bouton pour lancer la partie

// Rôle: crée la fenêtre de démarrage
void fenetreDemarrage(int argc, char *argv[], void *d){
   Widget 
    BQuitter,      // Bouton pour terminer le programme     
    labelTitre;    // Label pour afficher le titre

  // Création des composants graphiques
  labelTitre=MakeLabel("\n\n\n\n\n                                   MOMOMOMOTUS\n\n\n\n\nBienvenue dans ce jeu Motus concu par Teo Baillot d Estivaux et Simon Leguilloux.\n\nPour lancer la partie appuyez sur jouer, et si vous avez besoin d informations\nsur le jeu pensez a cliquer sur le bouton aide.\n\n\n\n\n");
  BQuitter=MakeButton("\n                 Quitter                \n\n",quitter,NULL); //2e parametre c'est le callback pr quitter
  BJouer=MakeButton("\n                   Jouer                \n\n",jouer,d);

  // Initialisation de la police
  XFont police = GetFont("8x16"); 
  SetWidgetFont(labelTitre,police);
  SetWidgetFont(BQuitter,police);
  SetWidgetFont(BJouer,police);
  
  // assemblage des widgets
  SetWidgetPos(BJouer,PLACE_UNDER,labelTitre,NO_CARE,NULL);
  SetWidgetPos(BQuitter,PLACE_UNDER,labelTitre,PLACE_RIGHT,BJouer);

  // Gestion des couleurs
  GetStandardColors();
  // Affichage de la fenêtre
  ShowDisplay();
}

// Rôle: crée la fenêtre de jeu
void fenetrePrincipale(void *d){
  MakeWindow("Jeu", SAME_DISPLAY, 0);

   Widget 
    BQuitter,       // Bouton pour terminer le programme   
    BAide,          // Bouton pour ouvir la fenêtre d'aide
    BValider,       // Bouton pour que l'utilisateur valide le mot qu'il a écrit
    BRejouer,       // Bouton pour relancer une partie
    labelZoneSaisie,// Label pour indiquer a l'utilisateur dans quelle zone de saisie il doit écrire
    labelPourAffichage1,
    labelPourAffichage2,
    labelPourAffichage3;

  // Création des composants graphiques
  ZoneSaisieUtilisateur=MakeStringEntry("",TAILLEZONEAFFICHAGE,NULL,NULL);
  BQuitter=MakeButton("\nQuitter\n\n",quitter,NULL); //2e parametre c'est le callback pr quitter: quit
  BAide=MakeButton("\nAide\n\n",aide,NULL); //d c'est la structure de donnes partagee
  BValider=MakeButton("\nValider\n\n",valider,d); //on peut mettre les deuc dernier parametres a NULL pr tester que un seul qu'on ne met pas a NULL
  BRejouer=MakeButton("\nRejouer\n\n",rejouer,d);
  labelZoneSaisie= MakeLabel("\n  Entrez un mot:\n");
  DrawArea = MakeDrawArea(810, 570, initialisation, d);
  ZoneSaisieValideInvalide=MakeStringEntry("",TAILLEZONEAFFICHAGE,NULL,NULL);
  ZoneSaisieNombreEssaisRestants=MakeStringEntry("\nIl vous reste 6 essais\n",200,NULL,NULL);
  labelPourAffichage1=MakeLabel("");
  labelPourAffichage2=MakeLabel("");
  labelPourAffichage3=MakeLabel("");
  
  // Initialisation de la police
  XFont police = GetFont("8x16"); 
  SetWidgetFont(DrawArea,police);
  SetWidgetFont(BQuitter,police);
  SetWidgetFont(BAide,police);
  SetWidgetFont(BValider,police);
  SetWidgetFont(BRejouer,police);
  SetWidgetFont(labelZoneSaisie,police);

  

  // assemblage des widgets
  SetWidgetPos(labelPourAffichage1, PLACE_RIGHT, labelZoneSaisie, PLACE_UNDER, DrawArea); //zone saisie utilisateur
  SetWidgetPos(labelPourAffichage2, PLACE_RIGHT, ZoneSaisieNombreEssaisRestants, PLACE_UNDER, DrawArea);// zone valide invalide
  SetWidgetPos(labelPourAffichage3, PLACE_RIGHT, BAide, PLACE_UNDER, DrawArea); // zone essais restants
  SetWidgetPos(ZoneSaisieUtilisateur, PLACE_RIGHT, labelZoneSaisie, PLACE_UNDER, labelPourAffichage1);
  SetWidgetPos(ZoneSaisieValideInvalide, PLACE_RIGHT, ZoneSaisieNombreEssaisRestants, PLACE_UNDER, labelPourAffichage2);
  SetWidgetPos(ZoneSaisieNombreEssaisRestants, PLACE_RIGHT, BAide, PLACE_UNDER, labelPourAffichage3);
  SetWidgetPos(BQuitter, PLACE_UNDER, DrawArea, NO_CARE, NULL);
  SetWidgetPos(BRejouer, PLACE_RIGHT, BQuitter, PLACE_UNDER, DrawArea);
  SetWidgetPos(BAide, PLACE_RIGHT, BRejouer, PLACE_UNDER, DrawArea);
  SetWidgetPos(labelZoneSaisie, PLACE_RIGHT, ZoneSaisieValideInvalide, PLACE_UNDER, DrawArea);
  SetWidgetPos(BValider, PLACE_RIGHT, ZoneSaisieUtilisateur, PLACE_UNDER, DrawArea);

  // Gestion des couleurs
  GetStandardColors();

  // Affichage de la fenêtre
  ShowDisplay();
}

// Rôle: crée la fenêtre lorsque la partie est gagnée
void fenetreGagnant(void *d){
  MakeWindow("Vous avez gagne", SAME_DISPLAY, EXCLUSIVE_WINDOW);

   Widget 
    BQuitter,      // Bouton pour terminer l'exécution     
    BRejouer,      // Bouton pour relancer une partie
    labelGagnant;  // Label pour afficher un message au gagnant

  // Création des composants graphiques
  labelGagnant=MakeLabel("\n\n\n\n\n          Bravo, vous avez gagne!         \n\n\n\n\n");
  BQuitter=MakeButton("\n       Quitter       \n\n",quitter,NULL); //2e parametre c'est le callback pr quitter
  BRejouer=MakeButton("\n       Rejouer       \n\n",rejouer,d);
  
  // Initialisation de la police
  XFont police = GetFont("8x16"); 
  SetWidgetFont(BQuitter,police);
  SetWidgetFont(BRejouer,police);
  SetWidgetFont(labelGagnant,police);

  // assemblage des widgets
  SetWidgetPos(BRejouer,PLACE_UNDER,labelGagnant,NO_CARE,NULL);
  SetWidgetPos(BQuitter,PLACE_UNDER,labelGagnant,PLACE_RIGHT,BRejouer);

  // Gestion des couleurs
  GetStandardColors();

  // Affichage de la fenêtre
  ShowDisplay();
}

// Rôle: crée la fenêtre lorsque la partie est perdu
void fenetrePerdant(void *d, char *messagePerdant){
  MakeWindow("Vous avez perdu", SAME_DISPLAY, EXCLUSIVE_WINDOW);
   Widget 
    BQuitter,      // le  bouton Quit pour terminer le programme      
    BRejouer,
    labelPerdant;

  // Création des composants graphiques
  labelPerdant=MakeLabel(messagePerdant);
  BQuitter=MakeButton("\n         Quitter         \n\n",quitter,NULL); //2e parametre c'est le callback pr quitter
  BRejouer=MakeButton("\n         Rejouer         \n\n",rejouer,d);
  
  // Initialisation de la police
  XFont police = GetFont("8x16"); 
  SetWidgetFont(BQuitter,police);
  SetWidgetFont(BRejouer,police);
  SetWidgetFont(labelPerdant,police);

  // assemblage des widgets
  SetWidgetPos(BRejouer,PLACE_UNDER,labelPerdant,NO_CARE,NULL);
  SetWidgetPos(BQuitter,PLACE_UNDER,labelPerdant,PLACE_RIGHT,BRejouer);

  // Gestion des couleurs
  GetStandardColors();

  // Affichage de la fenêtre
  ShowDisplay();
}

// Rôle: crée la fenêtre d'aide
void fenetreAide() {
  MakeWindow("Aide", SAME_DISPLAY, EXCLUSIVE_WINDOW);

  // Création des composants graphiques
  Widget labelAide=MakeLabel("Motus est un jeu televise francais populaire dont le but est de trouver un mot. Voici les regles de base : \n\n1-Le jeu : \nVotre but est de deviner un mot mystere de notre dictionnaire en un maximum de 6 tentatives.\n\n2-Le tableau : \nLe jeu se deroule sur un tableau ou chaque ligne represente une lettre du mot mystere. \nToutes les lettres du mot sont cachees au debut du jeu sauf la premiere.\n\n3-Les propositions : \nA chaque tentative, vous entrez un mot. Le mot est affiche sur le tableau, avec des indications sur la presence des lettres correctes dans le mot mystere dans le cas ou votre mot est valide.\nSi ce n’est pas le cas, nous vous le signalerons et vous devrez entrer un nouveau mot. Tout mot n ayant pas le meme nombre de lettres que le mot a trouve ou ne se trouvant pas dans notre\ndictionnaire sera considere comme invalide.\n\n4-Les indications : \nSi une lettre proposee est correcte et bien placee dans le mot mystere, elle est affichee en rouge.\nSi elle est correcte mais mal placee, elle est affichee en jaune. Si elle n'est pas presente dans le mot mystere, elle est affichee en bleu.\nAttention, si une lettre est affichee en orange, ceci signifie qu'il y a une ou plusieurs occurences de cette lettre qui sont mal placees dans le mot que vous avez rentre.\nDe plus, si deux occurrences d une lettre sont a la bonne place et que dans la suite du mot que vous avez saisi il y a d autres occurrences de ces lettres qui ne sont\npas a la bonne place, celle-ci ne seront pas affichee en orange.\n\nLe but de ce jeu est de vous amuser et de vous challengez alors il ne nous reste plus qu’a vous souhaiter bonne chance!\n");

  // Initialisation de la police
  XFont police = GetFont("8x16"); 
  SetWidgetFont(labelAide,police);

  // Gestion des couleurs
  GetStandardColors();
  // pour afficher l'interface 
  ShowDisplay();
}

// Rôle: crée la fenêtre d'erreur
void fenetreErreur(){
  MakeWindow("Erreur", SAME_DISPLAY, EXCLUSIVE_WINDOW);

  // Création des composants graphiques
  Widget labelErreur=MakeLabel("\n\n\n\n\n          Erreur          \n\n\n\n\n"); 

  // Initialisation de la police
  XFont police = GetFont("8x16"); 
  SetWidgetFont(labelErreur,police);
  
  // Gestion des couleurs
  GetStandardColors();

  // Affichage de la fenêtre 
  ShowDisplay();
}