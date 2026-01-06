#include "Magicien.hpp"

/*  Description : Définition du constructeur de la classe Magicien qui appelle le constructeur de "ClassePersonnage" afin de définir ce qu'est un magicien en passant trois arguments dans l'appel du constructeur de "ClassePersonnage"
                  Un magicien aura donc 80 points de vie et 20 d'attaque et cette classe sera représentée par le nom "Magicien"
*/
Magicien::Magicien() : ClassePersonnage(80, 20, "Magicien") {}
