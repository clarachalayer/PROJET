#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "./src/pecheAuxCanards/pecheAuxCanards.h"
#include "./src/tirAuxBallons/tirAuxBallons.h"
#include "./src/constant.h"

void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);
}

int main(void) {
    initialisation();
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
    /*image et texte pas dans la boucle
    file
    display
    IMG.carte
    while(1)
        wait
        switch event.type
            case KEYDOWN:
                switch keycode
                    case A:
                        tirBallons(file,&stats)
    }



*/

    return 0;
}
