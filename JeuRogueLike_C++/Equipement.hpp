#ifndef EQUIPEMENT_HPP  
#define EQUIPEMENT_HPP  

#include <string>  
#include <cstdlib>  
#include <ctime>    
#include <iostream> 


// Déclaration de la classe Equipement
class Equipement {
public:
    // Déclaration d'une énumération qui définit les trois types d'équipement possibles
    enum class Type { Casque, Armure, Arme };

    // Déclaration du constructeur de la classe
    Equipement(const std::string& nom, int effet, Type type);

    // Déclaration de l'accesseur (la fonction) getNom qui renvoie une chaîne de caractères qui représente le nom de l'équipement
    std::string getNom() const; 

    // Déclaration de l'accesseur (la fonction) getEffet qui renvoie un entier qui représente la valeur de l'effet de l'équipement
    int getEffet() const;   

    // Déclaration de la méthode virtuelle afficherCaracteristiques qui affiche les caractéristiques d'un équipement, la mettre en virtuel permet aux classes filles de la redéfinir
    virtual void afficherCaracteristiques() const;

// Déclaration des attributs protégé afin qu'ils puissent être utilisés par les classes filles
protected:
    std::string nom;  // Déclaration de l'attribut nom qui sera une chaîne de caractère qui représente le nom de l'équipement
    int effet;        // Déclaration de l'attribut effet qui sera un entier qui représente l'effet de l'équipement
    Type type;        // Déclaration de l'attribut type qui sera un type qui représente le type de l'équipement
};

#endif  
