#include "Personnage.hpp"
#include "Ennemi.hpp"
#include "ClassePersonnage.hpp"
#include "Guerrier.hpp"
#include "Archer.hpp"
#include "Magicien.hpp"
#include "Potion.hpp"
#include "PotionDeVie.hpp"
#include "PotionDAttaque.hpp"
#include "Equipement.hpp"
#include "Casque.hpp"
#include "Armure.hpp"
#include "Arme.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>   
#include <string>
#include <limits>

int main() {
    // Boucle qui permettra de relancer une partie à la fin d'une partie
    while (true) { 
        std::cout << "------------------------------------------------------------------------------------\n\n"; 
        // Affichage du message d'entrée dans le jeu
        std::cout << "Bienvenue dans Hero Fight, dans ce jeu de role, chaque decision compte et vous permettra d'avancer dans l'aventure. Dans ce monde fantastique vous incarnerez un hero dont le courage sera mis a l'epreuve et a l'issue de chaque combat vous pourrez trouver des armes, des equipements, ou des potions qui vous permettront de devenir plus fort. \nCommencez par choisir la classe de votre hero: \n";

        // Déclaration des variables qui permettront de gérer la création du personnage
        std::string nom;
        ClassePersonnage* classe = nullptr; // Le pointeur ne pointe sur rien au départ
        bool pretPourAventure = false;

        // Boucle permettant au joueur de redéfinir son personnage s'il n'est pas prêt à commencer l'aventure
        while (!pretPourAventure) {
            // Créer des instances des classes pour accéder à leurs caractéristiques
            Guerrier guerrier;
            Archer archer;
            Magicien magicien;

            // Affichage des caractéristiques de chaque classe pour permettre au joueur de choisir sa classe
            std::cout << "Caracteristiques des classes :\n";
            std::cout << guerrier.getNomClasse() << " : Points de vie = " << guerrier.getPointsDeVieMax() << ", Attaque = " << guerrier.getAttaque() << "\n";
            std::cout << archer.getNomClasse() << " : Points de vie = " << archer.getPointsDeVieMax() << ", Attaque = " << archer.getAttaque() << "\n";
            std::cout << magicien.getNomClasse() << " : Points de vie = "<< magicien.getPointsDeVieMax() << ", Attaque = " << magicien.getAttaque() << "\n";

            // On demande à l'utilisateur de choisir sa classe
            std::cout << "\nChoisissez une classe (Guerrier, Archer, Magicien) : ";
            std::string choix;

            // Boucle permettant à l'utilisateur de resélectionner un nom de classe tant qu'il rentre un nom de classe invalide
            while (true) {
                std::cin >> choix;

                // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Convertion de la réponse du joueur en minuscules
                for (auto & c : choix) c = tolower(c);

                // Gestion de l'attribution de la classe du personnage en fonction du choix de l'utilisateur
                if (choix == "guerrier") {
                    classe = &guerrier;
                    break;
                } else if (choix == "archer") {
                    classe = &archer;
                    break;
                } else if (choix == "magicien") {
                    classe = &magicien;
                    break;
                } else {
                    std::cout << "Choix invalide. Veuillez choisir Guerrier, Archer, ou Magicien : ";
                }
            }

            // On demande à l'utilisateur d'entrer le nom de son personnage
            std::cout << "Entrez le nom de votre personnage : ";
            std::cin >> nom;
            
            // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Création du personnage du joueur
            Personnage joueur(nom, *classe);
            std::cout << "\nFelicitation, vous avez cree votre personnage, voici ses caracteristiques:\n";
            joueur.afficherStatistiques();

            // Chaîne de caractère pour stocker la réponse de l'utilisateur
            std::string reponse;

            // Boucle pour reposer la question tant que l'utilisateur entre une réponse invalide
            while(true){
                // On demande si le joueur est prêt pour l'aventure
                std::cout << "\nEtes-vous pret pour cette aventure ? (oui/non) : \n";

                // On récupère la réponse de l'utilisateur
                std::cin >> reponse;

                // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Convertion de la réponse du joueur en minuscules
                for (auto & c : reponse) c = tolower(c);

                // On vérifie si la réponse est "oui"
                if (reponse == "oui" || reponse=="non") {
                    std::cout << "\nParfait, partons A l'aventure !\n\n";
                    break; // Sortie de la boucle principale
                } 
                // L'utilisateur a répondu autre chose que "oui" ou "non"
                else {
                    // Message pour réponse invalide
                    std::cout << "\nChoix invalide. Veuillez repondre par 'oui' ou 'non'.\n";
                }
            }

            // On vérifie si la réponse est "non"
            if (reponse == "non") {
                // La réponse est "non"
                std::cout << "\nRecrEez votre personnage.\n\n";

                // On retourne au début de la boucle principale pour créer un nouveau personnage
                continue; 
            } 

            // Création du vecteur contenant les ennemis que va rencontrer le joueur
            std::vector<Ennemi> ennemis = {
                Ennemi("Gobelin", 50, 5),
                Ennemi("Orque", 75, 10),
                Ennemi("Sorcier", 100, 15),
                Ennemi("Dragon", 150, 20),
                Ennemi("Titan colossal", 200, 25)
            };

            // Boucle qui permet au personnage de rencontrer tous les ennemis
            for (Ennemi& ennemi : ennemis) {
                // Invariant: il reste encore au moins un ennemi à combattre

                std::cout << "------------------------------------------------------------------------------------\n\n"; 

                // Affichage du scénario
                std::cout << "En vous baladant dans la foret vous croisez un " << ennemi.getNom() << " avec " << ennemi.getPointsDeVie() << " points de vie et il decide de vous attaquer, vous devez vous defendre!\n" << std::endl;

                // Boucle de combat contre un ennemi
                while (joueur.estVivant() && !ennemi.estVaincu()) {
                    // Invariant: le joueur est encore vivant ou l'ennemi n'est pas encore vaincu

                    std::cout << "------------------------------------------------------------------------------------\n\n"; 
                    // Chaîne de caractère pour stocker la réponse de l'utilisateur
                    std::string action;

                    // Boucle pour vérifier si le choix de l'utilisateur est valide et reposer la question dans le cas où le choix est invalide
                    while (true) {
                        // On demande au joueur ce qu'il souhaite faire
                        std::cout << "Que voulez-vous faire ? (1: Attaquer, 2: Utiliser potion) : ";

                        // On récupère la réponse de l'utilisateur
                        std::cin >> action;

                        // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        // On vérifie si la réponse du joueur est "1" ou "2"
                        if (action == "1" || action == "2") {
                            // La réponse du joueur est "1" ou "2" donc elle est valide, donc on sort de la boucle
                            break; 
                        } 
                        // La réponse n'est pas "1" ou "2" donc elle est invalide et on reboucle
                        else {
                            std::cout << "\nChoix invalide. Veuillez entrer '1' pour attaquer ou '2' pour utiliser une potion.\n";
                        }
                    }
                    // La réponse de l'utilisateur est valide

                    // Gestion de l'action en fonction de la réponse du joueur
                    if (action == "1") {
                        // Le joueur souhaite attaquer l'ennemi

                        // Le personnage attaque l'ennemi
                        if(joueur.attaquer(ennemi)==1){
                            std::cout << "Vous avez attaque le " << ennemi.getNom() << " ! Vous lui avez inflige " << joueur.getAttaque()+joueur.getEffetArme() << " degats, il lui reste " << ennemi.getPointsDeVie() << " points de vie.\n" << std::endl;
                        }

                        // Vérification de si l'ennemi est vaincu
                        if (!ennemi.estVaincu()) {
                            // L'ennemi n'est pas vaincu

                            // L'ennemi attaque le joueur
                            if(ennemi.attaquer(joueur)==1){
                                int degatsReel=ennemi.getAttaque()-joueur.getEffetArmure()-joueur.getEffetCasque();
                                if(degatsReel<0){
                                    degatsReel=0;
                                }
                                std::cout << "\nLe " << ennemi.getNom() << " vous a attaque et vous a inflige " << degatsReel << " degats, il vous reste " << joueur.getPointsDeVie() << " points de vie.\n" << std::endl;
                            }
                        }
                    } 
                    else if (action == "2") {
                        // Le joueur souhaite utiliser une potion
                        if(joueur.aDesPotions()){
                            // Le personnage a au moins une potion dans son inventaire

                            // Affichage des potions de l'inventaire du personnage
                            joueur.afficherPotions();

                            // Chaîne de caractères pour stocker le choix de l'utilisateur
                            std::string choixPotion;

                            // Boucle pour vérifier si le choix de l'utilisateur est valide et reposer la question dans le cas où le choix est invalide
                            while (true) {
                                // Demande au joueur de choisir une potion
                                std::cout << "Choisissez une potion (1: Vie, 2: Attaque, 3: Annuler) : ";
                                std::cin >> choixPotion;

                                // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                // On vérifie si le choix de l'utilisateur est '1', '2' ou '3'
                                if (choixPotion == "1" || choixPotion == "2" || choixPotion == "3") {
                                    // Le choix est valide donc on sort de la boucle
                                    break; 
                                } 
                                // Le choix de l'utilisateur est invalide donc on reboucle sur la question
                                else {
                                    std::cout << "\nChoix invalide. Veuillez entrer '1', '2' ou '3'.\n";
                                }
                            }

                            // On vérifie si le choix de l'utilisateur est "1"
                            if (choixPotion == "1") {
                                // Le joueur souhaite utiliser une potion de vie
                                joueur.utiliserPotion("Potion de Vie");
                            } 
                            // On vérifie si le choix de l'utilisateur est "2"
                            else if (choixPotion == "2") {
                                // Le joueur souhaite utiliser une potion d'attaque
                                joueur.utiliserPotion("Potion d'Attaque");
                            } 
                            // On vérifie si le choix de l'utilisateur est "3"
                            else {
                                // Le joueur ne souhaite plus utiliser de potion
                                std::cout << "Action annulee.\n\n";
                            }
                        }
                        else{
                            // Le personnage n'a pas de potion dans son inventaire
                            std::cout << "Aucune potion dans l'inventaire\n\n";
                        }
                    } 
                }
                std::cout << "------------------------------------------------------------------------------------\n\n"; 

                // Vérification de si le personnage est vivant
                if (joueur.estVivant()) {
                    // Le personnage est vivant à la fin du combat

                    // Affichage de différentes informations au joueur
                    std::cout << "\nVous avez vaincu le " << ennemi.getNom() << " !" << std::endl;
                    joueur.afficherStatistiques();

                    // On vérifie que l'ennemi vaincu n'est pas le titan colossal car le joueur gagne des équipements sauf au dernier ennemi vaincu
                    if(ennemi.getNom() != "Titan colossal") {
                        // L'ennemi vaincu n'est pas le titan colossal

                        // Permet de générer un nombre aléatoire correctement
                        srand(time(0));

                        // Génération des équipements gagnés
                        Casque casqueGagne = Casque::genererCasquePourClasse(classe->getNomClasse());
                        Armure armureGagne = Armure::genererArmurePourClasse(classe->getNomClasse());
                        Arme armeGagne = Arme::genererArmePourClasse(classe->getNomClasse());

                        // On affiche les équipement gagné et on les équipe si le joueur le souhaite
                        std::cout << "\nVous avez gagne : " << casqueGagne.getNom() << std::endl;
                        joueur.equiperCasque(casqueGagne);
                        std::cout << "\nVous avez gagne : " << armureGagne.getNom() << std::endl;
                        joueur.equiperArmure(armureGagne);
                        std::cout << "\nVous avez gagne : " << armeGagne.getNom() << std::endl;
                        joueur.equiperArme(armeGagne);

                        // Génération de la potion gagnée et on l'ajoute à l'inventaire du personnage
                        Potion* potionGagnee = Potion::genererPotionAleatoire();
                        std::cout << "\nVous avez egalement trouve une potion : " << potionGagnee->getNom() << "\n" <<std::endl;
                        joueur.ajouterPotion(potionGagnee);
                    }
                } 
                else {
                    // Le personnage n'est pas vivant à la fin du combat
                    std::cout << "Vous avez ete vaincu. Fin de l'aventure." << std::endl;

                    // On sort de la boucle où on rencontre les ennemis pour aller à l'écran de fin
                    break;
                }
            }
            // La partie est terminée

            // On vérifie si le personnage est vivant
            if (joueur.estVivant()) {
                // Le personnage est vivant donc on affiche un message de victoire
                std::cout << "\nFelicitations, vous avez vaincu tous les ennemis et avez sauve les villages alentours!" << std::endl;
            }

            // On demande au joueur s'il souhaite relancer une partie
            std::cout << "\nVoulez-vous relancer une partie ? (oui/non) : \n";
            std::string relancer;
            std::cin >> relancer;

            // Ignore tout ce qu'il y a après le premier mot si l'utilisateur répond avec plusieurs mots dans le terminal
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // On vérifie si le joueur a répondu oui
            if (relancer != "oui") {
                // Le joueur n'a pas répondu oui donc on termine l'exécution
                std::cout << "\nMerci d'avoir joue et a bientot!\n";

                return 0;
            }

            // Le joueur a répondu oui donc la boucle du jeu se relance
        }
    }
    return 0;
}
