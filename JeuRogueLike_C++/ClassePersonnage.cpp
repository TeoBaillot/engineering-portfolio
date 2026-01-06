#include "ClassePersonnage.hpp"


/*  Description : Définition du constructeur de la classe
    Paramètre: pdv est un entier qui représente les points de vie maximal de la classe du personnage, atk est un entier qui représente l'attaque de la classe du personnage,
               nom est une référence constante sur une chaîne de caractère qui représente le nom de la classe du personnage.
*/
ClassePersonnage::ClassePersonnage(int pdv, int atk, const std::string& nom)
    : pointsDeVieMax(pdv), attaque(atk), nomClasse(nom) {}

/*  Description : Définition de l'accesseur (la fonction) getPointsDeVieMax qui permet de renvoyer la valeur des points de vie maximum de la classe du personnage
    Retour : Renvoie un entier pointsDeVieMax qui représente la valeur des points de vie maximum de la classe du personnage
*/
int ClassePersonnage::getPointsDeVieMax() const { 
    return pointsDeVieMax; 
}

/*  Description : Définition de l'accesseur (la fonction) getAttaque qui permet de renvoyer la valeur de l'attaque de la classe du personnage
    Retour : Renvoie un entier attaque qui représente la valeur de l'attaque de la classe du personnage
*/
int ClassePersonnage::getAttaque() const { 
    return attaque; 
}

/*  Description : Définition de l'accesseur (la fonction) getNomClasse qui permet de récupérer le nom de la classe du personnage
    Retour : Renvoie une chaîne de caractère qui représente le nom de la classe
*/
std::string ClassePersonnage::getNomClasse() const { 
    return nomClasse; 
}
