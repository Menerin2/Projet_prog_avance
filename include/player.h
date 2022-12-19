#define PLAYER
#ifndef PLAYER

struct s_player;
typedef struct s_player {
    /* data player */
    int sizex;
    int sizey;
    char** states; 
} player_t;

//fonctions
void create_player(player_t* player);

#endif