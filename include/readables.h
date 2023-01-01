#ifndef READ
#define READ

typedef struct s_rinfo{
    /*infos a lire du txt*/
    int h;
    int w;
    int x;
    int y;
} rinfo_t;

rinfo_t** read_infos();

#endif