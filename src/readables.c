#include "main.h"

rinfo_t** read_infos(){
    char* nom = "./ressource/info_sprite.txt";
    FILE* ptr = fopen(nom,"r");
    if(ptr == NULL){
        printf("cannot open file %s\n", nom);
        exit(0);
    }
    rinfo_t** nbr_lu = malloc(sizeof(rinfo_t*)*6);
    for(int i = 0; i < 6; i++){
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