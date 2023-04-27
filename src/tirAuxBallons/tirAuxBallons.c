//
// Created by clara on 19/04/2023.
//

#include "tirAuxBallons.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>
#include <allegro5/bitmap.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define NOIR al_map_rgb(0,0,0)
#define NB_MAX_BALLONS 10
#define COULEUR_ALEA al_map_rgb(rand()%256, rand()%256, rand()%256)
#define RAYON 40


void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);

}

void afficher_temps(ALLEGRO_FONT *fontBangers60,ALLEGRO_TIMER *timer){
    int temps_ecoule= al_get_timer_count(timer);
    int secondes = (int) temps_ecoule/60;
    int millisecondes = (int) (temps_ecoule-secondes)/0.06;
    al_draw_textf(fontBangers60, al_map_rgb(255,175,44),SCREEN_WIDTH-350,10,0,"Temps: %02d:%02d", secondes,millisecondes%1000);
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

void collision_Ballons(Ballon Ballons[]){
    int i=0,j=0;
    for(i = 0; i < NB_MAX_BALLONS; i++){
        if(Ballons[i].actif==1){
            for(j = i+1; j < NB_MAX_BALLONS; j++){ // commence à j=i+1 pour éviter de comparer deux fois le même couple de ballons
                if(Ballons[j].actif==1){ // ajoute une vérification pour voir si le ballon j est actif
                    int d1 = (Ballons[i].x - Ballons[j].x)*(Ballons[i].x - Ballons[j].x) + (Ballons[i].y - Ballons[j].y)*(Ballons[i].y - Ballons[j].y);
                    if(d1 <= (RAYON*2)* (RAYON*2) ){
                        Ballons[i].haut=!Ballons[i].haut;
                        Ballons[i].droite=!Ballons[i].droite;
                    }
                }
            }
        }
    }
}


void mouvement_Ballons(Ballon Ballons[]) {
    int i = 0;
    for (i = 0; i < NB_MAX_BALLONS; i++) {
        if (Ballons[i].actif) {
            if (Ballons[i].x - RAYON < 380) {
                Ballons[i].droite=1;
            }
            else if (Ballons[i].x + RAYON >= 1580) {
                Ballons[i].droite=0;
            }
            if(Ballons[i].y - RAYON < 250) {
                Ballons[i].haut = 0;
            }
            else if(Ballons[i].y + RAYON >= 900) {
                Ballons[i].haut = 1;
            }

            if(Ballons[i].haut==1){
                Ballons[i].y -= Ballons[i].vitesseY;
            }
            else{
                Ballons[i].y += Ballons[i].vitesseY;
            }

            if(Ballons[i].droite==1){
                Ballons[i].x += Ballons[i].vitesseX;
            }
            else{
                Ballons[i].x -= Ballons[i].vitesseX;
            }

        }
    }
}



void tirBallons(event, stats){
    srand(time(NULL));
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();


    ALLEGRO_DISPLAY * display = NULL;
    ALLEGRO_EVENT_QUEUE * queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_BITMAP *fond = NULL;
    ALLEGRO_TIMER *timer=NULL;
    printf("test");
    ALLEGRO_FONT *font=NULL;

    font= al_load_font("../font/Bangers-Regular.ttf",60,0);

    Ballon Ballons[NB_MAX_BALLONS]={0};

    timer= al_create_timer(1.0/60);
    al_start_timer(timer);

    fond= al_load_bitmap("..\\image\\fond.jpg");
    queue = al_create_event_queue();
    display = al_create_display(SCREEN_WIDTH,SCREEN_HEIGHT);



    al_install_keyboard();

    al_register_event_source(queue,al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    init_Ballons(Ballons);
    al_draw_scaled_bitmap(fond,0,0,900,600,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);

    bool fin=0;
    while(!fin){
        al_wait_for_event(queue,&event);
        switch(event.type){
            case ALLEGRO_EVENT_KEY_DOWN:
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_ESCAPE:
                        fin=1;
                        break;
                }
                break;
            case ALLEGRO_EVENT_TIMER:


                al_draw_filled_rectangle(380,250,1580,900, NOIR);

                mouvement_Ballons(Ballons);
                collision_Ballons(Ballons);

                afficher_temps(font,timer);
                affiche_Ballons(Ballons);

                al_flip_display();
                break;
        }
    }


    al_destroy_display(display);
    al_destroy_font(font);
    al_destroy_event_queue(queue);
    al_destroy_bitmap(fond);
    al_destroy_timer(timer);


    return 0;
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







