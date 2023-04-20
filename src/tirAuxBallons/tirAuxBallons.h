//
// Created by clara on 19/04/2023.
//

#ifndef PROJET_TIRAUXBALLONS_H
#define PROJET_TIRAUXBALLONS_H

typedef struct {
    int x, y;
    int vitesse;
} Ballon;

void init_ballons(Ballon ballons[]);
void affiche_ballons(Ballon ballons[]);
void avance_ballons(Ballon ballons[]);
void collision_ballon(Ballon ballons[], Ennemi ennemis[], Vaisseau *vaisseau);
#endif //PROJET_TIRAUXBALLONS_H
