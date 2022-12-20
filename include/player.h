#ifndef PLAYER
#define PLAYER

struct s_player;
typedef struct s_player {
    /* data player */
    int sizex;
    int sizey;
    char** states; 
} player_t;

//fonctions
player_t* create_player();

#endif