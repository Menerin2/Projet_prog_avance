#ifndef LIST
#define LIST

typedef struct s_link link_t;
struct s_link {
    ennemi_t* guy;
    SDL_Rect dst;
    link_t* next;
};

typedef struct s_armada {
    link_t* first;
}armada_t;

armada_t* initialisation_ennemies(SDL_Renderer* renderer);
void insert_first(armada_t* ennemies, ennemi_t* kind, SDL_Rect dst);
void update_list(armada_t* ennemies, score_t* score);
void delete_first(armada_t* ennemies);
void insert_last(armada_t* ennemies, link_t* last_link);

/* fonctions à faire
    armada_t* initialisation_ennemies(SDL_Renderer renderer);
    crée la list et crée le premier ennemi qui sera set à null
    ce premier ennemi restera à la fin car pendant toute la creation de la liste
    on rajoutera les nouveaux ennemis en première place.
    appelle ensuite (ou dans le main je sais pas encore) le insert all to fill everything
    
    void insert_first(armada_t* liste, ennemi_t ennemi);
    ici on crée un nouvel element, on lui met en 'next' le premier element de la liste
    et on met ce nouvel element au 'first'


    void insert_all(armada_t* liste);
    appelle la fonction insert_first à chaque nouvel ennemi que l'on veut rentrer
    (pas insert last ici pour eviter les parcours inutile si il y a bcp d'ennemies)
    + envoie la donnée correspondante (ennemi_t) depuis le create_ennemies de player.c
    une fois que tous sont initialisé, on parcours et leur assigne le bon link_t->dst pour la position à l'écran

    void delete_first(armada_t* liste);
    met liste->first->next dans liste->first et free l'ancien liste->first

    void delete_all(armada_t* liste);
    appelle delete_first jusqu'a ce que liste->first = null;

    ennemi_t return_first(armada_t* liste);
    renvoie le premier elément existant(non null)
    permet de récupérer les ennemies que l'on remettra à la fin de la liste pour boucler à l'infini jusqu'a une collision

    void insert_last(armada_t* liste, ennemi_t ennemi);
    ajoute ennemi en dernier element et lui donne null en next
    permet de boucler les ennemies que l'on a passé tout en recréant la stat dst de link_t
    pour les remettre à la bonne position à l'écran

*/

#endif