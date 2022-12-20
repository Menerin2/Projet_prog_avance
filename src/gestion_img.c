#include "main.h"

SDL_Texture* loadspritesdino(SDL_Renderer* renderer){
    SDL_Surface* img = IMG_Load("../ressource/sprites.png");
    SDL_Texture* dinos = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);
    return dinos;
}

SDL_Rect* loadspritesposition(){
    SDL_Rect* src_sprite = malloc(sizeof(SDL_Rect) * 6);
    for(int i = 0; i < 6; i++){
        src_sprite[i].h = 93;
        src_sprite[i].w = 87;
        src_sprite[i].x = 1338 + (src_sprite[i].w * i);
        src_sprite[i].y = 2;
    }
    return(src_sprite);
}