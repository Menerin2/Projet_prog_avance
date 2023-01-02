#include "main.h"

bool collisions(SDL_Rect A, SDL_Rect B){
    int leftA = A.x;
    int rightA = A.x + A.w;
    int topA = A.y;
    int botA = A.y + A.h;
    int leftB = B.x;
    int rightB = B.x + B.w;
    int topB = B.y;
    int botB = B.y + B.h;
    //mtnt pour le if de l'enfer
    if (botA <= topB ||
        topA >= botB ||
        rightA <= leftB ||
        leftA >= rightB){
            return true;
        }
    return false;
}

void move(armada_t* ennemies, score_t* score, bg_t** backg){
    link_t* temp = ennemies->first;
    while(temp != NULL){
        temp->dst.x -= 10 + (score->current / 10);
        temp = temp->next;
    }
    update_list(ennemies, score);
    for(int i = 0; i < 2; i++){
        backg[i]->dst.x -= 10 + (score->current / 10);
        if(backg[i]->dst.x <= -backg[i]->src.w){
            backg[i]->dst.x += 2 * (backg[i]->src.w);
        }
    }
}

int animation_player(player_t* player){
    player->frame++;
    int i;
    if(player->frame >= 10){player->frame = 0;}
    i = player->frame < 5 ? 2 : 3;
    if(player->in_movement != 0){
        i = player->in_movement == -1 ? 2 : 3;
    }
    if(player->crouch){
        i += 4;
    }
    return i; 
}

int animation_bird(ennemi_t* bird){
    if (!bird->fly){
        return 0;
    }
    bird->frame++;
    if(bird->frame >= 30){bird->frame = 0;}
    return bird->frame < 15 ? 0 : 1;

}

void render_score(SDL_Renderer* renderer, score_t* score){
    int temp = score->current;
    int un = temp % 10; temp /= 10;
    int dix = temp % 10; temp /= 10;
    int cent = temp % 10;
    SDL_RenderCopy(renderer, score->sprite, &score->src[cent], &score->dst[0]);
    SDL_RenderCopy(renderer, score->sprite, &score->src[dix], &score->dst[1]);
    SDL_RenderCopy(renderer, score->sprite, &score->src[un], &score->dst[2]);
    SDL_RenderCopy(renderer, score->sprite, &score->src[10], &score->dst[3]);
    if(score->current > score->high){
        SDL_RenderCopy(renderer, score->sprite, &score->src[cent], &score->dst[4]);
        SDL_RenderCopy(renderer, score->sprite, &score->src[dix], &score->dst[5]);
        SDL_RenderCopy(renderer, score->sprite, &score->src[un], &score->dst[6]);
    } else {
        temp = score->high;
        un = temp % 10; temp /= 10; dix = temp % 10; temp /= 10; cent = temp % 10;
        SDL_RenderCopy(renderer, score->sprite, &score->src[cent], &score->dst[4]);
        SDL_RenderCopy(renderer, score->sprite, &score->src[dix], &score->dst[5]);
        SDL_RenderCopy(renderer, score->sprite, &score->src[un], &score->dst[6]);
    }
}

void render_all(SDL_Renderer* renderer, player_t* player, armada_t* ennemies, bg_t** backg, score_t* score, int fin){
    int frame = animation_player(player);
    if(fin != 0){frame = fin; player->crouch = 0;}
    SDL_RenderCopy(renderer, player->sprite, &player->src_sprite[frame], &player->dst[player->crouch]);
    link_t* temp = ennemies->first;
    if(temp != NULL){
        for(int i = 0; i < 5 && temp != NULL; i++){ //n'affiche que ceux qui sont sucesptible d'apparaitre à l'écran
            frame = animation_bird(temp->guy);
            SDL_RenderCopy(renderer, temp->guy->sprite, &temp->guy->src[frame], &temp->dst);
            temp = temp->next;
        }
    }
    for(int i = 0; i < 2; i++){
        SDL_RenderCopy(renderer, backg[i]->sprite, &backg[i]->src, &backg[i]->dst);
    }
    render_score(renderer, score);
}

void render_retry(SDL_Renderer* renderer){
    SDL_Texture* sprite = loadspritesdino(renderer);
    SDL_Rect** pos = loadgameoverpos();
    SDL_RenderCopy(renderer, sprite, pos[0], pos[2]);
    SDL_RenderCopy(renderer, sprite, pos[1], pos[3]);
}

void render_end(SDL_Renderer* renderer, player_t* player, score_t* score){
    SDL_RenderCopy(renderer, player->sprite, &player->src_sprite[0], &player->dst[0]);
    render_score(renderer, score);
    render_retry(renderer);
}

void free_everything(player_t* player, armada_t* ennemies, bg_t** backg, score_t* score){
    free_player(player);
    free_background(backg);
    free_score(score);
    free_liste(ennemies);
}

void gameover(SDL_Renderer* renderer, player_t* player, armada_t* ennemies, bg_t** backg, score_t* score){
    for(int i = 0; i < 10; i++){
        SDL_RenderClear(renderer);
        render_all(renderer, player, ennemies, backg, score, ((i % 2) + 4));
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    SDL_RenderClear(renderer);
    render_end(renderer, player, score);
    SDL_RenderPresent(renderer);
    bool end = true;
    bool retry = false;
    while(end){
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                end = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        end = false;
                        retry = false;
                        break;
                    case SDLK_SPACE:
                        end = false;
                        retry = true;
                        break;
                }
                break;
        }
        SDL_Delay(100);
    }
    if(retry){
        /*free_liste(ennemies);
        armada_t* */ennemies = initialisation_ennemies(renderer);
        score->current = 0;
        main_loop(renderer, player, ennemies, backg, score);
    }
}

void main_loop(SDL_Renderer* renderer, player_t* player, armada_t* ennemies, bg_t** bg, score_t* score){
    bool end = true;
    while(end){
        SDL_RenderClear(renderer);
        SDL_Event event;
        SDL_PollEvent(&event);
        end = collisions(player->dst[player->crouch], ennemies->first->dst);
        switch(event.type){
            case SDL_QUIT:
                end = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                    end=false;
                    break;
                    case SDLK_SPACE:
                    if(player->in_movement == 0 && !player->crouch){
                        player->in_movement = -1;
                        player->speed = 10;}
                    break;
                    case SDLK_LSHIFT:
                    if(player->in_movement == 0){
                        player->crouch = 1;
                    }
                    break;
                }
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_LSHIFT){
                    player->crouch = 0;
                }
        }
        jump(player);
        move(ennemies, score, bg);
        render_all(renderer, player, ennemies, bg, score, !end);
        SDL_RenderPresent(renderer);
        SDL_Delay(40);
    }
    if(score->current > score->high){
        write_highscore(score->current);
    }
    gameover(renderer, player, ennemies, bg, score);
}

int main(){
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* fenetre;
    fenetre = SDL_CreateWindow("Pr Avancé", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 400, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(ecran, 255, 255, 255, 255);
    player_t* player = create_player(ecran);
    armada_t* ennemies = initialisation_ennemies(ecran);
    bg_t** background = init_backgrounds(ecran);
    score_t* score = init_scores(ecran);
    main_loop(ecran, player, ennemies, background, score);
    //free_everything(player,ennemies, background, score);
    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    IMG_Quit();
    return 0;
}