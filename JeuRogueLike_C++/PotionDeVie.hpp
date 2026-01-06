#ifndef POTIONDEVIE_HPP
#define POTIONDEVIE_HPP

#include "Potion.hpp" 

// Déclaration de la classe PotionDeVie qui hérite de la classe Potion
class PotionDeVie : public Potion {
public:
    // Déclaration du constructeur de la classe
    PotionDeVie(int effet = 50); // Par défaut l'effet de la potion de vie sera 50
    
    // Déclaration de la fonction statique genererPotion qui permet de generer une potion de vie, static pour pouvoir l'appeler sans créer d'instance de l'objet
    static PotionDeVie genererPotion(); 
};

#endif
