#include "Potion.hpp"
#include "PotionDAttaque.hpp"
#include "PotionDeVie.hpp"
#include <cstdlib> 
#include <ctime>   

/*  Description : Définition du constructeur de la classe
    Paramètre: nom est une référence constante vers une chaîne de caractère qui représente le nom de la potion, effet est un entier qui représente la valeur de l'effet de la potion
*/
Potion::Potion(const std::string& nom, int effet) : nom(nom), effet(effet) {}

/*  Description : Définition de l'accesseur (la fonction) getNom qui permet de renvoyer le nom de la potion
    Retour : Renvoie une chaîne de caractère constante nom que représente le nom de la potion
*/
std::string Potion::getNom() const {
    return nom; 
}

/*  Description : Définition de l'accesseur (la fonction) getEffet qui permet de récupérer la valeur de l'effet de la potion
    Retour : Renvoie un entier effet qui représente la valeur de l'effet de la potion
*/
int Potion::getEffet() const {
    return effet; 
}

/*  Description : Définition de la fonction genererPotionAleatoire qui permet de générer une potion de façon aléatoire
    Retour : Renvoie un pointeur sur une potion
*/
Potion* Potion::genererPotionAleatoire() {
    // Génération d'un nombre aléatoire entre 0 et 1
    srand(time(0));
    int randomType = rand() % 2; 

    //Vérification du type de potion à générer
    if (randomType == 0) {
        // Si le nombre aléatoire est 0 donc on génère une potion de vie
        return new PotionDeVie(); 
    } else {
        // Si le nombre aléatoire est 1 donc on génère une potion d'attaque
        return new PotionDAttaque(); 
    }
}
