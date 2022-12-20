#ifndef PLAYER
#define PLAYER

struct s_player;
typedef struct s_player {
    /* data player */
    int sizex;
    int sizey;
    SDL_Texture* sprite;
    SDL_Rect* src_sprite;
} player_t;

//fonctions
player_t* create_player(SDL_Renderer* renderer);

#endif