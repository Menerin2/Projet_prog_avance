#include "main.h"

player_t* create_player(SDL_Renderer* renderer){
    player_t* dino = malloc(sizeof(player_t));
    dino->sprite = loadspritesdino(renderer);
    dino->src_sprite = loadspritesposition();
    return dino;
}

void free_player(player_t* player){
    free(player->src_sprite);
    free(player);
}