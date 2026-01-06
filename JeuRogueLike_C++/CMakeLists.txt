cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(JEU)

# Spécifie le standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter l'exécutable à partir des fichiers source
add_executable(jeu main.cpp Personnage.cpp ClassePersonnage.cpp Potion.cpp PotionDAttaque.cpp PotionDeVie.cpp Inventaire.cpp Ennemi.cpp Equipement.cpp Arme.cpp Armure.cpp Casque.cpp Guerrier.cpp Archer.cpp Magicien.cpp)
