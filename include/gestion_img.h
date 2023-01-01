#ifndef IMG
#define IMG

typedef struct s_bg{
    SDL_Texture* sprite;
    SDL_Rect src;
    SDL_Rect dst;
} bg_t;

SDL_Texture* loadspritesdino(SDL_Renderer* renderer);
SDL_Rect* loadspritesplayerposition();
SDL_Rect* loadplayerposition();
SDL_Rect loadBgSrc();
bg_t** init_backgrounds(SDL_Renderer* renderer);
#endif