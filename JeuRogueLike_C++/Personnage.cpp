#include "Personnage.hpp"
#include <iostream>

/*  Description : Définition du constructeur de la classe
    Paramètre: nom est une référence constante vers le nom du personnage, classe est une référence constante vers la classe du personnage
*/
Personnage::Personnage(const std::string& nom, const ClassePersonnage& classe)
    : nom(nom), 
      pointsDeVieMax(classe.getPointsDeVieMax()), 
      pointsDeVie(classe.getPointsDeVieMax()),    
      attaque(classe.getAttaque()),                
      attaqueClasse(classe.getAttaque()) {      
}

/*  Description : Définition de l'accesseur (la fonction) estVivant qui permet de savoir si le personnage est vivant ou non
    Retour : Renvoie un booléen, true si le personnage est vivant, false sinon
*/
bool Personnage::estVivant() const {
    return pointsDeVie > 0;
}

/*  Description : Définition de la fonction getEffetArmure qui permet de renvoyer l'effet de l'armure du personnage
    Retour : Renvoie un entier qui représente la valeur dans l'effet de l'armure du personnage
*/
int Personnage::getEffetArmure() const {
    return inventaire.getArmure().getEffet(); 
}

/*  Description : Définition de la fonction getEffetCasque qui permet de renvoyer l'effet du casque du personnage
    Retour : Renvoie un entier qui représente la valeur dans l'effet du casque du personnage
*/
int Personnage::getEffetCasque() const {
    return inventaire.getCasque().getEffet(); 
}

/*  Description : Définition de la fonction getEffetArmure qui permet de renvoyer l'effet de l'arme du personnage
    Retour : Renvoie un entier qui représente la valeur dans l'effet de l'arme du personnage
*/
int Personnage::getEffetArme() const {
    return inventaire.getArme().getEffet(); 
}

/*  Description : Définition de la méthode attaquer qui permet au personnage d'attaquer un ennemi
    Paramètre: ennemi est une référence vers un ennemi
*/
int Personnage::attaquer(Ennemi& ennemi) {
    // Génèration d'un entier aléatoire entre 1 et 10 qui permet de déterminer si l'attaque est esquivée ou non
    int entier = rand() % 10 + 1;  

    // On vérifie si l'entier vaut 1, si c'est le cas l'ennemi esquive l'attaque
    if(entier==1){
        // L'entier vaut 1 donc l'ennemi esquive l'attaque
        std::cout << "L ennemi a esquive votre attaque\n";  
        return 0;
    }
    else{
        // L'entier est différente de 1 donc l'ennemi n'esquive pas l'attaque
        int degats = attaque + getEffetArme(); 
        ennemi.recevoirDegats(degats);
        return 1;
    }
}

/*  Description : Définition de la méthode recevoirDegats qui permet au personnage de subir des dégats provenant de l'ennemi
    Paramètre : degat est un entier qui représente l'attaque de l'ennemi
*/
void Personnage::recevoirDegats(int degats) {
    // Récupèration de la valeur de la réduction des dégats suite aux effets de l'armure et du casque du personnage
    int reductionDegats = getEffetArmure() + getEffetCasque(); 

    // Calcul des dégats que le personnage va subir
    int degatsReel = degats - reductionDegats;                 
    if (degatsReel < 0) {
        degatsReel = 0;  
    }

    // On retire les points de vie correspondants
    pointsDeVie -= degatsReel;                   
        if (pointsDeVie < 0) {
        pointsDeVie = 0;  
    }       
}

/*  Description : Définition de la méthode afficherStatistiques qui permet d'afficher les statistiques du personnage
*/
void Personnage::afficherStatistiques() const {
    std::cout << "Nom : " << nom << "\n";
    std::cout << "Points de vie : " << pointsDeVie << "/" << pointsDeVieMax << "\n";
    std::cout << "Attaque : " << attaque << "\n";
    inventaire.afficherEquipements(); 
}

