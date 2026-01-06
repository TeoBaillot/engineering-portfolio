#ifndef ARME_HPP
#define ARME_HPP

#include "Equipement.hpp"

// Déclaration de la classe Arme qui hérite de la classe "Equipement"
class Arme : public Equipement {
public:
    // Déclaration du constructeur de la classe
    Arme(const std::string& nom, int effet);
    
    // Déclaration de la méthode afficherCaracteristiques qui affiche les caractéristiques d'une arme en redéfinissant la méthode de la classe mère
    void afficherCaracteristiques() const override;

    // Déclaration de la fonction statique genererArmePourClasse qui renvoie une Arme, statique pour pouvoir l'appeler sans créer d'instance de l'objet
    static Arme genererArmePourClasse(const std::string& classe);
};

#endif
