#ifndef READ
#define READ

typedef struct s_rinfo{ //littéralement un sdl_rect renamed
    /*infos a lire du txt*/
    int h;
    int w;
    int x;
    int y;
} rinfo_t;

rinfo_t** read_infos();
rinfo_t** read_infos_nbr();
int read_highscore();
void write_highscore(int i);

#endif