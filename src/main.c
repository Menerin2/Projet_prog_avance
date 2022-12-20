/*#include <stdio.h>
#include <SDL2/SDL.h>*/
#include "main.h"

void main_loop(SDL_Renderer* renderer){
    player_t* player = create_player(renderer);
    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 87;
    dst.y = 93;

    while(1){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, player->sprite, &player->src_sprite[3], &dst);
        SDL_Event event;
        if(SDL_PollEvent(&event) && (SDL_QUIT == event.type || (SDL_KEYDOWN == event.type && SDLK_ESCAPE == event.key.keysym.sym)))
            break;
        //on va update ici les informations à l'écran / state du jeu
        SDL_RenderPresent(renderer);
    }
    free_player(player);
}

int main(){
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* fenetre;
    fenetre = SDL_CreateWindow("Pr Avancé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(ecran, 255, 255, 255, 255);
    
    main_loop(ecran);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    IMG_Quit();
    return 0;
}