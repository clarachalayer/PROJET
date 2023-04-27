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
#include "../constant.h"
#define NB_MAX_BALLONS 10
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080



typedef struct {
    float x;
    float y;
    int vitesseX;
    int vitesseY;
    float rayon;
    int actif;
    int haut, droite;
    int score;
    ALLEGRO_COLOR couleur;
} Ballon;


void init_ballons(Ballon ballons[]);
void affiche_ballons(Ballon ballons[]);
void avance_ballons(Ballon ballons[]);
void apparition_etoiles(Ballon ballons[])
#endif //PROJET_TIRAUXBALLONS_H
