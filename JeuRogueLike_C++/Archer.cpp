#include "Archer.hpp" 

/*  Description : Définition du constructeur de la classe Archer qui appelle le constructeur de "ClassePersonnage" afin de définir ce qu'est un archer en passant trois arguments dans l'appel du constructeur de "ClassePersonnage"
                  Un archer aura donc 100 points de vie et 15 d'attaque et cette classe sera représentée par le nom "Archer"
*/
Archer::Archer() : ClassePersonnage(100, 15, "Archer") {}

