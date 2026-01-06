#ifndef CASQUE_HPP
#define CASQUE_HPP

#include "Equipement.hpp"

// Déclaration de la classe Casque qui hérite de la classe "Equipement"
class Casque : public Equipement {
public:
    // Déclaration du constructeur de la classe
    Casque(const std::string& nom, int effet);

    // Déclaration de la méthode afficherCaracteristiques qui affiche les caractéristiques d'un casque en redéfinissant la méthode de la classe mère
    void afficherCaracteristiques() const override;

    // Déclaration de la fonction statique genererCasquePourClasse qui renvoie un Casque, statique pour pouvoir l'appeler sans créer d'instance de l'objet
    static Casque genererCasquePourClasse(const std::string& classe);
};

#endif
