#ifndef INVENTAIRE_HPP
#define INVENTAIRE_HPP

#include <string>
#include <map>
#include <vector>
#include "Potion.hpp"
#include "Casque.hpp" 
#include "Armure.hpp" 
#include "Arme.hpp"   

// Déclaration de la classe Inventaire
class Inventaire {
private:
    // Déclaration d'un map pour pouvoir stocker les potions, chaque clé sera associée à un vecteur de potions, vecteur car on a besoin que le conteneur soit dynamique
    std::map<std::string, std::vector<Potion*>> potions; 

    Casque casque;  // Déclaration de l'attribut casque qui représente l'objet casque actuellement équipé 
    Armure armure;  // Déclaration de l'attribut casque qui représente l'objet armure actuellement équipé 
    Arme arme;      // Déclaration de l'attribut casque qui représente l'objet arme actuellement équipé 

public:
    // Déclaration du constructeur par défaut
    Inventaire();   
    // Déclaration du destructeur par défaut pour pouvoir libérer la mémoire prise par chaque potion de l'inventaire
    ~Inventaire();  

    // Déclaration de la méthode ajouterPotion qui permet d'ajouter une potion à l'inventaire
    void ajouterPotion(Potion* potion);

    // Déclaration de la fonction utiliserPotion qui permet d'utiliser une potion de l'inventaire et d'appliquer l'effet correspondant au personnage
    bool utiliserPotion(const std::string& nomPotion, int& pointsDeVie, int& attaque);

    // Déclaration de la méthode afficherPotion qui permet d'afficher les potions de l'inventaire
    void afficherPotions() const;

    // Déclaration de la fonction aDesPotions qui permet de savoir si le personnage possède des potions dans son inventaire
    bool aDesPotions() const;

    // Déclaration de la méthode afficherEquipements qui permet d'afficher les équipements présents dans l'inventaire
    void afficherEquipements() const;

    // Déclaration de la méthode afficherInventaire qui permet d'afficher l'inventaire complet: les potions et les équipements
    void afficherInventaire() const;

    // Déclaration de la fonction getArme qui permet de renvoyer l'arme de l'inventaire
    const Arme& getArme() const;    

    // Déclaration de la fonction qui permet de renvoyer l'armure de l'inventaire
    const Armure& getArmure() const;

    // Déclaration de la fonction qui permet de renvoyer le casque de l'inventaire
    const Casque& getCasque() const; 

    // Déclaration de la méthode qui permet d'équiper un casque et de l'ajouter à l'inventaire
    void equiperCasque(const Casque& nouveauCasque);     

    // Déclaration de la méthode qui permet d'équiper une armure et de l'ajouter à l'inventaire
    void equiperArmure(const Armure& nouvelleArmure);  

    // Déclaration de la méthode qui permet d'équiper une arme et de l'ajouter à l'inventaire
    void equiperArme(const Arme& nouvelleArme);        
};

#endif
