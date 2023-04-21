//
// Created by clara on 19/04/2023.
//

#include "tirAuxBallons.h"
void initialisation() {

    al_init(); // Initialisation d'Allegro
    assert(al_init_primitives_addon());
    assert(al_init_image_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());

}
void init_ballons(Ballon ballons[]) {
    int i = 0;
    for (i = 0; i < NB_DE_BALLONS; i++) {
        ballons[i].vitesse = 1;
        ballons[i].actif = 1;
        ballons[i].x = ballons[i].width + rand() % (CAGE_WIDTH - (ballons[i].width * 2));
        ballons[i].y = ballons[i].height + rand() % (CAGE_HEIGHT - (ballons[i].height * 2));
        ballons[i].height = 1 + rand() % 2;
        ballons[i].width = ballons[i].height;
    }
}

void affiche_ballons(Ballon ballons[]){
    int i = 0;
        for (i = 0; i < NB_DE_BALLONS; i++) {
            if (ballons[i].actif) {
                al_draw_filled_ellipse(ballons[i].x= rand()%, ballons[i].y, ballons[i].width, ballons[i].height,
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
            if (ballons[i].x - ballons[i].width < 0) {
                ballons[i].actif = 0;
            }
        }
    }
}
void apparition_etoiles(Ballon ballons[]) {
    int i = 0;
    for (i = 0; i < NB_DE_BALLONS; i++) {
        if (!ballons[i].actif && rand() % 1000 < 2) {
            ballons[i].x = CAGE_HEIGHT - ballons[i].width;
            ballons[i].y = ballons[i].height + rand() % (CAGE_WIDTH - (ballons[i].width * 2));
            ballons[i].actif = 1;
        }
    }
}
void tirBallons(queue, stats){
    init_ballons();
    affiche_ballons();
    avance_ballons();

    Img.ballons

    while(1){
        wait(file);
        switch
    }
    al_destroy_display(display);
}*/


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



    int main(){





}