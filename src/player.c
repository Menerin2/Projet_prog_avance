#include "main.h"

player_t* create_player(SDL_Renderer* renderer){
    player_t* dino = malloc(sizeof(player_t));
    dino->sprite = loadspritesdino(renderer);
    dino->src_sprite = loadspritesposition();
    dino->in_movement = 0;
    return dino;
}

void free_player(player_t* player){
    free(player->src_sprite);
    free(player);
}

void jump(player_t* player, SDL_Rect* dst){
    if(dst->y < 200){
        player->in_movement = 1;
    }
    dst->y += player->in_movement*10;
    if(dst->y > 300 - 87/2){
        player->in_movement = 0;
        dst->y = 300-87/2;
    }
} 