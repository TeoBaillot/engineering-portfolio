#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <string>
#include "ClassePersonnage.hpp"  
#include "Inventaire.hpp"       
#include "Ennemi.hpp"            

// Déclaration de la classe Personnage
class Personnage {
private:
    std::string nom; // Déclaration de l'attribut nom qui sera une chaîne de caractères qui représente le nom du personnage
    int pointsDeVie; // Déclaration de l'attribut pointsDeVie qui sera un entier qui représente les points de vie courant du personnage
    int pointsDeVieMax; // Déclaration de l'attribut pointsDeVieMax qui sera un entier qui représente les points de vie maximum du personnage
    int attaque; // Déclaration de l'attribut attaque qui sera un entier qui représente l'attaque du personnage
    int attaqueClasse; // Déclaration de l'attribut attaqueClasse qui représente l'attaque de la classe du personnage
    Inventaire inventaire; // Déclaration de l'attribut inventaire qui sera un Inventaire qui représente l'inventaire du personnage

public:
    // Déclaration du constructeur de la classe
    Personnage(const std::string& nom, const ClassePersonnage& classe);

    // Déclaration de la fonction estVivant qui permet de savoir si le personnage est vivant ou non
    bool estVivant() const;

    // Déclaration de la fonction getEffetArmure qui permet de renvoyer l'effet de l'armure du personnage
    int getEffetArmure() const;

    // Déclaration de la fonction getEffetCasque qui permet de renvoyer l'effet du casque du personnage
    int getEffetCasque() const;

    // Déclaration de la fonction getEffetArme qui permet de renvoyer l'effet de l'arme du personnage
    int getEffetArme() const;

    // Déclaration de la méthode attaquer qui permet au personnage d'attaquer un ennemi
    int attaquer(Ennemi& ennemi);
        
    // Déclaration de la méthode recevoirDégats qui permet au personnage de subir des dégats provenant de l'ennemi
    void recevoirDegats(int degats);

    // Déclaration de la méthode equiperCasque qui permet d'équiper un casque au personnage
    void equiperCasque(const Casque& nouvelEquipement);

    // Déclaration de la méthode equiperArmure qui permet d'équiper une armure au personnage
    void equiperArmure(const Armure& nouvelEquipement);

    // Déclaration de la méthode equiperArme qui permet d'équiper une arme au personnage
    void equiperArme(const Arme& nouvelEquipement);
    
    // Déclaration de la méthode afficherStatistiques qui permet d'afficher les statistiques du personnage
    void afficherStatistiques() const;

    // Déclaration de l'accesseur (la fonction) getPointsDeVie qui permet de renvoyer les points de vie courant du personnage
    int getPointsDeVie() const; 
    
    // Déclaration de l'accesseur (la fonction) getAttaque qui permet de renvoyer l'attaque du personnage
    int getAttaque() const;

    // Déclaration de la méthode ajouterPotion qui permet d'ajouter une potion à l'inventaire du personnage
    void ajouterPotion(Potion* potion);

    // Déclaration de la méthode affichePotions qui affiche les potions présentes dans l'inventaire du personnage
    void afficherPotions() const;

    // Déclaration de la fonction aDesPotions qui permet de savoir si le personnage a des potions dans son inventaire
    bool aDesPotions() const;

    // Déclaration de la fonction utiliserPotion qui permet à l'utilisateur d'utiliser une potion de son inventaire
    void utiliserPotion(const std::string& nomPotion);
};

#endif 
