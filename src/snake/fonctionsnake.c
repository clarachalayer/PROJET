//
// Created by Jb Caron on 20/04/2023.
//
#include<stdio.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include "fonctionsnake.h"

void initialisation() {

    al_init(); // Initialisation d'Allegro
    assert(al_init_primitives_addon());
    assert(al_init_image_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());

}

void initialisationCaractere() {




}

void afficherAreneFond(ALLEGRO_DISPLAY *display) {

    int x = 1076;
    int y = 476;
    int w = 106;
    int h = 106;


    al_set_window_title(display, "Gear 4");
    ALLEGRO_BITMAP *arene = al_load_bitmap("../src/snake/imagesnake/arene.jpeg");
    ALLEGRO_BITMAP *fond = al_load_bitmap("../src/snake/imagesnake/fonds.jpeg");

    assert(arene);
    al_set_display_icon(display, fond);
    al_set_display_icon(display, arene);
    al_draw_bitmap(fond, 0, 0,10000);
    al_draw_bitmap(arene, 1076, 476,10000);

    al_set_clipping_rectangle(x, y, w, h);

    // Dessin dans la zone de pixel définie
    al_draw_filled_rectangle( x, y, x + w, y + h, al_map_rgb(255, 0, 0));

    for (int i=0;i<8;i++) {

        al_set_clipping_rectangle(x, y, w, h);

        for (int j = 0; j < 8; j++) {

            al_set_clipping_rectangle(x, y, w, h);

            //al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(255, 0, 0));
            x=x+106;
        }
        x=1076;
        y=y+106;
    }

    al_flip_display();
    al_rest(10);
    al_destroy_display(display);

    al_destroy_bitmap(arene);
    al_destroy_bitmap(fond);


}

void initialisationTerrain(ALLEGRO_DISPLAY *display){

    int x = 1076;
    int y = 476;
    int w = 106;
    int h = 106;
    al_set_clipping_rectangle(x, y, w, h);

    // Dessin dans la zone de pixel définie
    for (int i=0;i<7;i++) {
        al_set_clipping_rectangle(x, y, w, h);

        for (int j = 0; j < 7; j++) {
            x=x+106;
            al_set_clipping_rectangle(x, y, w, h);

            al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(i*j, 10*j, 10*i));
        }
        y=y+106;
        x=1076;
    }

    // Attente d'une touche pour quitter
    al_rest(2.0);
    al_destroy_display(display);


}



