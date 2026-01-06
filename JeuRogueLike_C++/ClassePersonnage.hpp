#ifndef CLASSEPERSONNAGE_HPP
#define CLASSEPERSONNAGE_HPP

#include <string> 

// Déclaration de la classe ClassePersonnage
class ClassePersonnage {
// Déclaration des attributs protégé afin qu'ils puissent être utilisés par les classes filles
protected:
    int pointsDeVieMax; // Déclaration de l'attribut pointDeVieMax qui sera un entier qui représente les points de vie maximum de la classe du personnage
    int attaque;        // Déclaration de l'attribut attaque qui sera un entier qui représente l'attaque de la classe du personnage
    std::string nomClasse; // Déclaration de l'attribut nomClasse qui sera une chaîne de caractère et qui représente le nom de la classe

public:
    // Déclaration du constructeur de la classe
    ClassePersonnage(int pdv, int atk, const std::string& nom);

    // Déclaration de l'accesseur (la fonction) getPointsDeVieMax qui renvoie un entier qui représente la valeur du nombre de points de vie maximal de la classe du personnage
    int getPointsDeVieMax() const;
        
    // Déclaration de l'accesseur (la fonction) getAttaque qui renvoie un entier qui représente la valeur de l'attaque de la classe du personnage
    int getAttaque() const;
        
    // Déclaration de l'accesseur (la fonction) getNomclass qui renvoie une chaîne de caractères qui représente le nom de la classe du personnage
    std::string getNomClasse() const;
};

#endif
