#include "Inventaire.hpp"
#include <iostream>
#include <string>
#include <limits>

/*  Description : Définition du constructeur de la classe
*/
Inventaire::Inventaire() 
    : casque("Casque de base", 0), // Initialisation du casque de base
      armure("Armure de base", 0), // Initialisation de l'armure de base
      arme("Arme de base", 0) // Initialisation de l'arme de base
      {}

// Destructeur : nettoie la mémoire allouée pour chaque potion dans l'inventaire.
Inventaire::~Inventaire() {
    // Parcourt de toutes les potions dans la map.
    for (auto& paire : potions) {
        //Parcourt du vecteur associé à chaque clé qui correspond au nom de la potion
        for (Potion* potion : paire.second) {
            // Supression de la potion de l'inventaire donc libération de la mémoire
            delete potion; 
        }
    }
}


/*  Description : Définition de la méthode ajouterPotion qui permet d'ajouter une potion à l'inventaire
    Paramètre: potion est un pointeur vers un objet Potion
*/
void Inventaire::ajouterPotion(Potion* potion) {
    // Vérification que le pointeur potion pointe bien vers un objet de type Potion
    if (potion) { 
        // Récupèration du nom de la potion pointée
        std::string nom = potion->getNom();

        // Ajoute la potion au vecteur correspondant au nom de la potion dans la map
        potions[nom].push_back(potion);
    }
}

/*  Description : Définition de la fonction utiliserPotion qui permet d'utiliser une potion de l'inventaire
    Paramètre: nomPotion est une référence constante vers une chaîne de caractères qui représente le nom de la potion, pointsDeVie est une référence vers un entier qui représente les points de vie du personnage,
               attaque est une référence vers un entier qui représente l'attaque du personnage
    Retour : renvoit un booléen, true si la potion a été utilisée, false si la potion n'est pas dans l'inventaire
*/
bool Inventaire::utiliserPotion(const std::string& nomPotion, int& pointsDeVie, int& attaque) {
    // Création d'un pointeur sur la paire qui correspond à la clé et l'objet potion correspondant à nomPotion
    auto pointeur = potions.find(nomPotion);

    // Vérification que le nom de la potion qu'on cherche correspond bien au nom d'une potion existante et que le vecteur correspondant au nom contient au moins une potion
    if (pointeur != potions.end() && !pointeur->second.empty()) {
        // Il y a au moins une potion du type qu'on veut utiliser dans l'inventaire
        
        // Récupèration du premier élément du vecteur correspondant au nom de la potion qu'on veut utiliser
        Potion* potion = pointeur->second.front(); 

        // On vérifie si le nom de la potion est "Potion de Vie"
        if (nomPotion == "Potion de Vie") {
            // Le nom de la potion est "Potion de Vie"

            // On applique les effets de la potion
            pointsDeVie += potion->getEffet();
        } 
        // On vérifie si le nom de la potion est "Potion d'Attaque"
        else if (nomPotion == "Potion d'Attaque") {
            // Le nom de la potion est "Potion d'Attaque"

            // On applique les effets de la potion
            attaque += potion->getEffet();
        }

        // On libère la mémoire allouée à la potion qu'on vient d'utiliser
        delete potion; 

        // On enlève la potion du vecteur de potion
        pointeur->second.erase(pointeur->second.begin()); 

        // La potion a été utilisée
        return true; 
    }
    // La potion n'est pas dans l'inventaire
    return false; 
}

/*  Description : Définition de la méthode afficherPotions qui affiche les potions de l'inventaire
*/
void Inventaire::afficherPotions() const {
    // On vérifie si l'inventaire contient des potions
    if (potions.empty()) {
        // L'inventaire ne contient aucune potion
        return; 
    } else {
        // L'inventaire contient au moins une potion
        std::cout << "Potions disponibles :\n";
    }

    // Parcourt des potions de la map
    for (const auto& pair : potions) {
        // Récupèration du vecteur de potions
        const std::vector<Potion*>& potionsVector = pair.second;

        // Affichage de chaque potion
        for (const Potion* potion : potionsVector) {
            std::cout << "- " << potion->getNom() 
                      << " (Effet : " << potion->getEffet() << ")\n";
        }
    }
}

