//
// Created by clara on 20/04/2023.
//

#ifndef PROJET_CONSTANT_H
#define PROJET_CONSTANT_H
#define SCREEN_WIDTH 3000
#define SCREEN_HEIGHT 1800
int initialisation() {

    {
        assert(al_init());
        assert(al_init_primitives_addon()); //initialisation formes
        assert(al_install_keyboard()); //initialisation clavier
        assert(al_install_mouse()); //ini souris
        int fini = 0;

        return fini;
    }
}
//Joueur 1
typedef struct {
    int ticket;
    int nbCanards;
    int tmp;
}Joueur1;
//Joueur 2
typedef struct {
    int ticket;
    int nbCanards;
    int tmp;
}Joueur2;

#endif //PROJET_CONSTANT_H
