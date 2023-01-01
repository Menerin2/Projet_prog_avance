#include "main.h"

player_t* create_player(SDL_Renderer* renderer){
    player_t* dino = malloc(sizeof(player_t));
    dino->sprite = loadspritesdino(renderer);
    dino->src_sprite = loadspritesplayerposition();
    dino->dst = loadplayerposition();
    dino->in_movement = 0;
    dino->speed = 0;
    dino->frame = 0;
    return dino;
}

void free_player(player_t* player){
    free(player->src_sprite);
    free(player);
}

void jump(player_t* player){
    if(player->speed < 0){
        player->in_movement = 1;
    }
    player->dst.y += player->in_movement*player->speed;
    player->speed += player->in_movement * 0.4;
    if(player->dst.y > 300 - 94){
        player->in_movement = 0;
        player->speed = 0;
        player->dst.y = 300 - 94;
    }
    //printf("mvmt: %d , speed : %.1f\n", player->in_movement, player->speed);
}

ennemi_t** create_ennemies(SDL_Renderer* renderer){
    SDL_Texture* all = loadspritesdino(renderer);
    rinfo_t** dimensions = read_infos();
    ennemi_t** ennemies = malloc(sizeof(ennemi_t*)* 6);
    for(int i = 0; i < 6; i++){
        ennemies[i] = (ennemi_t*)malloc(sizeof(ennemi_t));
        ennemies[i]->sprite = all;
        ennemies[i]->src.h = dimensions[i]->h;
        ennemies[i]->src.w = dimensions[i]->w;
        ennemies[i]->src.x = dimensions[i]->x;
        ennemies[i]->src.y = dimensions[i]->y;
        ennemies[i]->speed = 10;
    }

    //les données seront plus tard dans un fichier text et à parser
    //-> permettra de tout boucler
    /*
    //single small cactus = 0
    ennemies[0]->src.h = 70;
    ennemies[0]->src.w = 34;
    ennemies[0]->src.x = 446;
    ennemies[0]->src.y = 2;

    //2 small cacti = 1;
    ennemies[1]->src.h = 70;
    ennemies[1]->src.w = 68;
    ennemies[1]->src.x = 480;
    ennemies[1]->src.y = 2;

    //3 small cacti = 2;
    ennemies[2]->src.h = 70;
    ennemies[2]->src.w = 102;
    ennemies[2]->src.x = 548;
    ennemies[2]->src.y = 2;

    //1 big cactus = 3;
    ennemies[3]->src.h = 96;
    ennemies[3]->src.w = 50;
    ennemies[3]->src.x = 652;
    ennemies[3]->src.y = 2;

    //2 big cacti = 4;
    ennemies[4]->src.h = 96;
    ennemies[4]->src.w = 100;
    ennemies[4]->src.x = 702;
    ennemies[4]->src.y = 2;

    //3 big cacti = 5;
    ennemies[5]->src.h = 96;
    ennemies[5]->src.w = 150;
    ennemies[5]->src.x = 802;
    ennemies[5]->src.y = 2;
    */
    return (ennemies);
}