/*  Description : Définition de la fonction aDesPotions qui permet de savoir si l'inventaire contient des potions
    Retour : renvoit un booléen, true si l'inventaire contient au moins une potion, false sinon
*/
bool Inventaire::aDesPotions() const {
    // Parcourir tous les vecteurs dans la map "potions"
    for (const auto& pair : potions) {
        // Vérifier si le vecteur associé n'est pas vide
        if (!pair.second.empty()) {
            return true;
        }
    }
    // Si tous les vecteurs sont vides, retourner false
    return false;
}


/*  Description : Définition de la méthode afficherEquipement qui affiche les équipements présents dans l'inventaire
*/
void Inventaire::afficherEquipements() const {
    std::cout << "Equipements :\n";
    std::cout << "- Casque : " << casque.getNom() << " (+Defense : " << casque.getEffet() << ")\n";
    std::cout << "- Armure : " << armure.getNom() << " (+Defense : " << armure.getEffet() << ")\n";
    std::cout << "- Arme : " << arme.getNom() << " (+Attaque : " << arme.getEffet() << ")\n";
}

/*  Description : Définition de la méthode afficherInventaire qui affiche les équipements et les potions présents dans l'inventaire
*/
void Inventaire::afficherInventaire() const {
    std::cout << "Inventaire Complet :\n";
    afficherEquipements(); // Appelle l'affichage des équipements.
    afficherPotions();     // Appelle l'affichage des potions.
}

/*  Description : Définition de l'accesseur (la fonction) getArme qui permet de récupérer l'arme de l'inventaire
    Retour : renvoit une référence constante vers une arme 
*/
const Arme& Inventaire::getArme() const { 
    return arme; 
}   

/*  Description : Définition de l'accesseur (la fonction) getArmure qui permet de récupérer l'armure de l'inventaire
    Retour : renvoit une référence constante vers une armure 
*/
const Armure& Inventaire::getArmure() const { 
    return armure; 
} 

/*  Description : Définition de l'accesseur (la fonction) qui permet de récupérer le casque de l'inventaire
    Retour : renvoit une référence constante vers un casque 
*/
const Casque& Inventaire::getCasque() const { 
    return casque; 
}

/*  Description : Définition de la fonction equiperCasque qui permet d'équiper un casque
    Paramètre : nouveauCasque est une référence constante a un casque
*/
void Inventaire::equiperCasque(const Casque& nouveauCasque) {
    // Chaîne de caractères pour stocker la réponse de l'utilisateur
    std::string reponse;

    // Boucle pour vérifier si la réponse de l'utilisateur est valide
    while (true) {
        // On affiche le message pour demander à l'utilisateur s'il souhaite équiper le casque
        std::cout << "Voulez-vous equiper " << nouveauCasque.getNom()
                  << " (+Defense : " << nouveauCasque.getEffet() << ") ? (oui/non) : ";

        // On récupère la réponse de l'utilisateur
        std::cin >> reponse;

        // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // On converti la réponse de l'utilisateur en minuscules
        for (auto & c : reponse) c = tolower(c);

        // On vérifie si la réponse est valide
        if (reponse == "oui" || reponse == "non") {
            // La réponse est valide donc on sort de la boucle
            break;
        } 
        // L'utilisateur a entré une réponse invalide donc on reboucle
        else {
            std::cout << "\nReponse invalide. Veuillez repondre par 'oui' ou 'non'.\n";
        }
    }
    // La réponse de l'utilisateur est valide

    // On vérifie si la réponse est "oui"
    if (reponse == "oui") {
        // La réponse est "oui"

        // On équipe le nouveau casque
        casque = nouveauCasque;
        std::cout << "Casque equipe : " << casque.getNom() << " (+Defense : " << casque.getEffet() << ")\n";
    } 
    // On vérifie si la réponse est "non"
    else if (reponse == "non") {
        // La réponse est "non"

        // L'utilisateur choisit de ne pas équiper le casque
        std::cout << "Vous abandonnez le casque dans la foret.\n";
    }
}

