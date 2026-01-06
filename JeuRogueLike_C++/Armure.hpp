#ifndef ARMURE_HPP
#define ARMURE_HPP

#include "Equipement.hpp"

// Déclaration de la classe Armure qui hérite de la classe "Equipement"
class Armure : public Equipement {
public:
    // Déclaration du constructeur de la classe
    Armure(const std::string& nom, int effet);

    // Déclaration de la méthode afficherCaracteristiques qui affiche les caractéristiques d'une armure en redéfinissant la méthode de la classe mère
    void afficherCaracteristiques() const override;

    // Déclaration de la fonction statique genererArmurePourClasse qui renvoie une Armure, statique pour pouvoir l'appeler sans créer d'instance de l'objet
    static Armure genererArmurePourClasse(const std::string& classe);
};

#endif
