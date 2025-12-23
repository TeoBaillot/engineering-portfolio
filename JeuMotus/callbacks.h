// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/05/2024
// Date de dernière modification: 01/06/2024

#pragma once

// Rôle : terminer l'application 
extern void quitter(Widget, void *);

// Rôle : ouvrir la fenêtre d'aide
extern void aide(Widget, void *);

// Rôle : initialiser la zone de dessin de la fenêtre de jeu
extern void initialisation(Widget, int, int, void *);

// Rôle : gère l'essai de l'utilisateur lorsqu'il entre un mot
extern void valider(Widget, void *);

// Rôle : relancer la partie
extern void rejouer(Widget, void *);

// Rôle : lancer la partie
extern void jouer(Widget, void *);

// Rôle : affiche dans la zone de saisie ZoneSaisieValideInvalide la chaîne de caractère dont le premier caractère est pointé par s
extern void afficherValideInvalide(char *);
