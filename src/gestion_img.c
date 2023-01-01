#include "main.h"

SDL_Texture* loadspritesdino(SDL_Renderer* renderer){
    SDL_Surface* img = IMG_Load("./ressource/sprites.png");
    if(img == NULL)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return NULL;
    }
    SDL_Texture* dinos = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);
    return dinos;
}

SDL_Rect* loadspritesplayerposition(){
    SDL_Rect* src_sprite = malloc(sizeof(SDL_Rect) * 8);
    for(int i = 0; i < 6; i++){
        src_sprite[i].h = 94;
        src_sprite[i].w = 87;
        src_sprite[i].x = 1338 + (src_sprite[i].w * i);
        src_sprite[i].y = 2;
    }
    for(int i = 6; i < 8; i++){
        src_sprite[i].h = 59;
        src_sprite[i].w = 117;
        src_sprite[i].x = 1866 + (src_sprite[i].w *(i-6));
        src_sprite[i].y = 36;
    }
    return(src_sprite);
}
SDL_Rect* loadplayerposition(){
    SDL_Rect* dst = malloc(sizeof(SDL_Rect) * 2);
    for(int i = 0; i < 2; i++){
        dst[i].x = 200;
        dst[i].y = 300 - (94 - 35 * i);
        dst[i].w = 87 + (30 * i);
        dst[i].h = 94 - (35 * i);
    }
    return(dst);
}

SDL_Rect loadBgSrc(){
    SDL_Rect src;
    src.h = 23;
    src.w = 2399;
    src.x = 2;
    src.y = 104;
    return src;
}

bg_t** init_backgrounds(SDL_Renderer* renderer){
    bg_t** bgs = malloc(sizeof(bg_t*) * 2);
    for(int i = 0; i < 2; i++){
        bgs[i] = (bg_t*)malloc(sizeof(bg_t));
        bgs[i]->sprite = loadspritesdino(renderer);
        bgs[i]->src = loadBgSrc();
        bgs[i]->dst.h = bgs[i]->src.h;
        bgs[i]->dst.w = bgs[i]->src.w;
        bgs[i]->dst.x = 0 + (i * bgs[i]->src.w);
        bgs[i]->dst.y = 292;
    }
    return bgs;
}