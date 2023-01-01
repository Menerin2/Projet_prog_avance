#include "main.h"

armada_t* initialisation_ennemies(SDL_Renderer* renderer){
    //choix des type/nombre d'ennemis, à faire en lecture de .txt plus tard
    int nbr_ennemis = 8;
    srand(time(NULL));
    int* type = malloc(sizeof(int)* nbr_ennemis);
    for(int i = 0; i < nbr_ennemis; i++){
        type[i] = rand() % 6;
    }
    //set des positions; to be changed
    SDL_Rect dest_temp;

    //premier link
    armada_t* ennemies = malloc(sizeof(armada_t));
    link_t* last = NULL;
    ennemies->first = last;
    //remplissage des links
    ennemi_t** kind = create_ennemies(renderer);
    for(int i = 0; i < nbr_ennemis; i++){
        dest_temp.x = (600 * nbr_ennemis) - (i * 600);
        dest_temp.y = 300 - kind[type[i]]->src.h; // à changer pour mettre à niveau
        dest_temp.h = kind[type[i]]->src.h;
        dest_temp.w = kind[type[i]]->src.w;
        insert_first(ennemies, kind[type[i]], dest_temp);
    }
    return(ennemies);
}

void insert_first(armada_t* ennemies, ennemi_t* kind, SDL_Rect dst){
    link_t* new_link = malloc(sizeof(link_t));
    new_link->guy = kind;
    new_link->dst = dst;
    new_link->next = ennemies->first;
    ennemies->first = new_link;
}

void update_list(armada_t* ennemies, int* score){
    if(ennemies->first->dst.x < 0){
        link_t* temp = malloc(sizeof(link_t));
        memcpy(temp, ennemies->first, sizeof(link_t));
        delete_first(ennemies);
        insert_last(ennemies, temp);
        ++*score;
    }
}

void delete_first(armada_t* ennemies){
    link_t* temp = ennemies->first;
    ennemies->first = temp->next;
    free(temp);
}

void insert_last(armada_t* ennemies, link_t* last_link){
    last_link->next = NULL;
    link_t* temp = ennemies->first;
    while(temp->next != NULL){
        temp = temp->next;
    }
    last_link->dst.x = temp->dst.x + 600;
    temp->next = last_link;
}