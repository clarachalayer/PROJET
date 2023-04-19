#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "src/pecheAuxCanards/pecheAuxCanards.h"
#include "/src/tirAuxBallons/tirAuxBallons.h"

void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);
}

int main(void) {
    if (!al_init()) {
        erreur("Initialisation Allegro");
    }
    if (!al_install_keyboard()) {
        erreur("Installation clavier");
    }
    if (!al_init_primitives_addon()) {
        erreur("Initialisation primitives de dessin");
    }
    if (!al_init_image_addon()) {
        erreur("Initialisation images");
    }




    return 0;
}
