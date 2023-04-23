//
// Created by clara on 19/04/2023.
//

#ifndef PROJET_TIRAUXBALLONS_H
#define PROJET_TIRAUXBALLONS_H
#include "tirAuxBallons.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#define NB_DE_BALLONS 10
#define CAGE_WIDTH 700
#define CAGE_HEIGHT 600
#define BALLON_DIAMETRE 90
#include "../constant.h"


typedef struct {
    int x, y;
    int d;
    int vitesse;
    int actif;
    ALLEGRO_BITMAP *image;
} Ballon;

void init_ballons(Ballon ballons[]);
void affiche_ballons(Ballon ballons[]);
void avance_ballons(Ballon ballons[]);
void apparition_etoiles(Ballon ballons[])
#endif //PROJET_TIRAUXBALLONS_H
