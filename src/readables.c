#include "main.h"

rinfo_t** read_infos(){
    char* nom = "./ressource/info_sprite.txt";
    FILE* ptr = fopen(nom,"r");
    if(ptr == NULL){
        printf("cannot open file %s\n", nom);
        exit(0);
    }
    rinfo_t** nbr_lu = malloc(sizeof(rinfo_t*) * 8);
    for(int i = 0; i < 8; i++){
        nbr_lu[i] = (rinfo_t*)malloc(sizeof(rinfo_t));
        fscanf(ptr, "%d\t%d\t%d\t%d\n"
        , &nbr_lu[i]->h
        , &nbr_lu[i]->w
        , &nbr_lu[i]->x
        , &nbr_lu[i]->y);
    }
    fclose(ptr);
    return nbr_lu;
}

rinfo_t** read_infos_nbr(){
    char* nom = "./ressource/info_sprite.txt";
    FILE* ptr = fopen(nom, "r");
    fseek(ptr, 114, SEEK_SET);//start of letters pos in txt
    rinfo_t** nbr_lu = malloc(sizeof(rinfo_t*) * 18);
    for(int i = 0; i < 18; i++){
        nbr_lu[i] = (rinfo_t*)malloc(sizeof(rinfo_t));
        fscanf(ptr, "%d\t%d\t%d\t%d\n"
        , &nbr_lu[i]->h
        , &nbr_lu[i]->w
        , &nbr_lu[i]->x
        , &nbr_lu[i]->y);
    }
    fclose(ptr);
    return nbr_lu;
}

int read_highscore(){
    char* nom = "./ressource/score.txt";
    FILE* ptr = fopen(nom, "r");
    int i = 0;
    fscanf(ptr, "highscore: %d", &i);
    fclose(ptr);
    return i;
}

void write_highscore(int i){
    char* nom = "./ressource/score.txt";
    FILE* ptr = fopen(nom, "w");
    fprintf(ptr, "highscore: %d", i);
    fclose(ptr);
}

rinfo_t** read_info_gameover(){
    char* nom = "./ressource/info_sprite.txt";
    FILE* ptr = fopen(nom, "r");
    fseek(ptr, 399, SEEK_SET);
    rinfo_t** nbr_lu = malloc(sizeof(rinfo_t*) * 4);
    for(int i = 0; i < 4; i++){
        nbr_lu[i] = (rinfo_t*)malloc(sizeof(rinfo_t));
        fscanf(ptr, "%d\t%d\t%d\t%d\n"
        , &nbr_lu[i]->h
        , &nbr_lu[i]->w
        , &nbr_lu[i]->x
        , &nbr_lu[i]->y);
    }
    fclose(ptr);
    return nbr_lu;
}