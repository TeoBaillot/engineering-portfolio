#include "Guerrier.hpp"

/*  Description : Définition du constructeur de la classe Guerrier qui appelle le constructeur de "ClassePersonnage" afin de définir ce qu'est un guerrier en passant trois arguments dans l'appel du constructeur de "ClassePersonnage"
                  Un guerrier aura donc 150 points de vie et 10 d'attaque et cette classe sera représentée par le nom "Guerrier"
*/
Guerrier::Guerrier() : ClassePersonnage(150, 10, "Guerrier") {}
