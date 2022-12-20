#include "main.h"
#include "player.h"

player_t* init_player(){
    player_t* player = malloc(sizeof(player->sizex) + sizeof(player->sizey) + sizeof(player->states));
    return player;
}

void create_player(player_t* dino){
    printf("works");
    dino->sizex = 50;
    dino->sizey = 50;
    dino->states = NULL;
}