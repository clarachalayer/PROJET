//
// Created by Jb Caron on 20/04/2023.
//
#include <stdlib.h>
#include <allegro5/allegro.h>
#ifndef PROJET_FONCTIONSNAKE_H
#define PROJET_FONCTIONSNAKE_H


 typedef struct PointXY  {

int x;
int y;


}Position ;


void initialisation();
void initialisationCaractere();
void afficherAreneFond(ALLEGRO_DISPLAY *display);
void initialisationTerrain();


#endif //PROJET_FONCTIONSNAKE_H
