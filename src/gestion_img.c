#include "main.h"

SDL_Texture* loadspritesdino(SDL_Renderer* renderer){
    SDL_Surface* img = IMG_Load("./ressource/sprites.png");
    if(img == NULL)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return NULL;
    }
    SDL_Texture* dinos = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);
    return dinos;
}

SDL_Rect* loadspritesplayerposition(){
    SDL_Rect* src_sprite = malloc(sizeof(SDL_Rect) * 6);
    for(int i = 0; i < 6; i++){
        src_sprite[i].h = 94;
        src_sprite[i].w = 87;
        src_sprite[i].x = 1338 + (src_sprite[i].w * i);
        src_sprite[i].y = 2;
    }
    return(src_sprite);
}
SDL_Rect loadplayerposition(){
    SDL_Rect dst;
    dst.x = 100 - 94/2;
    dst.y = 300 - 87/2;
    dst.w = 87;
    dst.h = 94;
    return(dst);
}