#include "Ennemi.hpp"
#include "Personnage.hpp"

/*  Description : Définition du constructeur de la classe Ennemi afin de définir ce qu'est un casque en passant trois arguments dans l'appel du constructeur de "Equipement"
                  Un ennemi aura donc un nom, un effet, et un type qui sera Casque
*/
Ennemi::Ennemi(const std::string& nom, int pdv, int atk)
    : nom(nom), pointsDeVie(pdv), attaque(atk) {}

/*  Description : Définition de l'accesseur (la fonction) getNom qui permet de renvoyer le nom de l'ennemi
    Retour : Renvoie une chaîne de caractère nom qui représente le nom de l'ennemi
*/
std::string Ennemi::getNom() const {
    return nom;
}

/*  Description : Définition de l'accesseur (la fonction) getPointsDeVie qui permet de renvoyer la valeur des points de vie de l'ennemi
    Retour : Renvoie un entier pointsDeVie qui représente la valeur des points de vie du personnage
*/
int Ennemi::getPointsDeVie(){
    if(pointsDeVie<0){
        pointsDeVie=0;
    }
    return pointsDeVie; // Retourne les points de vie de l'ennemi
}

/*  Description : Définition de l'accesseur (la fonction) getAttaque qui permet de renvoyer la valeur de l'attaque de l'ennemi
    Retour : Renvoie un entier attaque qui représente la valeur de l'attaque de l'ennemi'
*/
int Ennemi::getAttaque() const{
    return attaque;
}

/*  Description : Définition de la fonction est vaincu qui permet de savoir si un ennemi est vaincu
    Retour : Renvoie un booléen, true si l'ennemi est vaincu, false si l'ennemi n'est pas vaincu
*/
bool Ennemi::estVaincu() const {
    return pointsDeVie <= 0; 
}

/*  Description : Définition de la méthode recevoirDegats qui permet à l'ennemi de recevoir des dégats
    Paramètre : degat est un entier qui représente les dégats que l'ennemi subit
*/
void Ennemi::recevoirDegats(int degats) {
    pointsDeVie -= degats; 
}

/*  Description : Définition de la méthode attaquer qui permet à l'ennemi d'attaquer le personnage
    Paramètre : personnage est une référence vers Personnage
*/
int Ennemi::attaquer(Personnage& personnage) {
    // Génèration d'un entier aléatoire entre 1 et 10 qui permet de déterminer si l'attaque est esquivée ou non
    int entier = rand() % 10 + 1;

    // On vérifie si l'entier vaut 1, si c'est le cas le personnage esquive l'attaque
    if(entier==1){
        // entier vaut 1 donc le personnage esquive l'attaque
        std::cout << "Vous avez esquive l attaque de l'ennemi\n";
        return 0;
    }
    else{
        // Le personnage n'esquive pas l'attaque
        personnage.recevoirDegats(attaque);
        return 1;
    }
}
