#include "main.h"
#include "player.h"

player_t* create_player(){
    player_t* dino = malloc(sizeof(player_t));
    dino->sizex = 50;
    dino->sizey = 50;
    dino->states = malloc(sizeof(char)*2);
    dino->states[0] = "fair";
    dino->states[1] = "distribution";
    return dino;
}