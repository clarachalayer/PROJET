//
// Created by clara on 19/04/2023.
//

#include "tirAuxBallons.h"


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

int main(){





}