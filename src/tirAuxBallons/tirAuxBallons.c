//
// Created by clara on 19/04/2023.
//

#include "tirAuxBallons.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define RAYON 60

#define COULEUR_ALEA al_map_rgb(rand()%256, rand()%256, rand()%256)

void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);

}

void init_Ballons(Ballon Ballons[]){
    int i = 0;
    for (i=0;i<NB_MAX_BALLONS;i++) {
        Ballons[i].x = 440 + rand() % (1580 - 480);
        Ballons[i].y = 310 + rand() % (900 - 380);
        Ballons[i].actif = 1;
        Ballons[i].score = 10;
        Ballons[i].rayon = RAYON;
        Ballons[i].vitesseX=5+rand()%8;
        Ballons[i].vitesseY=5+rand()%8;
        Ballons[i].haut=rand()%2;
        Ballons[i].droite=rand()%2;
    }
}

void affiche_Ballons(Ballon Ballons[]){
    int i = 0;
    for(i=0; i < NB_MAX_BALLONS;i++){
        if (Ballons[i].actif==1){
            al_draw_filled_circle(Ballons[i].x,Ballons[i].y, RAYON, COULEUR_ALEA);
        }
    }
}

bool collision_Ballons(Ballon Ballons[]){
    int i=0,j=0;
    for(i = 0; i < NB_MAX_BALLONS; i++){
        if(Ballons[i].actif==1){
            for(j = i+1; j < NB_MAX_BALLONS; j++){ // commence à j=i+1 pour éviter de comparer deux fois le même couple de ballons
                if(Ballons[j].actif==1){ // ajoute une vérification pour voir si le ballon j est actif
                    int d1 = (Ballons[i].x - Ballons[j].x)*(Ballons[i].x - Ballons[j].x) + (Ballons[i].y - Ballons[j].y)*(Ballons[i].y - Ballons[j].y);
                    if(d1 <= (RAYON*2)* (RAYON*2) )
                        return true; // si la distance entre les deux ballons est inférieure ou égale au diamètre des ballons, il y a collision
                }
            }
        }
    }
    return false; // si aucune collision n'a été détectée, retourne false
}


void tirBallons(event, stats){
    ALLEGRO_DISPLAY * display = NULL;
    ALLEGRO_TIMER * timer = NULL;
    Ballon Ballons[NB_MAX_BALLONS];

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

    display= al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_BITMAP * font = al_load_bitmap("../fond.jpg");
    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_scaled_bitmap(font,0,0,900,600,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    al_draw_filled_rectangle(380,250,1580,900, al_map_rgb(0,0,0));

    //initialisations des ballons




    //déclaration
    int pause = 0, gameOver = 0, dessin = 0, waitInMilliseconds = -1;
    bool fini = false;
    ALLEGRO_DISPLAY*fenetre = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer=NULL;
    //créeation file
    queue = al_create_event_queue();
    //debut du temps
    timer= al_create_timer(1);
    al_start_timer(timer);
    assert(fenetre != NULL);
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    do{
        al_wait_for_event(queue, &event);
        if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            for (int i=0;i<10,i++){

            }

        }//souris sur un ballon, si oui le desactiver


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







