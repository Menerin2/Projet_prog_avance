#ifndef PLAYER
#define PLAYER

typedef struct s_player {
    /* data player */
    SDL_Texture* sprite;
    SDL_Rect* src_sprite;
    SDL_Rect dst;
    int in_movement;
    double speed;
} player_t;

typedef struct s_ennemi {
    /*data single ennemi*/
    SDL_Texture* sprite;
    SDL_Rect src;
}ennemi_t;


//fonctions
player_t* create_player(SDL_Renderer* renderer);
void free_player(player_t*);
void jump(player_t* player);
ennemi_t** create_ennemies(SDL_Renderer* renderer);

#endif