/*  Description : Définition de la fonction equiperArmure qui permet d'équiper une armure
    Paramètre : nouvelleArmure est une référence constante a une armure
*/
void Inventaire::equiperArmure(const Armure& nouvelleArmure) {
    // Chaîne de caractères pour stocker la réponse de l'utilisateur
    std::string reponse;

    // Boucle pour vérifier si la réponse de l'utilisateur est valide
    while (true) {
        // On affiche le message pour demander à l'utilisateur s'il souhaite équiper l'armuree
        std::cout << "Voulez-vous equiper " << nouvelleArmure.getNom()
                  << " (+Defense : " << nouvelleArmure.getEffet() << ") ? (oui/non) : ";

        // On récupère la réponse de l'utilisateur
        std::cin >> reponse;

        // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // On converti la réponse de l'utilisateur en minuscules
        for (auto & c : reponse) c = tolower(c);

        // On vérifie si la réponse est valide
        if (reponse == "oui" || reponse == "non") {
            // La réponse est valide donc on sort de la boucle
            break;
        } 
        // L'utilisateur a entré une réponse invalide donc on reboucle
        else {
            std::cout << "\nReponse invalide. Veuillez repondre par 'oui' ou 'non'.\n";
        }
    }
    // La réponse de l'utilisateur est valide

    // On vérifie si la réponse est "oui"
    if (reponse == "oui") {
        // La réponse est "oui"

        // On équipe la nouvelle armure
        armure = nouvelleArmure;
        std::cout << "Armure equipee : " << armure.getNom() << " (+Defense : " << armure.getEffet() << ")\n";
    } 
    // On vérifie si la réponse est "non"
    else if (reponse == "non") {
        // La réponse est "non"

        // L'utilisateur choisit de ne pas équiper l'armure
        std::cout << "Vous abandonnez l'armure dans la foret.\n";
    }
}

/*  Description : Définition de la fonction equiperArme qui permet d'équiper une arme
    Paramètre : nouvelleArme est une référence constante a une arme
*/
void Inventaire::equiperArme(const Arme& nouvelleArme) {
    // Chaîne de caractères pour stocker la réponse de l'utilisateur
    std::string reponse;

    // Boucle pour vérifier si la réponse de l'utilisateur est valide
    while (true) {
        // On affiche le message pour demander à l'utilisateur s'il souhaite équiper l'arme
        std::cout << "Voulez-vous equiper " << nouvelleArme.getNom()
                  << " (+Attaque : " << nouvelleArme.getEffet() << ") ? (oui/non) : ";

        // On récupère la réponse de l'utilisateur
        std::cin >> reponse;

        // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // On converti la réponse de l'utilisateur en minuscules
        for (auto & c : reponse) c = tolower(c);

        // On vérifie si la réponse est valide
        if (reponse == "oui" || reponse == "non") {
            // La réponse est valide donc on sort de la boucle
            break;
        } 
        // L'utilisateur a entré une réponse invalide donc on reboucle
        else {
            std::cout << "\nReponse invalide. Veuillez repondre par 'oui' ou 'non'.\n";
        }
    }
    // La réponse de l'utilisateur est valide

    // On vérifie si la réponse est "oui"
    if (reponse == "oui") {
        // La réponse est "oui"

        // On équipe la nouvelle arme
        arme = nouvelleArme;
        std::cout << "Arme equipee : " << arme.getNom() << " (+Attaque : " << arme.getEffet() << ")\n";
    } 
    // On vérifie si la réponse est "non"
    else if (reponse == "non") {
        // La réponse est "non"

        // L'utilisateur choisit de ne pas équiper l'arme
        std::cout << "Vous abandonnez l'arme dans la foret.\n";
    }
}
