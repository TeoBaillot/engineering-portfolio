# Motus – Jeu télévisé en C avec interface graphique

## Contexte
Projet académique réalisé pour mettre en pratique les connaissances acquises en **langage C** et en programmation d’interfaces graphiques avec la **librairie libsx**.  

L’objectif était de reproduire le célèbre jeu télévisé **Motus**, où le joueur dispose de 6 tentatives pour deviner un mot. À chaque essai, le joueur obtient des indications :  
- **Rouge** : lettre correcte et bien placée  
- **Jaune** : lettre présente mais mal placée  
- **Bleu** : lettre absente du mot à trouver  

Une première version du jeu a été réalisée sans interface graphique, puis adaptée pour fonctionner avec libsx.

---

## Fonctionnalités

- **Fenêtre de démarrage** :  
  - Bouton **Jouer** pour lancer la partie  
  - Bouton **Quitter** pour fermer le programme  

- **Fenêtre de jeu** :  
  - Boutons : **Rejouer**, **Quitter**, **Aide**  
  - Zones de saisie pour :  
    - Entrer un mot à tester  
    - Indiquer si le mot est valide ou non  
    - Afficher le nombre d’essais restants  
  - Zone graphique **DrawArea** pour afficher les lettres et les indications couleur  

- Gestion des cas particuliers :  
  - Mots invalides ou de taille incorrecte  
  - Fin de partie victoire ou défaite  

- Algorithme dynamique : le jeu réagit aux actions de l’utilisateur et met à jour les données partagées et l’affichage en temps réel  

---

## Contributions personnelles
- Implémentation de la logique principale du jeu et des vérifications de validité des mots  
- Développement des interactions avec l’interface graphique (boutons, zones de saisie, DrawArea)  
- Gestion des données partagées : mot à trouver, dernier mot valide, essais restants  
- Gestion des cas particuliers et amélioration de la robustesse de l’application  

---

## Technologies utilisées
- **Langage C** : logique, structures de données, gestion des événements  
- **LibSX** : interface graphique et interactions utilisateur  
- **Makefile** : compilation et exécution  

---

## Utilisation

1. Placer tous les fichiers du projet dans un même répertoire  
2. Ouvrir un terminal et exécuter :  
   ```bash
   make
3. Lancer le jeu avec:
  ./motus


## Limitations
- Certaines occurrences multiples de lettres ne sont pas parfaitement gérées.  
- La résolution d’écran peut affecter la visibilité des zones de saisie.  
- Le dictionnaire n’inclut pas tous les mots courants de la langue française, ce qui peut rendre certains mots valides impossibles à deviner.

---

## Améliorations possibles
- Fonction d’indications plus précise pour tous les cas particuliers.  
- Ajout de plusieurs niveaux de difficulté pour permettre à l’utilisateur de choisir son challenge.  
- Amélioration du design de l’interface pour la rendre plus agréable et intuitive.  
- Fonctionnalité permettant à l’utilisateur d’ajouter des mots personnalisés au dictionnaire avant de commencer une partie.  
- Optimisation de l’ergonomie pour différentes résolutions d’écran.

---

## Conclusion
Ce projet a été un challenge enrichissant qui a permis de **mettre en pratique les connaissances en C et en programmation graphique**, d’améliorer l’ergonomie et la robustesse d’une application interactive, et de gérer des cas utilisateurs complexes. Il a également permis de développer l’autonomie, la recherche de solutions et la capacité à rendre un projet fonctionnel et agréable dans un temps imparti.
