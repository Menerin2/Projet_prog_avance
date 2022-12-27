#include "main.h"

void move(armada_t* ennemies){
    link_t* temp = ennemies->first;
    while(temp != NULL){
        temp->dst.x -= 10;
        temp = temp->next;
    }
    update_list(ennemies);
}

void render_all(SDL_Renderer* renderer, player_t* player, armada_t* ennemies){
    SDL_RenderCopy(renderer, player->sprite, &player->src_sprite[0], &player->dst);
    link_t* temp = ennemies->first;
    if(temp != NULL){
        for(int i = 0; i < 4 && temp != NULL; i++){ //4 est just temp pour voir si les 4 premier ca suffit
            SDL_RenderCopy(renderer, temp->guy->sprite, &temp->guy->src, &temp->dst);
            temp = temp->next;
        }
    }
}

void main_loop(SDL_Renderer* renderer){
    player_t* player = create_player(renderer);
    armada_t* ennemies = initialisation_ennemies(renderer);
    bool end = true;
    while(end){
        SDL_RenderClear(renderer);
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
        jump(player);
        move(ennemies);
        //end = collisions(player, ennemies); = true si pas de collisions
        render_all(renderer, player, ennemies);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }
    free_player(player);
}

int main(){
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* fenetre;
    fenetre = SDL_CreateWindow("Pr Avancé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(ecran, 255, 255, 255, 255);
    main_loop(ecran);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    IMG_Quit();
    return 0;
}