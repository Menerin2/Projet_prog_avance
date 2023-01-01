#include "main.h"

player_t* create_player(SDL_Renderer* renderer){
    player_t* dino = malloc(sizeof(player_t));
    dino->sprite = loadspritesdino(renderer);
    dino->src_sprite = loadspritesplayerposition();
    dino->dst = loadplayerposition();
    dino->in_movement = 0;
    dino->speed = 0;
    dino->frame = 0;
    dino->crouch = 0;
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
    player->dst[0].y += player->in_movement*player->speed;
    player->speed += player->in_movement * 0.4;
    if(player->dst[0].y > 300 - 94){
        player->in_movement = 0;
        player->speed = 0;
        player->dst[0].y = 300 - 94;
    }
    //printf("mvmt: %d , speed : %.1f\n", player->in_movement, player->speed);
}

ennemi_t** create_ennemies(SDL_Renderer* renderer){
    SDL_Texture* all = loadspritesdino(renderer);
    rinfo_t** dimensions = read_infos();
    ennemi_t** ennemies = malloc(sizeof(ennemi_t*)* 7);
    for(int i = 0; i < 7; i++){
        ennemies[i] = (ennemi_t*)malloc(sizeof(ennemi_t));
        ennemies[i]->src = malloc(sizeof(SDL_Rect) * 2);
        ennemies[i]->sprite = all;
        ennemies[i]->src[0].h = dimensions[i]->h;
        ennemies[i]->src[0].w = dimensions[i]->w;
        ennemies[i]->src[0].x = dimensions[i]->x;
        ennemies[i]->src[0].y = dimensions[i]->y;
        ennemies[i]->speed = 10;
        ennemies[i]->fly = false;
        ennemies[i]->frame = 0;
    }
    ennemies[6]->src[1].h = dimensions[7]->h;
    ennemies[6]->src[1].w = dimensions[7]->w;
    ennemies[6]->src[1].x = dimensions[7]->x;
    ennemies[6]->src[1].y = dimensions[7]->y;
    ennemies[6]->fly = true;
    return (ennemies);
}