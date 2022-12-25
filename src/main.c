/*#include <stdio.h>
#include <SDL2/SDL.h>*/
#include "main.h"

void main_loop(SDL_Renderer* renderer){
    player_t* player = create_player(renderer);
    SDL_Rect dst;
    dst.x = 300 - 87/2;
    dst.y = 300 - 93/2;
    dst.w = 87;
    dst.h = 93;
    bool end = true;
    while(end){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, player->sprite, &player->src_sprite[0], &dst);
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                end = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    end=false;
                    break;
                    case SDLK_SPACE:
                    if(player->in_movement == 0){
                        player->in_movement = -1;}
                    break;
                }
        }
        jump(player, &dst);
        //on va update ici les informations à l'écran / state du jeu
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }
    free_player(player);
}

int main(){
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* fenetre;
    fenetre = SDL_CreateWindow("Pr Avancé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(ecran, 255, 255, 255, 255);
    main_loop(ecran);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    IMG_Quit();
    return 0;
}