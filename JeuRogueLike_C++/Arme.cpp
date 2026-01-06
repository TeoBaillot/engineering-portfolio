#include "Arme.hpp" 
#include <cstdlib>  


/*  Description : Définition du constructeur de la classe Arme qui appelle le constructeur de "Equipement" afin de définir ce qu'est une arme en passant trois arguments dans l'appel du constructeur de "Equipement"
                  Une arme aura donc un nom, un effet, et un type qui sera Arme
    Paramètres : nom est une référence constante vers une chaîne de caractères qui représente le nom de l'arme, effet est un entier qui représente l'effet de l'arme
*/
Arme::Arme(const std::string& nom, int effet) 
    : Equipement(nom, effet, Type::Arme) {}


/*  Description : Définition de la méthode afficherCaracteristiques qui permet d'afficher les caractéristiques d'une arme
*/
void Arme::afficherCaracteristiques() const {
    std::cout << "Arme - " << getNom() << ", Effet : " << getEffet() << "\n"; 
}

/*  Description : Définition de la fonction genererArmePourClasse qui renvoie une arme aléatoire en fonction de la classe du personnage
    Paramètres: classe est une référence constante vers une chaîne de caractère qui représente le nom de la classe
    Retour : Renvoie une arme
*/
Arme Arme::genererArmePourClasse(const std::string& classe) {
    std::string nom;  // Variable qui permet de stocker le nom de l'arme
    int categorie=0;  // Variable qui permet de définir la catégorie d'arme (1, 2 ou 3)
    int effet=0;      // Variable qui permet de définir l'effet de l'arme
    
    // Génèration d'un entier aléatoire entre 1 et 100 qui permet de déterminer la catégorie de l'arme
    int entier = rand() % 100 + 1;  
    
    // Détermination de la catégorie de l'arme gagnée
    if(entier >= 1 && entier <= 60) {
        categorie = 1;  // 60% de chance d'obtenir une arme de catégorie 1
    }
    else if(entier >= 60 && entier <= 90) {
        categorie = 2;  // 30% de chance d'obtenir une arme de catégorie 2
    }
    else {
        categorie = 3;  // 10% de chance d'obtenir une arme de catégorie 3
    }

    // Détermination de l'arme gagnée en fonction de la classe du personnage et de la catégorie

    // Détermination de l'arme gagnée si la classe du personnage est guerrier
    if (classe == "Guerrier") {
        // Détermination de l'arme en fonction de la catégorie tirée au sort
        switch(categorie) {
            case 1: nom = "Epee en bois"; effet = 3; break;
            case 2: nom = "Epee en fer"; effet = 6; break;
            case 3: nom = "Epee en diamant"; effet = 9; break;
        }
    } 
    //Détermination de l'arme gagnée si la classe du personnage est archer
    else if (classe == "Archer") {
        // Détermination de l'arme en fonction de la catégorie tirée au sort
        switch(categorie) {
            case 1: nom = "Arc en bois"; effet = 4; break;
            case 2: nom = "Arc en fer"; effet = 8; break;
            case 3: nom = "Arc en diamant"; effet = 12; break;
        }
    } 
    // Détermination de l'arme gagnée si la classe du personnage est magicien
    else if (classe == "Magicien") {
        // Détermination de l'arme en fonction de la catégorie tirée au sort
        switch(categorie) {
            case 1: nom = "Baguette en bois"; effet = 5; break;
            case 2: nom = "Baguette en fer"; effet = 10; break;
            case 3: nom = "Baguette en diamant"; effet = 15; break;
        }
    } 
    // Sécurité au cas où la classe renseignée n'existe pas
    else {
        // Si la classe ne correspond à aucun cas prévu, attribuer une arme par défaut
        nom = "Arme Inconnue"; effet = 0;
    }

    // Renvoie l'arme
    return Arme(nom, effet); 
}
