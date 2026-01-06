#ifndef POTIONDATTAQUE_HPP
#define POTIONDATTAQUE_HPP

#include "Potion.hpp"

// Déclaration de la classe PotionDAttaque qui hérite de la classe Potion
class PotionDAttaque : public Potion {
public:
    // Déclaration du constructeur de la classe
    PotionDAttaque(int effet = 10); // Par défaut l'effet de la potion d'attaque sera 10

    // Déclaration de la fonction statique genererPotion qui permet de generer une potion d'attaque, static pour pouvoir l'appeler sans créer d'instance de l'objet
    static PotionDAttaque genererPotion();
};

#endif 
