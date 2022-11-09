#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
int main(int argc, char* argv[]){
    SDL_Window* fenetre;
    SDL_Event events;
    bool terminer = false;
    fenetre = SDL_CreateWindow("Pr Avancé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    while(!terminer){
        SDL_RenderClear(ecran);
        SDL_PollEvent(&events);
        switch(events.type){
            case SDL_QUIT:
                terminer = true;
                break;
        }
        SDL_RenderPresent(ecran);
    }
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    printf("camarche\n");
    return 0;
}