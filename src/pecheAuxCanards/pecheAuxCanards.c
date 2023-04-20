//
// Created by mathilde curtil on 18/04/2023.
//

#include "pecheAuxCanards.h"
#include <stdio.h>
#include <assert.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define CANARD_LARGEUR 80
#define CANARD_HAUTEUR 60
#define LIGNE_EAU 500
#define NB_CANARDS 10

int initialisation(){

    {
        assert(al_init());
        assert(al_init_primitives_addon()); //initialisation formes
        assert(al_install_keyboard()); //initialisation clavier
        assert(al_install_mouse()); //ini souris
        int fini = 0;

        return fini ;
    }
}
//initialisation canards
void initCanards(Canards canards[]) {
    int i = 0;
    for (i = 0; i < NB_CANARDS; i++) {
        canards[i].actif = 0;
        canards[i].width = 10 + rand() % 20;
        canards[i].height = canards[i].width * 2 / 3;
    }
}
//affichage
void afficherCanards(Canards canards[]) {
    int i = 0;
    for (i = 0; i < NB_CANARDS; i++) {
        al_draw_filled_ellipse(canards[i].x, canards[i].y, canards[i].width, canards[i].height,
                               al_map_rgb(255, 100 + rand() % 156, 100 + rand() % 156));
    }
}

int gagnant(Joueur1 joueur1, Joueur2 joueur2){
    if (joueur1.nbCanards > joueur2.nbCanards) {
        printf("Joueur 1 vous êtes le gagnant !");
        int ticket = 0;
        joueur1.ticket = ticket++;
    }else if(joueur2.nbCanards > joueur1.nbCanards) {
        printf("Joueur 2 vous êtes le gagnat !");
        int ticket = 0;
        joueur2.ticket = ticket++;
    }




void erreur(const char *txt) {
    printf("ERREUR : %s", txt);
    exit(EXIT_FAILURE);
}
int pecheCanards() {
    initialisation();

    //déclarations
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event = {};
    ALLEGRO_COLOR noir;
    ALLEGRO_COLOR bleu;
    ALLEGRO_COLOR vert;
    ALLEGRO_BITMAP *canard_bitmap = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *fontBangers60 = NULL;
    ALLEGRO_FONT *fontBangers160 = NULL;
    int score = 0;

    //création display=>allocation
    display = al_create_display(3000,1800);
    //céation file
    queue = al_create_event_queue();
    //ajouter les sources
    al_register_event_source(queue, al_get_display_event_source(display));
    //clavier
    al_register_event_source(queue,al_get_keyboard_event_source());

    //chargement image canard
    canard_bitmap = al_load_bitmap("canard.png");
    assert(canard_bitmap);

    noir = al_map_rgb(0,0,0);
    bleu = al_map_rgb(0,0,200);
    vert = al_map_rgb(0,255,0);

    //position des canards
    int canard_x[NB_CANARDS], canard_y[NB_CANARDS];
    for (int i = 0; i < NB_CANARDS; i++) {
        canard_x[i] = rand() % (800 - CANARD_LARGEUR);
        canard_y[i] = rand() % (LIGNE_EAU - CANARD_HAUTEUR);
    }

    timer = al_create_timer(1.0 / 60);
    if (!timer) {
        al_destroy_display(display);
        al_destroy_font(fontBangers60);
        al_destroy_font(fontBangers160);
        erreur("Création du timer");
    }

    queue = al_create_event_queue();
    if (!queue) {
        al_destroy_display(display);
        al_destroy_font(fontBangers60);
        al_destroy_font(fontBangers160);
        al_destroy_timer(timer);
        erreur("Création de l'event queue");
    }
    al_start_timer(timer);
    //boucle principale
    bool fini;
    while(!fini) {
        //gestion des événements
        if (al_get_next_event(queue, &event)) {
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                fini = 1;
            }
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    fini = 1;
                }
            }
            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                int x = event.mouse.x;
                int y = event.mouse.y;
                //vérification si on a cliqué sur un canard
                for (int i = 0; i < NB_CANARDS; i++) {
                    if (x >= canard_x[i] && x <= canard_x[i]+CANARD_LARGEUR &&
                        y >= canard_y[i] && y <= canard_y[i]+CANARD_HAUTEUR) {
                        score++;
                        canard_x[i] = rand() % (800 - CANARD_LARGEUR);
                        canard_y[i] = rand() % (LIGNE_EAU - CANARD_HAUTEUR);
                        break;
                    }
                }
            }
        }

        ALLEGRO_FONT *fontBangers60 = al_load_ttf_font("../fonts/bangers/bangers-Regular.ttf", 60, 0);
        ALLEGRO_FONT *fontBangers160 = al_load_ttf_font("../fonts/bangers/bangers-Regular.ttf", 160, 0);
        if (!fontBangers60 || !fontBangers160) {
            al_destroy_display(display);
            erreur("Chargement de la police bangers");
        }

    }
        al_clear_to_color(bleu);
        al_draw_filled_rectangle(0, LIGNE_EAU, 800, 600, vert); //ligne d'eau
        void afficherCanards(); //affichage canards
        al_draw_textf(NULL, noir, 10, 10, 0, "Score : %d", score);//affichage score
        void gagnant;
        al_flip_display();
    }
    
    //libérations
    ALLEGRO_BITMAP *canard_bitmap = NULL;
    al_destroy_bitmap(canard_bitmap);
    ALLEGRO_FONT *fontBangers160 = NULL;
    al_destroy_font(fontBangers160);
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    al_destroy_event_queue(queue);
    ALLEGRO_DISPLAY *display = NULL;
    al_destroy_display(display);
    return 0;
}
