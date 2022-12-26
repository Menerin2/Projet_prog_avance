#include "main.h"

armada_t* initialisation_ennemies(SDL_Renderer* renderer){
    //choix des type/nombre d'ennemis, à faire en lecture de .txt plus tard
    int nbr_ennemis = 40;
    srand(time(NULL));
    int* type = malloc(sizeof(int)* nbr_ennemis);
    for(int i = 0; i < nbr_ennemis; i++){
        type[i] = rand() % 6;
    }
    //set des positions; to be changed
    SDL_Rect dest_temp;
    dest_temp.h = 0;
    dest_temp.w = 0;
    dest_temp.x = 400 * nbr_ennemis;
    dest_temp.y = 300;

    //creation du premier link
    armada_t* ennemies = malloc(sizeof(armada_t*));
    link_t* last = NULL;
    ennemies->first = last;
    //remplissage des links
    ennemi_t** kind = create_ennemies(renderer);
    for(int i = 0; i < nbr_ennemis; i++){
        link_t* newer = malloc(sizeof(link_t*));
        newer->guy = kind[type[i]];
        newer->dst = dest_temp;
        newer->dst.x = dest_temp.x - (400 * (nbr_ennemis - i));
        newer->next = ennemies->first;
        ennemies->first = newer;
    }
    return(ennemies);
}