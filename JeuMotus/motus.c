// Auteurs: Téo Baillot d'Estivaux, Simon Leguilloux
// Date de création: 28/05/2024
// Date de dernière modification: 30/05/2024


#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "vue.h"

int main(int argc, char *argv[]) {
    if (OpenDisplay(argc, argv) == 0) {
      fprintf(stderr,"Can't open display\n");
      return EXIT_FAILURE;
    }

    // initialiser la donnée partagée avec le modèle
    DonneePartagee d;  
    initDonneePartagee(&d);

    // créer l'IG et l'afficher à l'écran
    fenetreDemarrage(argc, argv, &d);
    MainLoop();
    
    return EXIT_SUCCESS;
}

