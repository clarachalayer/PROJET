#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include "fonctionsnake.h"


int main() {

    initialisation();
    ALLEGRO_DISPLAY *display = al_create_display(3000, 1800);

    afficherAreneFond(display);

    return 0;
}