/*  Description : Définition de la méthode equiperCasque qui permet au personnage d'équiper un casque
    Paramètre : nouveauCasque est une référence constante vers un Casque
*/
void Personnage::equiperCasque(const Casque& nouveauCasque) {
    inventaire.equiperCasque(nouveauCasque); // Équipe le casque via l'inventaire
}

/*  Description : Définition de la méthode equiperArmure qui permet au personnage d'équiper une armure
    Paramètre : nouvelleArmure est une référence constante vers une Armure
*/
void Personnage::equiperArmure(const Armure& nouvelleArmure) {
    inventaire.equiperArmure(nouvelleArmure); // Équipe l'armure via l'inventaire
}

/*  Description : Définition de la méthode equiperArme qui permet au personnage d'équiper une arme
    Paramètre : nouvelleArme est une référence constante vers une Arme
*/
void Personnage::equiperArme(const Arme& nouvelleArme) {
    inventaire.equiperArme(nouvelleArme); // Équipe l'arme via l'inventaire
}

/*  Description : Définition de l'accesseur (la fonction) getPointsDeVie qui permet de récupérer la valeur des points de vie courant du personnage
    Retour : Renvoie un entier pointsDeVie qui représente la valeur des points de vie du personnage
*/
int Personnage::getPointsDeVie() const {
    return pointsDeVie;
}

/*  Description : Définition de l'accesseur (la fonction) getAttaque qui permet de renvoyer la valeur de l'attaque du personnage
    Retour : Renvoie un entier attaque qui représente la valeur de l'attaque du personnage
*/
int Personnage::getAttaque() const {
    return attaque;
}

/*  Description : Définition de la méthode ajouterPotion qui permet d'ajouter une potion à l'inventaire du personnage
    Paramètre : potion est une référence vers une Potion
*/
void Personnage::ajouterPotion(Potion* potion) {
    inventaire.ajouterPotion(potion);
}

/*  Description : Définition de la méthode afficherPotion qui permet d'afficher les potions de l'inventaire du personnage
*/
void Personnage::afficherPotions() const {
    inventaire.afficherPotions(); 
}

/*  Description : Définition de la méthode aDesPotions qui permet de savoir si l'inventaire du personnage contient au moins une potion
    Retour : Renvoie un booléen, true si l'inventaire du personnage contient au moins une potion, false sinon
*/
bool Personnage::aDesPotions() const {
    return inventaire.aDesPotions(); 
}

/*  Description : Définition de la méthode utiliserPotion qui permet d'utiliser une potion de l'inventaire du personnage
    Paramètre : nomPotion est une référence constante vers une chaîne de caractère qui représente le nom de la potion
*/
void Personnage::utiliserPotion(const std::string& nomPotion) {
    // Vérifie si la potion est dans l'inventaire et utilise la potion de l'inventaire et passe les effets sur les points de vie et d'attaque du personnage
    if (inventaire.utiliserPotion(nomPotion, pointsDeVie, attaque)) {
        std::cout << "Vous avez utilise " << nomPotion << " !\n" << std::endl;

        // On vérifie si les points de vie dépassent le maximum de point de vie autorisé par la classe du personnage
        if (pointsDeVie > pointsDeVieMax) {
            // Si les points de vie du personnage sont supérieur au point de vie maximum de sa classe on ajuste les points de vie du personnage pour qu'ils soient égaux aux points de vie maximal de la classe du personnage
            pointsDeVie = pointsDeVieMax;
        }
        std::cout << "Points de vie actuels : " << pointsDeVie << "/" << pointsDeVieMax << std::endl;
        std::cout << "Points d'attaque actuels : " << attaque+getEffetArme() << "\n" << std::endl;
    } 
    // La potion n'est pas dans l'inventaire
    else {
        std::cout << "Potion non trouvee !\n" << std::endl; 
    }
}
