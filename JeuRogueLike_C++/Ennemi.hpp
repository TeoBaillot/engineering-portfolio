#ifndef ENNEMI_HPP
#define ENNEMI_HPP

#include <string>

class Personnage; /* Déclaration anticipée de la classe Personnage afin d'éviter les dépendances croisés car on a pas besoin de déclarer un objet personnage 
                    pour manipuler la classe personnage dans la classe ennemi, évite de faire un include de la classe Personnage qui crée des problèmes de compilation*/

// Déclaration de la classe Ennemi
class Ennemi {
private:
    std::string nom;       // Déclaration de l'attribut nom qui sera une chaîne de caractères qui représente le nom de l'ennemi
    int pointsDeVie;       // Déclaration de l'attribut pointDeVie qui sera un entier qui représente le nombre de points de vie de l'ennemi
    int attaque;           // Déclaration de l'attribut attaque qui sera un entier qui représente l'attaque de l'ennemi

public:
    // Déclaration du constructeur de la classe
    Ennemi(const std::string& nom, int pdv, int atk);

    // Déclaration de l'accesseur (la fonction) getNom qui renvoie une chaîne de caractères qui représente le nom de l'ennemi
    std::string getNom() const;

    // Déclaration de l'accesseur (la fonction) getPointsDeVie qui renvoie un entier qui représente la valeur du nombre de points de vie de l'ennemi
    int getPointsDeVie();

    // Déclaration de l'accesseur (la fonction) getAttaque qui renvoie un entier qui représente l'attaque de l'ennemi
    int getAttaque() const;

    // Déclaration de la fonction estVaincu qui renvoie un booléen qui permet de savoir si un ennemi est vaincu ou non
    bool estVaincu() const;

    // Déclaration de la méthode recevoirDegats qui permet à l'ennemi de recevoir les dégats
    void recevoirDegats(int degats);

    // Déclaration de la méthode attaquer qui permet à l'ennemi d'attaquer le personnage
    int attaquer(Personnage& personnage);
};

#endif
