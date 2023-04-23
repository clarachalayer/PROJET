//
// Created by clara on 19/04/2023.
//

#include "tirAuxBallons.h"


void init_ballons(Ballon ballons[]) {
    int i = 0;
    for (i = 0; i < NB_DE_BALLONS; i++) {
        ballons[i].vitesse = 1;
        ballons[i].actif = 1;
        ballons[i].x = CAGE_WIDTH + rand() % (CAGE_WIDTH - (ballons[i].width * 2));
        ballons[i].y = CAGE_HEIGHT + rand() % (CAGE_HEIGHT - (ballons[i].height * 2));
        ballons[i].d = BALLON_DIAMETRE;

    }
}

void affiche_ballons(Ballon ballons[]){
    int i = 0;
        for (i = 0; i < NB_DE_BALLONS; i++) {
            if (ballons[i].actif) {
                al_draw_filled_circle(180,180,BALLON_DIAMETRE,
                                       al_map_rgb(200 + rand() % 56, 200 + rand() % 56, 200 + rand() % 56));
            }
        }
}
void avance_ballons(Ballon ballons[]) {
    int i = 0;
    for (i = 0; i < NB_DE_BALLONS; i++) {
        if (ballons[i].actif) {
            ballons[i].x -= ballons[i].vitesse;
            ballons[i].y -= ballons[i].vitesse;
            if (ballons[i].x - ballons[i].y < 0) {
                ballons[i].actif = 0;
            }
        }
    }
}

void tirBallons(event, stats){
    init_ballons();
    affiche_ballons();
    avance_ballons();

    Img.ballons

    while(1){
        ALLEGRO_TIMER *timer=NULL;
        ALLEGRO_EVENT event;

        al_wait_for_event(fifo, &event);
        timer= al_create_timer(1);
        al_start_timer(timer);
        printf("Le temps du joueur 1 à demarrer %d.\n");
        switch
    }
    al_destroy_display(display);
}


int gagnant(Joueur1 joueur1, Joueur2 joueur2){
    if (joueur1.tmp < joueur2.tmp) {
        printf("Joueur 1 vous êtes le gagnant !");
        int ticket = 0;
        joueur1.ticket = ticket++;
    }else if(joueur2.tmp > joueur1.tmp) {
        printf("Joueur 2 vous êtes le gagnat !");
        int ticket = 0;
        joueur2.ticket = ticket++;
    }

}







