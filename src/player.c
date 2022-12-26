#include "main.h"

player_t* create_player(SDL_Renderer* renderer){
    player_t* dino = malloc(sizeof(player_t));
    dino->sprite = loadspritesdino(renderer);
    dino->src_sprite = loadspritesplayerposition();
    dino->dst = loadplayerposition();
    dino->in_movement = 0;
    return dino;
}

void free_player(player_t* player){
    free(player->src_sprite);
    free(player);
}

void jump(player_t* player){
    if(player->dst.y < 200){
        player->in_movement = 1;
    }
    player->dst.y += player->in_movement*10;
    if(player->dst.y > 300 - 87/2){
        player->in_movement = 0;
        player->dst.y = 300-87/2;
    }
}
/*load les cactus*/
/*
player_t** create_ennemies(SDL_Renderer* renderer){
    player_t** ennemies = malloc(sizeof(player_t)* 6);
    SDL_Texture* all = loadspritesdino(renderer);
    for(int i = 0; i < 8; i++){
        ennemies[i]->sprite = all;
        ennemies[i]->src_sprite = loadallsprites(i);
        ennemies[i]->in_movement = 1;
    }
    
}*/