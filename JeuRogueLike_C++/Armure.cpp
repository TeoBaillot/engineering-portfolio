#include "Armure.hpp"
#include <cstdlib>

/*  Description : Définition du constructeur de la classe Armure qui appelle le constructeur de "Equipement" afin de définir ce qu'est une armure en passant trois arguments dans l'appel du constructeur de "Equipement"
                  Une armure aura donc un nom, un effet, et un type qui sera Armure
*/
Armure::Armure(const std::string& nom, int effet) 
    : Equipement(nom, effet, Type::Armure) {}

/*  Description : Définition de la méthode afficherCaracteristiques qui permet d'afficher les caractéristiques d'une arme
*/
void Armure::afficherCaracteristiques() const {
    std::cout << "Armure - " << getNom() << ", Effet : " << getEffet() << "\n";
}

/*  Description : Définition de la fonction genererArmurePourClasse qui renvoie une armure aléatoire en fonction de la classe du personnage
    Paramètres: classe est une référence vers une chaîne de caractère constante qui représente le nom de la classe
    Retour : Renvoie une armure
*/
Armure Armure::genererArmurePourClasse(const std::string& classe) {
    std::string nom; // Variable qui permet de stocker le nom de l'armure
    int categorie=0; // Variable qui permet de définir la catégorie d'armure (1, 2 ou 3)
    int effet=0; // Variable qui permet de définir l'effet de l'armure

    // Génèration d'un entier aléatoire entre 1 et 100 qui permet de déterminer la catégorie de l'armure
    int entier = rand() % 100 + 1; 

    // Détermination de la catégorie de l'armure gagnée
    if(entier>=1 && entier<=60){
        categorie=1; //60% de chance d'avoir une armure de catégorie 1
    }
    else if(entier>=60 && entier<=90){
        categorie=2; //30% de chance d'avoir une armure de catégorie 2
    }
    else{
        categorie=3; //10% de chance d'avoir une armure de catégorie 3
    }

    // Détermination de l'armure gagnée en fonction de la classe du personnage et de la catégorie

    // Détermination de l'armure gagnée si la classe du personnage est guerrier
    if (classe == "Guerrier") {
        switch(categorie){
            // Si la classe est "Guerrier", choisir une armure en fonction de la catégorie
            case 1: nom="Armure en bois";
                    effet=3;
                    break;
            case 2: nom="Armure en fer";
                    effet=5;
                    break;
            case 3: nom="Armure en diamant";
                    effet=7;
                    break;
        }
    } 
    // Détermination de l'armure gagnée si la classe du personnage est archer
    else if (classe == "Archer") {
        switch(categorie){
            // Si la classe est "Archer", choisir une armure en fonction de la catégorie
            case 1: nom="Plastron en bois";
                    effet=2;
                    break;
            case 2: nom="Plastron en fer";
                    effet=4;
                    break;
            case 3: nom="Plastron en diamant";
                    effet=6;
                    break;
        }
    } 
    // Détermination de l'armure gagnée si la classe du personnage est magicien
    else if (classe == "Magicien") {
        switch(categorie){
            // Si la classe est "Magicien", choisir une armure en fonction de la catégorie
            case 1: nom="Cape en tissu";
                    effet=1;
                    break;
            case 2: nom="Cape en soie";
                    effet=3;
                    break;
            case 3: nom="Cape en peau de dragon";
                    effet=5;
                    break;
        }
    } 
    // Sécurité au cas où la classe renseignée n'existe pas
    else {
        // Si la classe ne correspond à aucun cas prévu, attribuer une arme par défaut
        nom = "Armure Inconnue";
        effet=0;
    }
    // Renvoie une nouvelle instance d'armure avec le nom et l'effet généré
    return Armure(nom, effet); 
}
