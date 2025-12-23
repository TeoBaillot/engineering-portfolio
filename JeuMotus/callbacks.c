// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/05/2024
// Date de dernière modification: 09/06/2024


#include <stdlib.h>
#include <stdio.h> 
#include <libsx.h>
#include "data.h"
#include "vue.h"
#include "callbacks.h"


/* Callback bouton jouer. 
 * Rôle : lancer la partie
 */
void jouer(Widget w, void *d){
  // On bloque le bouton jouer une fois qu'il a été cliqué une fois pour éviter que l'utilisateur revienne sur l'écran de démarrage et ouvre d'autres fenêtres de jeu ce qui poserait problème
  SetWidgetState(BJouer, 0);

  // On ouvre la fenêtre principale (la fenêtre du jeu)
  fenetrePrincipale(d);
}

// Rôle: affiche dans la zone de saisie ZoneSaisieNombreEssaisRestants le nombre d'essais restants
void afficherNombreEssaisRestants(int essais){
  // On définit une chaîne de caractère qui contiendra l'entier cconverti en chaîne de caractères
  char s[2]; 

  // On définit une chaîne de caractères qui contiendra la chaîne de caractères à afficher
  char affichage[30];

  // On converti l'entier en chaîne de caractère et on stocke le résultat dans s
  sprintf(s, "%d", essais);

  // On crée le message finale à afficher
  strcpy(affichage, "Il vous reste ");
  strcat(affichage, s);
  strcat(affichage, " essais");
  
  // On écrit ce qu'on veut afficher dans la zone de saisie Zone SaisieNombreEssaisRestants
  SetStringEntry(ZoneSaisieNombreEssaisRestants, affichage);
}

/* Callback. 
 * Rôle : initialiser la zone de dessin de la fenêtre de jeu
 */
void initialisation(Widget w, int a, int b, void *d){
  // On définit les couleurs
  const int rouge=GetRGBColor(255, 0, 0);
  const int vert=GetRGBColor(172, 255, 51);
  const int noir=GetRGBColor(0, 0, 0);

  // On crée une chaîne de caractère contenant un seul caractère et le caractère de fin de chaîne pour pouvoir utiliser la fonction DrawText
  char premiereLettre[2];
  premiereLettre[0]=getMotATrouver(d)[0];
  premiereLettre[1]='\0';

  // On crée une chaîne de caractère contenant un seul caractère et le caractère de fin de chaîne pour pouvoir utiliser la fonction DrawText
  char tiret[2];
  tiret[0]='-';
  tiret[1]='\0';

  // Boucle pour initialiser l'affichage du jeu
  for(int i=0; i<getTailleMotATrouver(d); i++){
    // Invariant: on a affiché un nombre de caractère inférieur au nombre de caractères du mot à trouver

    // On teste si on veut afficher le premier caractère
    if(i>0){
      // On ne veut pas afficher le premier caractère

      // On définit la couleur de la boite
      SetColor(vert);

      // On dessine la boite
      DrawFilledBox(80* i+5, 5, 75, 75);

      // On définit la couleur du caractère
      SetColor(noir);

      // On définit la couleur de l'arrière plan du caractère
      SetBgColor(DrawArea, vert);

      // On affiche le caractère
      DrawText(tiret, 38 +80* i, 43);
    }
    else{
      // On veut afficher le premier caractère
      SetColor(rouge);
      
      // On dessine la boite
      DrawFilledBox(80* i+5, 5, 75, 75);

      // On définit la couleur du caractère
      SetColor(noir);

      // On définit la couleur du fond du caractère
      SetBgColor(DrawArea, rouge);

      // On affiche le caractère
      DrawText(premiereLettre, 38, 43);
    }
  }
  // On affiche le nombre d'essais
  afficherNombreEssaisRestants(nombreEssaiMax);
}

/* Callback bouton quitter. 
 * Rôle : terminer l'application 
 */
void quitter(Widget w, void *d) {
  // On ferme le jeu
  exit(EXIT_SUCCESS);
}

/* Rôle : affiche dans la zone de saisie ZoneSaisieValideInvalide la chaîne de caractère dont le premier caractère est pointé par s
 */ 
void afficherValideInvalide(char *s){
  // On écrit dans la zone de saisie ZoneSaisieValideInvalide
  SetStringEntry(ZoneSaisieValideInvalide,s);
}

/* Callback bouton aide. 
 * Rôle : ouvrir la fenêtre d'aide
 */
void aide(Widget w, void *d){
  // On affiche la fenêtre d'aide
  fenetreAide();
}

/* Callback bouton rejouer. 
 * Rôle : relancer la partie
 */
void rejouer(Widget w, void *d){
  // On ferme la fenêtre du jeu
  CloseWindow();

  // On réinitialise nos données partagées
  initDonneePartagee(d);

  // On réouvre la fenêtre principale du jeu
  fenetrePrincipale(d);
}

/* Callback bouton valider. 
 * Rôle : gère l'essai de l'utilisateur lorsqu'il entre un mot
 */
