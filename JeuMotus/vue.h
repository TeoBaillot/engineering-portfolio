// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/05/2024
// Date de dernière modification: 09/06/2024

#pragma once

// Widget zone de saisie pour récupérer les mots entrés par l'utilisateur
extern Widget ZoneSaisieUtilisateur;

// Widget zone de saisie pour affiche un message indiquant à l'utilisateur si son mot est valide ou non
extern Widget ZoneSaisieValideInvalide;

// Widget zone de saisie pour afficher à l'utilisateur le nombre d'essais restants
extern Widget ZoneSaisieNombreEssaisRestants;

// Widget DrawArea pour afficher des mots et des indications en fonction des actions de l'utilisateur
extern Widget DrawArea;


// Widget pour lancer la première partie
extern Widget BJouer; 

// Rôle: crée la fenêtre de démarrage
extern void fenetreDemarrage(int, char *[], void *);

// Rôle: crée la fenêtre de jeu
extern void fenetrePrincipale(void *);

// Rôle: crée la fenêtre lorsque la partie est gagnée
extern void fenetreGagnant(void *);

// Rôle: crée la fenêtre lorsque la partie est perdu
extern void fenetrePerdant(void *, char *);

// Rôle: crée la fenêtre d'aide
extern void fenetreAide(void);

// Rôle: crée la fenêtre d'erreur
extern void fenetreErreur(void);