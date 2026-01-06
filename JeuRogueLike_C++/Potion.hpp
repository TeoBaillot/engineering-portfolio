#ifndef POTION_HPP
#define POTION_HPP

#include <string> 
#include <cstdlib>

// Déclaration de la classe Potion
class Potion {
private:
    std::string nom; // Déclaration de l'attribut nom qui sera une chaîne de caractères qui représente le nom de la potion
    int effet; // Déclaration de l'attribut effet qui sera un entier qui représente l'effet de la potion

public:
    // Déclaration du constructeur de la classe
    Potion(const std::string& nom, int effet); 
    
    // Déclaration de l'accesseur getNom qui renvoie le nom de la potion
    std::string getNom() const; 
    
    // Déclaration de l'accesseur getEffet qui renvoie l'effet de la potion
    int getEffet() const; 

    // Déclaration d'une fonction statique pour generer une potion de façon aléatoire, statique pour pouvoir l'appeler sans créer d'instance de l'objet 
    static Potion* genererPotionAleatoire(); 
};

#endif 
