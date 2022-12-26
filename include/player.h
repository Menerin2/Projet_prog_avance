#ifndef PLAYER
#define PLAYER

struct s_player;
typedef struct s_player {
    /* data player */
    SDL_Texture* sprite;
    SDL_Rect* src_sprite;
    SDL_Rect dst;
    int in_movement;
} player_t;

//fonctions
player_t* create_player(SDL_Renderer* renderer);
void free_player(player_t*);
void jump(player_t* player);

#endif