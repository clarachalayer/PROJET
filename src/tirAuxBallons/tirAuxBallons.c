//
// Created by clara on 19/04/2023.
//

#include "tirAuxBallons.h"


void init_Ballons(Ballon Ballons[]){
    int i = 0;
    for (i = 0; i < NB_MAX_BALLONS; i++) {
        Ballons[i].x = 380+80+rand()%(1580-380);
        Ballons[i].actif = 0;
        Ballons[i].y = 250+80+rand()%(900-250);
    }
}
void affiche_Ballons(Ballon Ballons[]){
    int i=0;
    for(i=0; i < NB_MAX_BALLONS;i++){

        al_draw_filled_circle(440+rand()%(1580-480), 310+rand()%(900-360), 60,COULEUR_ALEA);


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
    init_ballons(Ballon ballons[]);
    affiche_ballons(Ballon ballons[]);
    avance_ballons(Ballon ballons[]);

    Img.ballons

    while(1){
        //déclaration
        bool fini = false;
        ALLEGRO_DISPLAY*fenetre = NULL;
        ALLEGRO_EVENT_QUEUE* fifo = NULL;
        ALLEGRO_EVENT event;
        ALLEGRO_TIMER *timer=NULL;
        //créeation file
        fifo = al_create_event_queue();
        //
        al_wait_for_event(fifo, &event);
        //debut du temps
        timer= al_create_timer(1);
        al_start_timer(timer);
        printf("Le temps du joueur 1 à demarrer %d.\n");
        // Création des éléments
        fenetre = al_create_display(WIDTH, HEIGHT);
        assert(fenetre != NULL);
        al_set_window_title(fenetre, "Jeu tir aux ballons");
        al_register_event_source(fifo, al_get_display_event_source(fenetre));
        al_register_event_source(fifo, al_get_mouse_event_source());
        al_register_event_source(fifo, al_get_timer_event_source(timer));
        //first display
        al_flip_display();






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







