/*#include <stdio.h>
#include <SDL2/SDL.h>*/
#include "main.h"

void main_loop(SDL_Renderer* renderer){
    player_t* player = create_player();
    while(1){
        SDL_Event event;
        if(SDL_PollEvent(&event) && (SDL_QUIT == event.type || (SDL_KEYDOWN == event.type && SDLK_ESCAPE == event.key.keysym.sym)))
            break;
        //on va update ici les informations à l'écran / state du jeu
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}

int main(){
    SDL_Window* fenetre;
    fenetre = SDL_CreateWindow("Pr Avancé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    
    main_loop(ecran);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    printf("ca marche\n");
    return 0;
}