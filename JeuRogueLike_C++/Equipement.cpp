#include "Equipement.hpp"  // Inclusion du fichier d'en-tête "Equipement.hpp" pour utiliser la classe Equipement et ses méthodes.


/*  Description : Définition du constructeur de la classe
    Paramètre: nom est une référence constante sur une chaîne de caractère qui représente le nom de l'équipement, effet est un entier qui représente l'effet de l'équipement, type est un Type qui représente le type de l'équipement.
*/
Equipement::Equipement(const std::string& nom, int effet, Type type) 
    : nom(nom), effet(effet), type(type) {}  

/*  Description : Définition de l'accesseur (la fonction) getNom qui permet de récupérer le nom de l'équipement
    Retour : Renvoie une chaîne de caractères nom qui représente le nom de l'équipement
*/
std::string Equipement::getNom() const {
    return nom;  
}

/*  Description : Définition de l'accesseur (la fonction) getEffet() qui permet de récupérer la valeur de l'effet de l'équipement
    Retour : Renvoie un entier effet qui représente la valeur de l'effet de l'équipement
*/
int Equipement::getEffet() const {
    return effet; 
}

/*  Description : Définition de la méthode afficherCaractéristiques qui permet d'afficher les caractéristiques d'un équipement
*/
void Equipement::afficherCaracteristiques() const {
    std::cout << "Equipement - " << getNom()<< ", Effet : " << getEffet() <<"\n";  

}
