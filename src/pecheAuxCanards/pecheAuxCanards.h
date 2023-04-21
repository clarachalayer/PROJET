//
// Created by mathilde curtil on 18/04/2023.
//

#ifndef PROJET_PECHEAUXCANARDS_H
#define PROJET_PECHEAUXCANARDS_H

//initialisations
int initialisation () ;

typedef struct {
    int x, y;
    int width, height;
    int actif;
} Canards;

typedef struct {
    int ticket;
    int nbCanards;
    int score;
}Joueur1;

typedef struct {
    int ticket;
    int nbCanards;
    int score;
}Joueur2;

void afficherCanards();

#endif //PROJET_PECHEAUXCANARDS_H