void valider(Widget w, void *d) {
  // On définit des couleurs
  const int rouge=GetRGBColor(255, 0, 0);
  const int vert=GetRGBColor(172, 255, 51);
  const int orange=GetRGBColor(255, 160, 0);
  const int bleu=GetRGBColor(103, 208, 236);
  const int noir=GetRGBColor(0, 0, 0);

  // On teste si la taille du mot entré par l'utilisateur est trop grande pour éviter une segmentation fault
  if(strlen(GetStringEntry(ZoneSaisieUtilisateur))>tailleMotMax+1){
    // La taille du mot entré par l'utilisateur est trop grande

    // On remplace le mot qui correspondra au mot de l'utilisateur par une chaîne de caractères vide qui déclenchera le fait que le mot est invalide
    SetStringEntry(ZoneSaisieUtilisateur,"");
  }

  // On récupère le mot entré par l'utilisateur dans les données partagées
  setMotUtilisateur(d, GetStringEntry(ZoneSaisieUtilisateur));


  // On efface le contenu de la zone de saisie de l'utilisateur
  SetStringEntry(ZoneSaisieUtilisateur,"");

  // On initialise un pointeur sur une chaîne de caractères qui pointe sur le premier caractère du mot entré par l'utilisateur
  char *motUtilisateur=getMotUtilisateur(d);

  // On teste si le mot entré par l'utilisateur est valide
  if(motValide(d)){
    // Le mot entré par l'utilisateur est valide

    // On signale à l'utilisateur que son mot est bien valide
    afficherValideInvalide("Felicitation, votre mot est valide");

    // On change la valeur du booléen dans la donnée partagée qui indique si le ou les premiers mots entrés par l'utilisateur sont invalides
    setPremierMotsInvalides(d);
    
    // On actualise le pointeur qui pointe sur le premier caractère du dernier mot valide entré par l'utilisateur
    setDernierMotValide(d, motUtilisateur);

    // On actualise le pointeur qui pointe sur le premier caractère de la chaîne de caractère qui donne des indications sur le mot
    compareMot(d);

    // On compare le mot entré par l'utilisateur avec le mot à trouver
    if(memeMot(d)){
      // Le mot entré par l'utilisateur est le même que le mot à trouver
      
      // On ferme la fenêtre du jeu pour ne pas qu'il y en ait 2 ouvertes en même temps si l'utilisateur clique sur rejouer ce qui pourrait poser problème
      CloseWindow();

      // On affiche la fenêtre pour dire à l'utilisateur qu'il a gagné
      fenetreGagnant(d);
    }

    // Le mot entré par l'utilisateur n'est pas le même que le mot à trouver

    // Boucle pour actualiser l'affichage de la fenêtre de jeu
    for(int i=0; i<getTailleMotATrouver(d); i++){
      // Invariant: il manque au moins un caractère à afficher

      // On crée une chaîne de caractère contenant un seul caractère et le caractère de fin de chaîne pour pouvoir utiliser la fonction DrawText
      char caractere[2];
      caractere[0]=motUtilisateur[i];
      caractere[1]='\0';

      // On étudie les différents cas en fonction du caractère de l'indication
      switch(getIndications(d)[i]){
        case 'o': SetColor(orange);SetBgColor(DrawArea, orange);break; // La lettre est mal placée, on change la couleur de la boite et la couleur de fond du caractère en conséquences
        case '-': SetColor(bleu);SetBgColor(DrawArea, bleu); break; // La lettre n'est pas dans le mot à trouver, on change la couleur de la boite et la couleur de fond du caractère en conséquences
        case 'x': SetColor(rouge);SetBgColor(DrawArea, rouge); break; // La lettre est à la bonne place, on change la couleur de la boite et la couleur de fond du caractère en conséquences
        default: fenetreErreur();break;  // Cas où il y a une erreur donc on ouvre une fenêtre d'erreur
      }

      // On dessine la boite
      DrawFilledBox(80* i+5, 80*(getNumeroEssais(d))+5, 75, 75);

      // On définit la couleur du caractère
      SetColor(noir);

      // On affiche le caractère
      DrawText(caractere, 38 +80* i, 43+(getNumeroEssais(d))*80);
    }
  }
  // On teste si le mot est invalide après que l'utilisateur est rentré un mot valide
  else if(!motValide(d) && !getPremierMotsInvalides(d)){
    // Le mot de l'utilisateur est invalide mais il avait rentré un mot valide dans un des essais précédents

    // On ne change pas l'affichage mais on signal à l'utilisateur que son mot n'est pas valide
    afficherValideInvalide("Le mot est invalide, reessayez");

    // Boucle pour gérer l'affichage
    for(int i=0; i<getTailleMotATrouver(d); i++){
      // Invariant: il reste encore au moins un mot à afficher

      // On crée une chaîne de caractère contenant un seul caractère et le caractère de fin de chaîne pour pouvoir utiliser la fonction DrawText
      char caractere[2];
      caractere[0]=getDernierMotValide(d)[i];
      caractere[1]='\0';

      // On gère l'affichage en fonction de l'indication
      switch(getIndications(d)[i]){
        case 'o': SetColor(orange);SetBgColor(DrawArea, orange);break; // La lettre est mal placée, on change la couleur de la boite et la couleur de fond du caractère en conséquences
        case '-': SetColor(bleu);SetBgColor(DrawArea, bleu); break; // La lettre n'est pas dans le mot à trouver, on change la couleur de la boite et la couleur de fond du caractère en conséquences
        case 'x': SetColor(rouge);SetBgColor(DrawArea, rouge); break; // La lettre est à la bonne place, on change la couleur de la boite et la couleur de fond du caractère en conséquences
        default: fenetreErreur();break; // Cas où il y a une erreur donc on ouvre une fenêtre d'erreur
      }

      // On dessine la boîte
      DrawFilledBox(80* i+5, 80*(getNumeroEssais(d))+5, 75, 75);

      // On définit la couleur du caractère
      SetColor(noir);

      // On affiche le caractère
      DrawText(caractere, 38 +80* i, 43+(getNumeroEssais(d))*80);
    }
      // On teste s'il reste des essais à l'utilisateur
    if(getNombreEssaisRestants(d)-1==0){
      // L'utilisateur n'a plus d'essais

      // On ferme la fenêtre du jeu
      CloseWindow();

      // On crée le message à afficher
      char *messagePerdant=malloc(sizeof(char)*(getTailleMotATrouver(d)+100));
      messagePerdant[0]='\0';
      strcat(messagePerdant, "\n\n\n\n\n          Dommage, vous avez perdu.\n\n        Le mot a trouver etait: ");
      strcat(messagePerdant, getMotATrouver(d));
      strcat(messagePerdant, "          \n\n\n\n\n");
        
      // On ouvre la fenêtre qui indique à l'utilisateur qu'il a perdu
      fenetrePerdant(d, messagePerdant);

      // On libère la mémoire
      free(messagePerdant);
    }
  }
  // On teste si le mot est invalide et l'utilisateur n'a pas rentré de mot valide dans un de ses essais précédents
  else if(!motValide(d) && getPremierMotsInvalides(d)){
    // Le mot de l'utilisateur est invalide et il n'a pas rentré de mot valide dans un de ses essais précédents

    // On signale à l'utilisateur que son mot est invalide
    afficherValideInvalide("Le mot est invalide, reessayez");

    // On crée une chaîne de caractère contenant un seul caractère et le caractère de fin de chaîne pour pouvoir utiliser la fonction DrawText
    char premiereLettre[2];
    premiereLettre[0]=getMotATrouver(d)[0];
    premiereLettre[1]='\0';

    // On crée une chaîne de caractère contenant un seul caractère et le caractère de fin de chaîne pour pouvoir utiliser la fonction DrawText
    char tiret[2];
    tiret[0]='-';
    tiret[1]='\0';

    // Boucle pour gérer l'affichage
    for(int i=0; i<getTailleMotATrouver(d); i++){
      // On teste si on veut afficher le premier caractère
      if(i>0){
        // On ne veut pas afficher le premier caractère

        // On définit la couleur de la boite
        SetColor(vert);

        // On dessine la boite
        DrawFilledBox(80* i+5, 80*(getNumeroEssais(d))+5, 75, 75);

        // On définit la couleur du caractère
        SetColor(noir);

        // On définit la couleur de fond du caractère
        SetBgColor(DrawArea, vert);

        // On affiche le caractère
        DrawText(tiret, 38 +80* i, 43+(getNumeroEssais(d))*80);
      }
      else{
        // On veut afficher le premier caractère

        // On définit la couleur de la boite
        SetColor(rouge);
        
        // On dessine la boite
        DrawFilledBox(80* i+5, 80*(getNumeroEssais(d))+5, 75, 75);

        // On définit la couleur du caractère
        SetColor(noir);

        // On définit la couleur de fond du caractère
        SetBgColor(DrawArea, rouge);

        // On affiche le caractère
        DrawText(premiereLettre, 38, 43+(getNumeroEssais(d))*80);
      }
    }
      // On teste s'il reste des essais à l'utilisateur
    if(getNombreEssaisRestants(d)-1==0){
      // L'utilisateur n'a plus d'essais

      // On ferme la fenêtre du jeu
      CloseWindow();

      // On crée le message à afficher
      char *messagePerdant=malloc(sizeof(char)*(getTailleMotATrouver(d)+100));
      messagePerdant[0]='\0';
      strcat(messagePerdant, "\n\n\n\n\n          Dommage, vous avez perdu.\n\n        Le mot a trouver etait: ");
      strcat(messagePerdant, getMotATrouver(d));
      strcat(messagePerdant, "          \n\n\n\n\n");
        
      // On ouvre la fenêtre qui indique à l'utilisateur qu'il a perdu
      fenetrePerdant(d, messagePerdant);

      // On libère la mémoire
      free(messagePerdant);
    }
  }
  // On décrémente le nombre d'essais restants
  decrementeNombreEssaisRestants(d);

  // On signale à l'utilisateur le nombre d'essais qu'il lui reste
  afficherNombreEssaisRestants(getNombreEssaisRestants(d));
}

