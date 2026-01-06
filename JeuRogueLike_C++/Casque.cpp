#include "Casque.hpp"
#include <cstdlib>

/*  Description : Définition du constructeur de la classe Casque qui appelle le constructeur de "Equipement" afin de définir ce qu'est un casque en passant trois arguments dans l'appel du constructeur de "Equipement"
                  Un casque aura donc un nom, un effet, et un type qui sera Casque
*/
Casque::Casque(const std::string& nom, int effet) 
    : Equipement(nom, effet, Type::Casque) {}

/*  Description : Définition de la méthode afficherCaracteristiques qui permet d'afficher les caractéristiques d'un casque
*/
void Casque::afficherCaracteristiques() const {
    std::cout << "Casque - " << getNom() << ", Effet : " << getEffet() << "\n";
}

/*  Description : Définition de la fonction genererCasquePourClasse qui renvoie un casque aléatoire en fonction de la classe du personnage
    Paramètres: classe est une référence vers une chaîne de caractère constante qui représente le nom de la classe
    Retour : Renvoie un casque
*/
Casque Casque::genererCasquePourClasse(const std::string& classe) {
    std::string nom; // Variable qui permet de stocker le nom du casque
    int categorie=0; // Variable qui permet de définir la catégorie du casque (1, 2 ou 3)
    int effet=0; // Variable qui permet de définir l'effet de l'armure

    // Génèration d'un entier aléatoire entre 1 et 100 qui permet de déterminer la catégorie du casque
    int entier = rand() % 100 + 1; 

    // Détermination de la catégorie du casque gagné
    if(entier>=1 && entier<=60){
        categorie=1; //60% de chance d'avoir un casque de catégorie 1
    }
    else if(entier>=60 && entier<=90){
        categorie=2; //30% de chance d'avoir un casque de catégorie 2
    }
    else{
        categorie=3; //10% de chance d'avoir un casque de catégorie 3
    }

    // Détermination du casque gagné en fonction de la classe du personnage et de la catégorie

    // Détermination du casque gagné si la classe du personnage est guerrier
    if (classe == "Guerrier") {
        switch(categorie){
            // Si la classe est "Guerrier", choisir un casque en fonction de la catégorie
            case 1: nom="Casque en bois";
                    effet=3;
                    break;
            case 2: nom="Casque en fer";
                    effet=4;
                    break;
            case 3: nom="Casque en diamant";
                    effet=5;
                    break;
        }
    } 
    // Détermination du casque gagné si la classe du personnage est Archer
    else if (classe == "Archer") {
        switch(categorie){
            // Si la classe est "Archer", choisir un casque en fonction de la catégorie
            case 1: nom="Capuche en bois";
                    effet=2;
                    break;
            case 2: nom="Capuche en fer";
                    effet=3;
                    break;
            case 3: nom="Capuche en diamant";
                    effet=4;
                    break;
        }
    } 
    // Détermination du casque gagné si la classe du personnage est Magicien
    else if (classe == "Magicien") {
        switch(categorie){
            // Si la classe est "Magicien", choisir un casque en fonction de la catégorie
            case 1: nom="Chapeau en tissu";
                    effet=1;
                    break;
            case 2: nom="Chapeau en soie";
                    effet=2;
                    break;
            case 3: nom="Chapeau en peau de dragon";
                    effet=3;
                    break;
        }
    } 
    // Sécurité au cas où la classe renseignée n'existe pas
    else {
        // Si la classe ne correspond à aucun cas prévu, attribuer une arme par défaut
        nom = "Arme Inconnue";
        effet=0;
    }
    // Renvoie une nouvelle instance d'Arme avec le nom et l'effet généré
    return Casque(nom, effet); 
}