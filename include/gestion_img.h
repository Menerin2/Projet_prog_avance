#ifndef IMG
#define IMG

typedef struct s_bg{
    SDL_Texture* sprite;
    SDL_Rect src;
    SDL_Rect dst;
} bg_t;

typedef struct s_score{
    SDL_Texture* sprite;
    SDL_Rect* src;//0 will be 'hi' else will be numbers
    SDL_Rect* dst;
    int high;
    int current;
} score_t;

SDL_Texture* loadspritesdino(SDL_Renderer* renderer);
SDL_Rect* loadspritesplayerposition();
SDL_Rect* loadplayerposition();
SDL_Rect loadBgSrc();
bg_t** init_backgrounds(SDL_Renderer* renderer);
score_t* init_scores(SDL_Renderer* renderer);
SDL_Rect** loadgameoverpos();
#endif